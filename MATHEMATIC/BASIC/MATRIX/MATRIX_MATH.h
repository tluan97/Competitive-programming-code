
void getCofactor(int mat[N][N], int temp[N][N], 
				int p, int q, int n){ 
	int i = 0, j = 0; 
	for (int row = 0; row < n; row++){ 
		for (int col = 0; col < n; col++){ 
			if (row != p && col != q){ 
				temp[i][j++] = mat[row][col]; 
				if (j == n - 1){ 
					j = 0; 
					i++; 
				}
			}
		}
	}
}
int determinantOfMatrix(int mat[N][N], int n){ 
	int D = 0;
	if (n == 1) return mat[0][0]; 
	int temp[N][N];
	int sign = 1; 
	for (int f = 0; f < n; f++){ 
		getCofactor(mat, temp, 0, f, n); 
		D += sign * mat[0][f] * 
			determinantOfMatrix(temp, n - 1); 
		sign = -sign; 
	} 
	return D;
}
void adjoint(int A[N][N],int adj[N][N]){ 
	if (N == 1){ 
		adj[0][0] = 1; 
		return; 
	}
	int sign = 1, temp[N][N]; 
	for (int i=0; i<N; i++)
	for (int j=0; j<N; j++){ 
		getCofactor(A, temp, i, j, N); 
		sign = ((i+j)%2==0)? 1: -1; 
		adj[j][i] = (sign)*(determinant(temp, N-1)); 
	}
}
bool inverse(int A[N][N], double inverse[N][N]){ 
	int det = determinant(A, N); 
	if (det == 0) return false; 
	int adj[N][N]; 
	adjoint(A, adj);
	for (int i=0; i<N; i++) 
	for (int j=0; j<N; j++) 
		inverse[i][j] = adj[i][j]/double(det);
	return true; 
}
