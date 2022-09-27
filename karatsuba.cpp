#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<stdlib.h>
#include <bits/stdc++.h>
#include<string.h>
#include<math.h>
using namespace std;
int makeEqualLength(string &str1, string &str2)
{
     int len1 = str1.size();
     int len2 = str2.size();
     if (len1 < len2)
        {
             for (int i = 0 ; i < len2 - len1 ; i++)
             str1 = '0' + str1;
     return len2;
 }
  else if (len1 > len2)
    {
         for (int i = 0 ; i < len1 - len2 ; i++)
         str2 = '0' + str2;
 }
 return len1;
}
string addBitStrings( string first, string second )
{
     string result;
 int length = makeEqualLength(first, second);
 int carry = 0;
 for (int i = length-1 ; i >= 0 ; i--)
 {
      int firstBit = first.at(i) - '0';
 int secondBit = second.at(i) - '0';
 int sum = (firstBit ^ secondBit ^ carry)+'0';
 result = (char)sum + result;
 carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
 }
 if (carry) result = '1' + result;
 return result;
}
int multiplyiSingleBit(string a, string b)
{
    return (a[0] - '0')*(b[0] - '0'); }
long int multiply(string X, string Y)
{
    int n = makeEqualLength(X, Y);
 if (n == 0) return 0;
 if (n == 1) return multiplyiSingleBit(X, Y);
 int fh = n/2;
 int sh = (n-fh);
 string Xl = X.substr(0, fh);
 string Xr = X.substr(fh, sh);
 string Yl = Y.substr(0, fh);
 string Yr = Y.substr(fh, sh);
 long int P1 = multiply(Xl, Yl);
 long int P2 = multiply(Xr, Yr);
 long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));
 return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2;
}
int decToBin(int n)
{
     long binary=0,pow=1;
 while(n>0){
 int lastbit=n%2;
 binary+=lastbit*pow;
 pow*=10;
 n/=2;
 }
 return binary;
}
long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();
int prime(long int pr)
{
     int i;
 j = sqrt(pr);
 for (i = 2; i <= j; i++)
 {
 if (pr % i == 0)
 return 0;
 }
 return 1;
}
int swe(int t, string e, int m){
    int c,pad=0,i,j,timm[4]={t%m,(t*t*t)%m,(t*t*t*t*t)%m,(t*t*t*t*t*t*t)%m};
    int nonzero_partition_index[99][2];
    for( j=0,i=e.size()-1;i>=0;i--){
            if(e[i]=='1')
                {
                nonzero_partition_index[j++][0]=i;
    i-=2;
if(i==-2) {e="00"+e;pad=2;i+=2;}
if(i==-1) {e="0"+e;pad=2;i+=1;}
if(e[i]=='0')
if(e[i+1]=='0')
    nonzero_partition_index[j-1][1]=0;
else
nonzero_partition_index[j-1][1]=1;
if(e[i]=='1')

if(e[i+1]=='0')

nonzero_partition_index[j-1][1]=2;
else
nonzero_partition_index[j-1][1]=3;
}
}
j--;
c=timm[nonzero_partition_index[j--][1]];
for(i=3;i<e.size();i+=3){
    while((i+2)!=(nonzero_partition_index[j][0]+pad)){
        c= (c*c) %m;
        i++;
if(i==e.size())
 return c;
}
c=(c*c)%m;
c=(c*c)%m;
c=(c*c)%m;
c=(c*timm[nonzero_partition_index[j--][1]])%m;
}
return c;
}
int main()
{
 cout << "\nENTER FIRST PRIME NUMBER\n";
 cin >> p;
 flag = prime(p);
 if (flag == 0)
 {
      cout << "\nWRONG INPUT\n";
 exit(1);
 }
 int p1=decToBin(p);
 int p2=decToBin(p-1);
 stringstream str01;
 str01<<p1;
 string str1=str01.str();
 stringstream str03;
 str03<<p2;
 string str3=str03.str();

 cout << "\nENTER ANOTHER PRIME NUMBER\n";
 cin >> q;
 flag = prime(q);
 if (flag == 0 || p == q)
 {
 cout << "\nWRONG INPUT\n";
 exit(1);
 }
 int q1=decToBin(q);
 int q2=decToBin(q-1);
 stringstream str02;
 str02<<q1;
 string str2=str02.str();
 stringstream str04;
 str04<<q2;
 string str4=str04.str();
 cout << "\nENTER MESSAGE\n";
 fflush(stdin);
 cin >> msg;
 for (i = 0; msg[i] != '\0'; i++)
     m[i] = msg[i];
 n = multiply(str1,str2);
 t = multiply(str3,str4);
 ce();
 cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";
 for (i = 0; i < j - 1; i++)

 cout << e[i] << "\t" << d[i] << "\n";
 encrypt();
 decrypt();
 return 0;
}

void ce()
{
 int k;
 k = 0;
 for (i = 2; i < t; i++)
 {
 if (t % i == 0)
 continue;
 flag = prime(i);
 if (flag == 1 && i != p && i != q)
 {
 e[k] = i;
 flag = cd(e[k]);
 if (flag > 0)
 {
 d[k] = flag;
 k++;
 }
 if (k == 99)
 break;
 }
 }
}
long int cd(long int x)
{
 long int k = 1;
 while (1)
 {
 k = k + t;
 if (k % x == 0)
 return (k / x);
 }
}
void encrypt()
{
 long int pt, ct, key = e[0], k, len;
 i = 0;
 len = strlen(msg);
 while (i != len)
 {
 pt = m[i];
 pt = pt - 96;
 k = 1;
 for (j = 0; j < key; j++)
 {
 k = k * pt;
 k = k % n;
 }
 temp[i] = k;
 ct = k + 96;
 en[i] = ct;
 i++;
 }
en[i] = -1;
 cout << "\nTHE ENCRYPTED MESSAGE IS\n";
 for (i = 0; en[i] != -1; i++)
 printf("%c", en[i]);
}
void decrypt()
{
    long int pt, ct, key = d[0], k;
 i = 0;
 while (en[i] != -1)
 {
      ct = temp[i];
 k = 1;
 for (j = 0; j < key; j++)
 {
      k = k * ct;
 k = k % n;
 }
 pt = k + 96;
 m[i] = pt;
 i++;
 }
 m[i] = -1;
 cout << "\nTHE DECRYPTED MESSAGE IS\n";
 for (i = 0; m[i] != -1; i++)
 printf("%c", m[i]);
}
