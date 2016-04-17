#include "Anchor.h"

using namespace std;
template<int k>
AnchorVertex<k>::~AnchorVertex()
{
for (auto x : AncPts)
	{
		x.clear();
	}

}

template<int k>
void AnchorVertex<k>::Initialize(const Shell &s, const LloydCluster<k> &MC)
{
shl = &s; MyCl = &MC;
}

template<int k>
void AnchorVertex<k>::MakeAnchorVertex()
{

for(auto vt : shl->AllVertex())
{
	auto Poly = shl->GetVertexPolygon(vt);
	int count = 0;
	std::vector<int> temp;
	for(auto py : Poly)
	{
		int label = MyCl->GetLabelForPolygon(py);
		if(count==0)
		{
			temp.push_back(label);
			count++;
			
		}else
		{
			int flag = 0; //0: mean same label not present 1: means label already exists
			for(auto &t : temp)
			{
				if(label==t)
				{
					flag = 1;
					break;
				}
				
			}
			
			if(flag==0)
			{	
				temp.push_back(label);
				count++;
			}
		}
		
	
	}
	
	if(temp.size()>=3)
	{
		AncVtx AV;
		AV.Anchor = shl->GetVertexPosition(vt);
        AV.Ptr = vt;
		for(int i=0;i<temp.size();i++)
		{
			AV.label[i] = temp[i];
		}
		AncPts.push_back(AV);
		
	}

}

}


template<int k>
void AnchorVertex<k>::FindAverageAnchorVertex()
{
    for(int i=0;i<AncPts.size();i++)
    {
        Vec3 temp(0.,0.,0.);
        for(int j=0;j<AncPts[i].label.size();j++)
        {
            auto Proxy = MyCl->GetProxy(AncPts[i].label[j]);
            temp = temp + GetProjection(Proxy.ProxyPosition, Proxy.ProxyNormal, AncPts[i].Anchor);
        }
        
        temp = temp/AncPts[i].label.size();
        
        AncPts[i].Anchor = temp;
    }
}


template<int k>
void AnchorVertex<k>::BinAnchorVertex()//Bins all the anchors into their respective proxies
{

int nProxy = MyCl->GetNumProxy();//Get number of proxies

    PrxyAnc.resize(nProxy);
//PrxyAnc = new AncVtxHandle[nProxy];//dynamic memory allocation

	for(auto &t : AncPts)
	{

		for(auto &u : t.label)
		{
            
			PrxyAnc[u].push_back(t);
		}
        
	}

}

template<int k>
AncVtxHandle AnchorVertex<k>::GetAnchorVtx(int ProxyNum)//ProxyNum : 0 to k-1 Returns all the anchor vertices associated with given proxy
{

//	if(EdgVtx!=nullptr)
        return PrxyAnc[ProxyNum];

}

template<int k>
AncVtxHandle AnchorVertex<k>::GetNeighbourAnc(AncVtx VtxHd, AncVtxHandle PxHd)//can change to AncVtx on the return type
{
	AncVtxHandle Neighbour;
    
    for(int i=0;i<PxHd.size();i++)
    {
        for(int j=0;j<VtxHd.label.size();j++)
        {
    
            for(int m=0;m<PxHd[i].label.size();m++)
            {
                if(VtxHd.label[j]==PxHd[i].label[m])
                {
                    Neighbour.push_back(PxHd[i]);
                }
            
            
            }
        }
    }
	
//	for(int i=0;i<2&&i<PxHd.size();i++)
//	{	
//		double minD = 10^6;//Need something better. Does inf work?
//		AncVtx temp;
//		
//		for(int j=0;j<PxHd.size();j++)
//		{
//			double d = L2Norm(VtxHd.Anchor-PxHd[j].Anchor);
//			if(d<minD && d!=0)
//			{
//				minD = d;
//				temp.Anchor = PxHd[j].Anchor;
//				temp.label.swap(PxHd[j].label);
//				
//			}
//		}
//		Neighbour.push_back(temp);
//		
//		for(int j=0;j<PxHd.size();j++)
//		{
//			if(PxHd[j].Anchor==temp.Anchor)
//			{	
//				PxHd.erase(PxHd.begin()+j);
//				break;
//			}
//		}
//
//	}
//	
	return Neighbour;
}

template<int k>
void AnchorVertex<k>::AssignLabel()//assign label to each vertex of every polygon in a given proxy
{
	for(int i=0;i<k;i++)
	{	
		auto cluster = MyCl->GetCluster(i);
		std::vector<PxyVtx> bin;
		for(auto &PlHd : cluster)
		{
			auto PlVtx = PlHd->GetVertex();
			for(auto &VtHd :PlVtx)
			{
				PxyVtx V;
				V.label1 = i;
				V.Anchor = VtHd;
				bin.push_back(V);
				
			}
		} 
		
		Vtxlst.push_back(bin);
	}


}

