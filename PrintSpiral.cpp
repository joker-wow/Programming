    #include <iostream>
     
    using namespace std;
     
    void printSpiral(int (*arr)[6], int row, int col) {
    	int flipper = 1;
    	for(int i=0;i<row;i++) {
    		flipper = 1 - flipper;
    		for(int j=0;j<col;j++) {
    			if(flipper) cout<<arr[row-i-1][col-j-1]<<" ";
    			else cout<<arr[i][j]<<" ";
    		}
    	}
    }
     
    int main() {
    	int a[3][6] = { {1,  2,  3,  4,  5,  6},
            {7,  8,  9,  10, 11, 12},
            {13, 14, 15, 16, 17, 18}
        };
     
        printSpiral(a, 3, 6);
     
     
    	return 0;
    }
