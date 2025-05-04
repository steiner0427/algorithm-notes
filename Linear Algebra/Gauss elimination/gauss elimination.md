대충 양변에 기본행연산을 여러번 갖다박아서 역행렬을 구하는데 사용하는 알고리즘이다. n개의 열에 대해 n번의 행별 빼기연산(1회당 n번연산필요)를 반복하므로 시간복잡도는 $O(n^3)$이다.  
구현은 아래코드와 같이 했다. 우선 정방행렬 $A \in \mathbb{R}^{n\times n}$ 를 입력받고, 맨 마지막 행 벡터부터 시작하여 n-1행까지의 n열의 성분을 0으로 만들고, n-2행까지 n-1열의 성분을 모두 0으로 만들고...이 과정을 반복하여 우선 하삼각 행렬꼴로 바꾼다. 마찬가지 과정을 반대로 적용해 하삼각 행렬을 상삼각화 해주면 대각성분들만 남게되고, 이 대각성분들의 크기에 따라 첨가행렬의 행들을(아래 문제에서는 첨가벡터) 나누어 주면 끝난다.

```c++

#include<bits/stdc++.h>
using namespace std;
void gauss_jordan(vector<vector<double>> &A,vector<double> &v){
    int n = A[0].size();
    for(int i=n-1;i>=1;i--){
        for(int j=i-1;j>=0;j--){
            double m = A[j][i]/A[i][i];
            v[j] -= v[i]*m;
            for(int k=0;k<=n-1;k++){
                A[j][k] -= A[i][k]*m;
            }
        }
    }//tril complete
    
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            double m = A[j][i]/A[i][i];
            v[j] -= v[i]*m;
            for(int k=0;k<=n-1;k++){
                A[j][k] -= A[i][k]*m;
            }
        }
    }
    //triu complete
    
    for(int i=0;i<n;i++){
        v[i]/=A[i][i];
        A[i][i] /= A[i][i];
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<double>> A(n,vector<double>(n,0));
 //zero-based index.
    vector<double> v(n,0);

    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
        }
        cin >> v[i];
    }
    
    gauss_jordan(A,v);
    for(auto &i:v){
        cout << (round(i)) << ' ';
    }
    
}
```
연습문제 : https://www.acmicpc.net/problem/22940


