#include <iostream>
using namespace std;
ifstream fin1("matrice.txt");
ifstream fin2("matrice2.txt");
ifstream fin3("matrice3.txt");
////////////<<<MATRICE>>>//////////
matrice::matrice(int x, int y)//int x, int y
{
    n=x;
    m=y;
    matrix=new numar_complex*[n];
    for(int i=0; i<n; i++)
        *(matrix+i)=new numar_complex[m];
    //cout<<"construct matrice"<<endl;
}
matrice::matrice(const matrice &m2)
{
    n=m2.n;
    m=m2.m;
    matrix=new numar_complex*[n];
    for(int i=0; i<n; i++)
        *(matrix+i)=new numar_complex[m];
    //cout<<"construct matrice"<<endl;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            matrix[i][j]=m2.matrix[i][j];
}
//destructori
matrice::~matrice()
{
    for(int i=n-1; i>=0; i--)
        delete [] matrix[i];
    delete [] matrix;

    //cout<<"destruct matrice"<<endl;
}

matrice matrice::operator=(const matrice m2)
{
    n=m2.n;
    m=m2.m;
    matrix=new numar_complex*[n];
    for(int i=0; i<n; i++)
        *(matrix+i)=new numar_complex[m];
    //cout<<"construct matrice"<<endl;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            matrix[i][j]=m2.matrix[i][j];
    return *this;
}
matrice matrice::operator+(const matrice m2)
{
    if(n==m2.n && m==m2.m)
    {
        matrice temp;
        temp.n=n;
        temp.m=m;
        temp.matrix=new numar_complex*[temp.n];
        for(int i=0; i<temp.n; i++)
            *(temp.matrix+i)=new numar_complex[temp.m];
        //cout<<"construct matrice"<<endl;

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                temp.matrix[i][j]=matrix[i][j]+m2.matrix[i][j];
        return temp;
    }
    else
    {
        cout<<"Suma a doua matrici cu dimensiuni diferite nu poate fi efectuata!"<<endl;
        return *this;
    }
}
matrice matrice::operator*(const matrice m2)
{
    matrice temp;
    temp.n=n;
    cout<<"temp.n="<<temp.n<<endl;
    temp.m=m2.m;
    cout<<"temp.m="<<temp.m<<endl;
    numar_complex aux;
    temp.matrix=new numar_complex*[temp.n];
    for(int i=0; i<temp.n; i++)
        *(temp.matrix+i)=new numar_complex[temp.m];
    if(temp.n != temp.m)
    {
        cout<<"Produsul nu poate fi calculat!"<<endl;
        cout<<"Temp return NULL"<<endl;
        temp.show_matrice();
        return temp;
    }

    for(int i=0; i<temp.n; i++)
        for(int j=0; j<temp.m; j++)
        {

            for(int k=0; k<m; k++)
            {
                //cout<<endl<<"i j k "<<i<<' '<<j<<' '<<k<<endl;
                //cout<<endl<<"matrix["<<i<<"]["<<k<<"]= "<<matrix[i][k].get_a_nr_complex()<<' '<<matrix[i][k].get_b_nr_complex()<<' '<<matrix[i][k].get_i_nr_complex()<<endl;
                //cout<<"m2.matrix["<<k<<"]["<<j<<"]= "<<m2.matrix[k][j].get_a_nr_complex()<<' '<<m2.matrix[k][j].get_b_nr_complex()<<' '<<m2.matrix[k][j].get_i_nr_complex()<<endl;
                //cout<<endl<<"aux=matrix["<<i<<"]["<<k<<"]= "<<aux.get_a_nr_complex()<<' '<<aux.get_b_nr_complex()<<' '<<aux.get_i_nr_complex()<<endl;
                aux=matrix[i][k]*m2.matrix[k][j];
                //cout<<"aux=aux*m2.matrix["<<k<<"]["<<j<<"]= "<<aux.get_a_nr_complex()<<' '<<aux.get_b_nr_complex()<<' '<<aux.get_i_nr_complex()<<endl;
                temp.matrix[i][j]=temp.matrix[i][j]+aux;
                //cout<<"temp.matrix["<<i<<"]["<<j<<"]+aux= "<<temp.matrix[i][j].get_a_nr_complex()<<' '<<temp.matrix[i][j].get_b_nr_complex()<<' '<<temp.matrix[i][j].get_i_nr_complex()<<endl;
            }
            //cout<<endl<<">>>>>>>>>>>>>>>>FINALtemp.matrix["<<i<<"]["<<j<<"]= "<<temp.matrix[i][j].get_a_nr_complex()<<' '<<temp.matrix[i][j].get_b_nr_complex()<<' '<<temp.matrix[i][j].get_i_nr_complex()<<endl;
        }
    return temp;
}
//setare matrice
void matrice::set_matrice()
{
    int a, b, c;
    cout<<endl<<"Introduceti n=";
    cin>>n;
    cout<<"Introduceti m=";
    cin>>m;
    //matrice(n); aloc matrice dinamic de n dimensiuni
    matrix=new numar_complex*[n];
    for(int i=0; i<n; i++)
        *(matrix+i)=new numar_complex[m];
    cout<<"construct matrice"<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<"Introduceti nr de pe linia "<<i+1<<" si coloana "<<j+1<<" (de forma a b i)"<<endl;
            cin>>a>>b>>c;
            matrix[i][j].set_nr_complex(a,b,c);
        }
    }
}
//istream& operator>>( istream& input, matrice& m)
//{
//    return input;
//}
void matrice::set_matrice_txt1()
{
    int a, b, c;
    cout<<"Citim pe n=";
    fin1>>n;
    cout<<n<<endl;
    cout<<"Citim pe m=";
    fin1>>m;
    cout<<m<<endl;
    //matrice(n); aloc matrice dinamic de n dimensiuni
    matrix=new numar_complex*[n];
    for(int i=0; i<n; i++)
        *(matrix+i)=new numar_complex[m];
    cout<<"construct matrice"<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<"Citesc nr de pe linia "<<i+1<<" si coloana "<<j+1<<" (de forma a b i): ";
            fin1>>a>>b>>c;
            cout<<a<<' '<<b<<' '<<c<<endl;
            matrix[i][j].set_nr_complex(a,b,c);
        }
    }
    cout<<endl;
    fin1.close();
}
void matrice::set_matrice_txt2()
{
    int a, b, c;
    cout<<"Citim pe n=";
    fin2>>n;
    cout<<n<<endl;
    cout<<"Citim pe m=";
    fin2>>m;
    cout<<m<<endl;
    //matrice(n); aloc matrice dinamic de n dimensiuni
    matrix=new numar_complex*[n];
    for(int i=0; i<n; i++)
        *(matrix+i)=new numar_complex[m];
    cout<<"construct matrice"<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<"Citesc nr de pe linia "<<i+1<<" si coloana "<<j+1<<" (de forma a b i): ";
            fin2>>a>>b>>c;
            cout<<a<<' '<<b<<' '<<c<<endl;
            matrix[i][j].set_nr_complex(a,b,c);
        }
    }
    cout<<endl;
    fin2.close();
}
void matrice::set_matrice_txt3()
{
    int a, b, c;
    cout<<"Citim pe n=";
    fin3>>n;
    cout<<n<<endl;
    cout<<"Citim pe m=";
    fin3>>m;
    cout<<m<<endl;
    //matrice(n); aloc matrice dinamic de n dimensiuni
    matrix=new numar_complex*[n];
    for(int i=0; i<n; i++)
        *(matrix+i)=new numar_complex[m];
    cout<<"construct matrice"<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<"Citesc nr de pe linia "<<i+1<<" si coloana "<<j+1<<" (de forma a b i): ";
            fin3>>a>>b>>c;
            cout<<a<<' '<<b<<' '<<c<<endl;
            matrix[i][j].set_nr_complex(a,b,c);
        }
    }
    cout<<endl;
    fin3.close();
}
void matrice::show_matrice()
{
    cout<<"|";
    for(int sp=1; sp<m*8; sp++)
    {
        int q=0;
        if((sp+q)%8==0) {cout<<"|"; q++;}
        else cout<<"-";
    }
    cout<<"|";
    cout<<endl;//linia 1
    for(int i=0; i<n; i++)
    {
        cout<<"|";
        for(int sp=1; sp<m*8; sp++)
        {
            int q=0;
            if((sp+q)%8==0) {cout<<"|"; q++;}
            else cout<<" ";
        }
        cout<<"|";
        cout<<endl;//linia2

        cout<<"|";
        for(int j=0; j<m; j++)
            cout<<' '<<matrix[i][j].get_a_nr_complex()<<' '<<matrix[i][j].get_b_nr_complex()<<' '<<matrix[i][j].get_i_nr_complex()<<" |";
        cout<<endl;

        cout<<"|";
        for(int sp=1; sp<m*8; sp++)
        {
            int q=0;
            if((sp+q)%8==0) {cout<<"|"; q++;}
            else cout<<" ";
        }
        cout<<"|"; //linia 3

        cout<<endl;
        cout<<"|";
        for(int sp=1; sp<m*8; sp++)
        {
            int q=0;
            if((sp+q)%8==0) {cout<<"|"; q++;}
            else cout<<"-";
        }
        cout<<"|";
        cout<<endl;
    }
}
