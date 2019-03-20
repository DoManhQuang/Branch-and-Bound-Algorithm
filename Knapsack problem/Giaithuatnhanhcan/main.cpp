#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DoVat
{
private:
    string tenDV;
    int soLuong;
    int trongLuong;
    int giaTien;
public:
    DoVat()
    {

    }
    DoVat(string ten, int sl, int tl, int gt)
    {
        tenDV = ten;
        soLuong = sl;
        trongLuong = tl;
        giaTien = gt;
    }
    void NhapDV()
    {
        cin>>tenDV;
        cin>>soLuong;
        cin>>trongLuong;
        cin>>giaTien;
    }
    void HienDV()
    {
        cout<<"\t"<<setw(4)<<tenDV<<setw(18)<<soLuong<<setw(19)<<trongLuong<<setw(22)<<giaTien;
    }
    string getTenDV()
    {
        return tenDV;
    }
    int getGiaTien()
    {
        return giaTien;
    }
    int getSoLuong()
    {
        return soLuong;
    }
    int getTrongLuong()
    {
        return trongLuong;
    }
    void setGiaTien(int gt)
    {
        giaTien = gt;
    }
    void setTrongLuong(int tl)
    {
        trongLuong = tl;
    }
    void setSoLuong(int sl)
    {
        soLuong = sl;
    }
    void setTenDV(string ten)
    {
        tenDV = ten;
    }
};
int ndv;
int tlMax; /// trọng lượng max
DoVat *dv;
void NhapDuLieu()
{
    freopen("data.txt","r",stdin);
    cin>>ndv;
    cin>>tlMax;
    dv = new DoVat[ndv];
    for(int i=0; i<ndv; i++)
    {
        dv[i].NhapDV();
    }
}
void XuatDuLieuDV()
{
    cout<<endl<<setw(4)<<"\tTen DV"<<setw(20)<<"So Luong"<<setw(20)<<"Trong Luong"<<setw(20)<<"Gia Tien\n";
    for(int i=0; i<ndv; i++)
    {
        dv[i].HienDV();
        cout<<endl;
    }
}
int n = 4;
int *gt; /// Giá trị của đồ vật
int *tl; /// trọng lượng của đồ vật
int *sl; /// số lượng của đồ vật
void NhapDL()
{
    gt = new int [n]; /// mảng giá trị
    tl = new int [n]; /// mảng trọng lượng
    sl = new int [n]; /// mảng số lượng
    for(int i=0; i<n; i++)
    {
        gt[i] = dv[i].getGiaTien();
    }
    for(int i=0; i<n; i++)
    {
        tl[i] = dv[i].getTrongLuong();
    }
    for(int i=0; i<n; i++)
    {
        sl[i] = dv[i].getSoLuong();
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
void HienThiSLDV()
{
    cout<<"\nSo Luong hang: \n\n\t   ";
    for(int i=0; i<n; i++)
    {
        cout<<sl[i]<<setw(9);
    }
}

void SapXepdulieu()
{
    for(int i=0; i<n-1; i++)
    {
        int ma = i;
        for(int j=i+1; j<n; j++)
        {
            float gt_tl_i = (float)gt[ma]/tl[ma]; /// c(i) / a(i)
            float gt_tl_i1 = (float)gt[j]/tl[j];/// c(i+1)/a(i+1)
            if(gt_tl_i < gt_tl_i1)
            {
                ma = j;
            }
        }
        if(ma != i )
        {
            /// sắp xếp 3 mảng cùng 1 lúc
            swap(gt[i],gt[ma]);
            swap(tl[i],tl[ma]);
            swap(sl[i],sl[ma]);
        }
    }
}

int *x;
int count_x = 0;
void XuLyThuatToan()
{
    int i = 0;
    float trongLuong = 0; /// trọng lượng túi : w
    float triGiatui = 0; /// giá trị của túi : nuy
    int soNhanh = 0; /// số nhánh của cây
    float gMax = 0; /// giá trị gMax
    x = new int [n]; /// mảng nghiệm của pt
    while(i != n)
    {
        if(i==0) /// lần đầu tiên
        {
            /// tính số nhánh cây
            soNhanh = tlMax/tl[i];
            if(soNhanh > sl[i])
            {
                soNhanh = sl[i];
            }
            float MangSN[10]; /// mảng số nhánh;
            int count_SN = 1;
            for(int j=0; j<soNhanh+1; j++)
            {
                /// xử lý tính toán từng giá trị của nhánh
                triGiatui = (float)gt[i]*j;
                trongLuong = (float)tlMax - (float)tl[i]*j;
                gMax = triGiatui + (float)trongLuong * gt[1]/tl[1];
                MangSN[j] = gMax;
                count_SN++;
            }
            /// xử lý chọn nhánh tốt nhất
            float Max = MangSN[0];
            int vtMa = 0; /// là giá trị của nhánh , vị trị max ứng với số nhánh.
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
            sl[i] = sl[i] - vtMa;
            x[count_x] = vtMa;
            count_x++;
        }
        else if(sl[i] > 0) /// các lần tiếp theo
        {
            soNhanh = trongLuong/tl[i];
            if(soNhanh > sl[i])
            {
                soNhanh = sl[i];
            }
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
            int vtMa = 0; /// là giá trị của nhánh , vị trị max ứng với số nhánh.
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
            sl[i] = sl[i] - vtMa;
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
    cout << "\tCoding by Manh Quang" << endl;
    cout<<"Du Lieu Bang : "<<endl;
    NhapDuLieu();
    XuatDuLieuDV();
    cout<<endl;
    NhapDL();
    cout<<"Du Lieu PT : "<<endl<<endl;
    HienThiPTGT();
    HienThiPTTL();
    HienThiSLDV();
    cout<<endl;
    SapXepdulieu();
    cout<<"Du Lieu PT Sau Khi Sap Xep : "<<endl<<endl;
    HienThiPTGT();
    HienThiPTTL();
    HienThiSLDV();
    cout<<endl;
    XuLyThuatToan();
    cout<<"Nghiem cua bai toan la : "<<endl<<endl;
    HienThiNghiemX();
    XuLyFmax();
    return 0;
}
