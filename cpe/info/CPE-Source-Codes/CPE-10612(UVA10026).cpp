#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Job{
   public:
   int m_id,m_day,m_money;
   Job (){m_id=m_day=m_money=0;}
   bool operator<(const Job& b)const{
      if(m_day*b.m_money==m_money*b.m_day)
         return m_id<b.m_id;
      return (m_day*b.m_money)<(m_money*b.m_day);
   }
};
int main(){
   int n;cin>>n;
   for(int i=0;i<n;i++){
      if(i)cout<<endl;
      int n;cin>>n;vector<Job> jobs(n);
      for(int i=0;i<n;i++){
         cin>>jobs[i].m_day>>jobs[i].m_money;
         jobs[i].m_id=i+1;
      }
      sort(jobs.begin(),jobs.end());
      for(int i=0;i<n;i++){
         if(i)cout<<" ";
         cout<<jobs[i].m_id;
      }
      cout<<endl;
   }	
   return 0;
}
