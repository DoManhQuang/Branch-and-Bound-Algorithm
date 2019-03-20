#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int n;/// so pt cua 2 mang gt va tl
int tlMax;
int *gt;
int *tl;
void NhapDL()
{
    freopen("data.txt","r",stdin);
    cin>>n;
    cin>>tlMax;
    gt = new int [n];
    tl = new int [n];
    for(int i=0; i<n; i++)
    {
        cin>>gt[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>tl[i];
    }
}
void HienThiPTGT()
{
    cout<<"\t";
    for(int i=0; i<n-1; i++)
    {
        cout<<setw(3)<<gt[i]<<" X"<<i<<setw(3)<<" + ";
    }
    cout<<setw(3)<<gt[n-1]<<" X"<<n-1<<setw(2)<<" -> Max"<<endl;
}
void HienThiPTTL()
{
    cout<<"\t";
    for(int i=0; i<n-1; i++)
    {
        cout<<setw(3)<<tl[i]<<" X"<<i<<setw(3)<<" + ";
    }
    cout<<setw(3)<<tl[n-1]<<" X"<<n-1<<setw(3)<<" <= "<<tlMax<<endl;
}
void SapXepdulieu()
{
    for(int i=0; i<n-1; i++)
    {
        int ma = i;
        for(int j=i+1; j<n; j++)
        {
            float gt_tl_i = (float)gt[ma]/tl[ma]; /// ci / ai
            float gt_tl_i1 = (float)gt[j]/tl[j];/// ci+1/ai+1
            if(gt_tl_i < gt_tl_i1)
            {
                ma = j;
            }
        }
        if(ma != i )
        {
            swap(gt[i],gt[ma]);
            swap(tl[i],tl[ma]);
        }
    }
}
int *x;
int count_x = 0;
void XuLyThuatToan()
{
    int i = 0;
    float trongLuong = 0; /// Bk : w
    float triGiatui = 0; /// niu
    int soNhanh = 0;
    float gMax = 0; ///g
    x = new int [n];
    while(i != n)
    {
        if(i==0)
        {
            soNhanh = tlMax/tl[i];
            float MangSN[10]; /// mảng số nhánh;
            int count_SN = 1;
            for(int j=0; j<soNhanh+1; j++)
            {
                triGiatui = (float)gt[i]*j;
                trongLuong = (float)tlMax - (float)tl[i]*j;
                gMax = triGiatui + (float)trongLuong * gt[1]/tl[1];
                MangSN[j] = gMax;
                count_SN++;
            }
            float Max = MangSN[0];
            int vtMa = 0;
            for(int j=0; j<count_SN-1; j++)
            {
                if(MangSN[j] > Max)
                {
                    Max = MangSN[j];
                    vtMa = j;

                }
            }
            triGiatui = (float)gt[i]*vtMa;
            trongLuong = (float)tlMax - (float)tl[i]*vtMa;
            gMax = triGiatui + (float)trongLuong * gt[vtMa]/tl[vtMa];
            x[count_x] = vtMa;
            count_x++;
        }
        else
        {
            soNhanh = trongLuong/tl[i];
            float MangSN[10]; /// mảng số nhánh;
            int count_SN = 1;
            for(int j = 0;j<soNhanh+1;j++)
            {
                triGiatui = triGiatui + (float)gt[i]*j;
                trongLuong = trongLuong - (float)tl[i]*j;
                gMax = triGiatui + (float)trongLuong * gt[i+1]/tl[i+1];
                MangSN[j] = gMax;
                count_SN++;
            }
            float Max = MangSN[0];
            int vtMa = 0;
            for(int j=0; j<count_SN-1; j++)
            {
                if(MangSN[j] > Max)
                {
                    Max = MangSN[j];
                    vtMa = j;

                }
            }

            triGiatui = (float)gt[i]*vtMa;
            trongLuong = (float)trongLuong - (float)tl[i]*vtMa;
            gMax = triGiatui + (float)trongLuong * gt[vtMa]/tl[vtMa];
            x[count_x] = vtMa;
            count_x++;
        }
        i++;
    }
}
void XuLyFmax()
{
    int Fmax = 0;
    for(int i=0;i<count_x;i++)
    {
        Fmax = Fmax + gt[i]*x[i];
    }
    cout<<"\t Fmax = "<<Fmax<<endl;
}
void HienThiNghiemX()
{
    cout<<"\t X = [";
    for(int i=0;i<count_x;i++)
    {
        cout<<setw(3)<<x[i];
    }
    cout<<setw(3)<<"]"<<endl;
}

int main()
{
    cout << "\tCoding By Manh Quang" << endl<<endl;
    NhapDL();
    cout<<"Du Lieu PT : "<<endl<<endl;
    HienThiPTGT();
    HienThiPTTL();
    cout<<endl;
    SapXepdulieu();
    cout<<"Du Lieu PT Sau Khi Sap Xep : "<<endl<<endl;
    HienThiPTGT();
    HienThiPTTL();
    cout<<endl;
    XuLyThuatToan();
    cout<<"Nghiem cua bai toan la : "<<endl<<endl;
    HienThiNghiemX();
    XuLyFmax();


    return 0;
}