template<int k>
std::vector<PxyVtx> AnchorVertex<k>::GetEdgeVertices(AncVtx vtx1, AncVtx vtx2, int ClusterNum)
{
	int commlabel[2],l=0;
	std::vector<PxyVtx> EdgVtx; 
	for(int i=0;i<vtx1.label.size();i++)
	{
		for(int j=0;j<vtx2.label.size();j++)
		{
			if(vtx1.label[i]==vtx2.label[j])
			{	
				
                commlabel[l]=vtx1.label[i];
				l=l+1;
			}
            
		}
        
        if(l>1)
        {
            break;
        }
		
	}

	auto cluster1 = Vtxlst[commlabel[0]];
	auto cluster2 = Vtxlst(commlabel[1]);
	
	for(int i=0;i<cluster1.size();i++)
	{
		auto temp = cluster1[i];
		for(int j=0;j<cluster2.size();j++)
		{
			if(temp.Anchor==cluster2[j].Anchor)
			{	
				if(temp.label1==commlabel[0])
                {
                    temp.label2 = commlabel[1];
                    EdgVtx.push_back(temp);
                }else
                {
                    temp.label2 = commlabel[0];
                    EdgVtx.push_back(temp);
                    
                }
                
               
			}
			
		}
	}
    
    return EdgVtx;

}

template<int k>
void AnchorVertex<k>::AddAncVtx(AncVtx vtx1, AncVtx vtx2, std::vector<PxyVtx> EdgeVtx, int ClusterNum)
{
	AncVtxHandle newAnchors;
	auto pxy1 = MyCl->GetProxy[EdgeVtx[0].label1];
	auto pxy2 = MyCl->GetProxy[EdgeVtx[0].label2];
	double N1 = L2Norm(pxy1.ProxyNormal), N2 = L2Norm(pxy2.ProxyNormal);
    double maxD = 0.0;
    AncVtx t;
	for	(int i=0;i<EdgeVtx.size();i++)
	{
        double D = fabs(sin(N1/N2)*DistancePtToLine(vtx1.Anchor, vtx2.Anchor, shl->GetVertexPosition(EdgeVtx[i].Anchor))*L2Norm(vtx1.Anchor-vtx2.Anchor));
		if(D>maxD)
		{
            maxD = D;
			t.Anchor = shl->GetVertexPosition(EdgeVtx[i].Anchor);
			t.label.push_back(EdgeVtx[i].label1);
			t.label.push_back(EdgeVtx[i].label2);
            t.Ptr = EdgeVtx[i].Anchor;
        }
	}
    
    if(maxD>threshold&&maxD!=0)
    {
        PrxyAnc[t.label[0]].push_back(t);
        PrxyAnc[t.label[1]].push_back(t);
        AddAncVtx(vtx1, t, GetEdgeVertices(vtx1, t, ClusterNum), ClusterNum);
        AddAncVtx(t, vtx2, GetEdgeVertices(t, vtx2, ClusterNum), ClusterNum);

    }
	
}

template<int k>
void AnchorVertex<k>::ExtractEdges(int ClusterNum)
{
    
    AncVtxHandle todo;
	todo.swap(PrxyAnc[ClusterNum]);//Check ProxyAnc after swapping
	
	auto t = todo.back();
	todo.pop_back();
	
	while(todo.size()!=0)
	{
		auto nextHd =  GetNeighbourAnc(t, todo);
        
        if(nextHd.size()!=0)
        {
            if(nextHd.size()==2)
            {
                auto next = nextHd.back();
               
                nextHd.pop_back();
                auto EgdeVtx1 = GetEdgeVertices(t, next, ClusterNum);
                AddAncVtx(t,next,EgdeVtx1,ClusterNum);
                
                auto prev = nextHd.back();
                auto EgdeVtx2 = GetEdgeVertices(t, prev, ClusterNum);
                AddAncVtx(t,prev,EgdeVtx2,ClusterNum);
                
                
            }else if(nextHd.size()==1)
            {
                auto next = nextHd.back();
                
                nextHd.pop_back();
                auto EgdeVtx1 = GetEdgeVertices(t, next, ClusterNum);
                AddAncVtx(t,next,EgdeVtx1,ClusterNum);
                
            }
            
        }
		
		t = todo.back();
		todo.pop_back();
		
	}
	
}