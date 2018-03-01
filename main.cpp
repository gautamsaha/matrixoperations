/******************************************************************************

                              Matrix Operations Program.

*******************************************************************************/

#include <iostream>

using namespace std;

#define GETINDEX(r, c, n_cols) (r*n_cols + c)

class Matrix{

	public:
	
		int n_cols;
		int n_rows;
		
		int* matrix = NULL;
		
		Matrix(){
			cout << "Insert the rows & columns count " << endl;
			cout << "row count:";
			cin >>n_rows;
			cout << "column count:";
			cin >> n_cols;
			matrix = new int[n_rows*n_cols];
		}
		
		Matrix(int r,int c){
			n_rows = r;
			n_cols = c;
			matrix = new int[n_rows*n_cols];
		}
		
		void GetShape(){
			cout << " matrix shape: " << n_rows << " X " << n_cols <<endl;
		}
		
		~Matrix(){
			delete[] matrix;
		}
		
		void FillValues(int row_size, int col_size, int* arr){
		    
		    if((row_size != n_rows) || (col_size != n_cols)){
		        cout << "------  Bad Sample Data -----" <<endl;
		    }
		    
		    for(int r=0;r<n_rows;r++){
			    for(int c=0;c<n_cols;c++){
			        matrix[GETINDEX(r,c,n_cols)]  = arr[r*n_cols+c] ;
			    }
			}
		    
		}
		
		void FillValues(){
			
			cout << " Fill matrix with " << n_rows << " X " << n_cols << " values:" <<endl;
			for(int r=0;r<n_rows;r++){
			    
			    for(int c=0;c<n_cols;c++){
			        cout << " row " << r+1 << ", col " << c+1 << ":";
			        cin >> matrix[GETINDEX(r,c,n_cols)] ;
			     //   cout <<endl;
			    }
			}
			
		}
		
		void GetValues(){
			
			cout << "Matrix with " << n_rows << " X " << n_cols << " values:" <<endl;
			for(int r=0;r<n_rows;r++){
			    for(int c=0;c<n_cols;c++){
			        cout << matrix[GETINDEX(r,c,n_cols)] << " ";
			    }
			    cout << endl;
			}
			
		}
		
		Matrix* Transpose(){
		    Matrix* _t = new Matrix(n_cols,n_rows);
		    
		    for(int r=0;r<n_rows;r++){
			    for(int c=0;c<n_cols;c++){
			        _t->matrix[GETINDEX(c,r,n_rows)] =  matrix[GETINDEX(r,c,n_cols)];
			    }
			}
		    
		    return _t;
		}
		
		Matrix* Multiply(Matrix* y){
		    if(NULL==y){
		        cout << "Input matrices invalid" << endl;
		    }
		    
		    if(n_cols != y->n_rows){
		        cout << "First matrix columns count MUST be same as Second matrix's rows count" << endl;
		    }
		    
		    int _prod_n_rows = n_rows;
		    int _prod_n_cols = y->n_cols;
		    Matrix* _prod = new Matrix(_prod_n_rows,_prod_n_cols);
		    
		    for(int r=0;r<_prod_n_rows;r++){
			    for(int c=0;c<_prod_n_cols;c++){
			        
			        //Calculate the n-tuple dot product
			        for(int k=0;k<n_cols;k++){
			            _prod->matrix[GETINDEX(r,c,_prod_n_cols)] 
			                += matrix[GETINDEX(r,k,n_cols)] 
			                    * y->matrix[GETINDEX(k,c,y->n_cols)];
			        }
			    }
		    }
		    
		    return _prod;
		    
		}
		
};

void transpose_sample()
{
    cout << "Transpose operation:" << endl;
	Matrix A = Matrix(4,3);
	
// 	A.GetShape();
    int arr[4][3]={ {2,3,4},
                    {5,6,7},
                    {8,9,10},
                    {11,12,13}};
	A.FillValues(4,3,(int*)arr);
	A.GetValues();
	
	cout << "Transpose result:" << endl;
	Matrix* tA = A.Transpose();
	tA->GetValues();
	delete tA;
    
}

void transpose_userinput()
{
    cout << "Transpose operation:" << endl;
	Matrix A = Matrix();
	
// 	A.GetShape();
	A.FillValues();
	A.GetValues();
	
	cout << "Transpose result:" << endl;
	Matrix* tA = A.Transpose();
	tA->GetValues();
	delete tA;
    
}

void multiply_sample()
{
    cout << endl << "Multiply operation: Positive Test" << endl;
	cout << "First matrix:" << endl;
	Matrix B = Matrix(2,3);
	int arr_1[2][3]={ {2,4,6},
                        {8,10,12}};
	B.FillValues(2,3,(int*)arr_1);
	B.GetValues();
	
	cout << "Second matrix:" << endl;
	Matrix C = Matrix(3,4);
	int arr_2[3][4]={ {3,5,7,9},
                    {11,13,15,17},
                    {19,21,23,25}};
	C.FillValues(3,4,(int*)arr_2);
	C.GetValues();

	Matrix* pBC = B.Multiply(&C);
	if(NULL != pBC){
	    cout << "Multiplication result:" << endl;
	    pBC->GetValues();
	    
	    delete pBC;
	}
	else{
	    cout << " Multiply returned NULL" << endl;
	}
    
}

void multiply_userinput()
{
    cout << endl << "Multiply operation (User Input):" << endl;
	cout << "First matrix:" << endl;
	Matrix B = Matrix();
// 	B.GetShape();
	B.FillValues();
	B.GetValues();
	
	cout << "Second matrix:" << endl;
	Matrix C = Matrix();
// 	B.GetShape();
	C.FillValues();
	C.GetValues();

	Matrix* pAB = B.Multiply(&C);
	if(NULL != pAB){
	    cout << "Multiplication result:" << endl;
	    pAB->GetValues();
	    
	    delete pAB;
	}
	else{
	    cout << " Multiply returned NULL" << endl;
	}
    
}


int main()
{
    int inputkey=0;
    while(1){
        cout << "Matrix Operations" << endl;
        
        cout<< "1.Transpose operation: Sample Input"<<endl;
        cout<< "2.Transpose operation: User Input"<<endl;
        cout<< "3.Multiply operation: Sample Input"<<endl;
        cout<< "4.Multiply operation: User Input"<<endl;
        cout<< "99.Exit Program"<<endl<<endl;
        
        cout<< "Enter menu option:"<<endl;
        cin >> inputkey;
        
        switch(inputkey){
            case 1: transpose_sample(); //Sample data provided in code
            break;
            case 2: transpose_userinput;    //Data to be typed in by user
            break;
            case 3: multiply_sample(); //Sample data provided in code
            break;
            case 4: multiply_userinput(); //Data to be typed in by user
            break;
            case 99: return 0;
            default: cout << "invalid option" << endl;
        }
        
    }
	
	return 0;
}



