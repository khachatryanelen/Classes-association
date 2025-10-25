#include <iostream>
#include <cstdlib>
#include <ctime>

 class Matrix{
     private:
        int m_rows;
        int m_columns;
        int** m_matrix;
    public:
        Matrix(int rows,int columns){
            m_rows=rows;
            m_columns=columns;
            allocateMemory();
        }
        Matrix(){
            m_rows=5;
            m_columns=5;
            allocateMemory();
        }
        Matrix(const Matrix& other){
            this->m_rows=other.m_rows;
            this->m_columns=other.m_columns;
            this->m_matrix=new int*[m_rows];
            
            for(int i=0;i<m_rows;i++){
                m_matrix[i]=new int[m_columns];
            }
            for(int i=0;i<m_rows;i++){
                for(int j=0;j<m_columns;j++){
                    m_matrix[i][j]=other.m_matrix[i][j];
                }
            }
        }
        Matrix& operator =(const Matrix& other){
            if(this!=&other){
                if(this->m_rows!=other.m_rows || this->m_columns!=other.m_columns){
                    this->~Matrix();
                    
                    this->m_rows=other.m_rows;
                    this->m_columns=other.m_columns;
                    this->m_matrix=new int*[m_rows];
                    
                    for(int i=0;i<m_rows;i++){
                        m_matrix[i]=new int[m_columns];
                    }
                }
                for(int i=0;i<m_rows;i++){
                    for(int j=0;j<m_columns;j++){
                        m_matrix[i][j]=other.m_matrix[i][j];
                    }
                }
                
            }
            return *this;
        }
        ~Matrix(){
            for(int i=0;i<m_rows;i++){
                delete[] m_matrix[i];
            }
            delete[] m_matrix;
        }
    public:
        int getRows(){
            return m_rows;
        }
        int getColumns(){
            return m_columns;
        }
    private:
        void allocateMemory(){
            m_matrix=new int*[m_rows];
            for(int i=0;i<m_rows;i++){
                m_matrix[i]=new int[m_columns];
            }
        } 
    public:
        void init(){
            srand(time(0));
            for(int i=0;i<m_rows;i++){
                for(int j=0;j<m_columns;j++){
                    m_matrix[i][j]=rand()%10;
                }
            }
            
        }
        void print(){
            for(int i=0;i<m_rows;i++){
                for(int j=0;j<m_columns;j++){
                    std::cout<<m_matrix[i][j]<<" ";
                }
                std::cout<<std::endl;
            }
        }
        void set(int row,int col,int number){
            m_matrix[row][col]=number;
        }
        int get(int row,int col){
            return m_matrix[row][col];
        }
 };
int main(int argc, const char* argv[]){
    Matrix* A=new Matrix(4,7);
    
    Matrix B(5,7);
    B.init();
    B.print();
    std::cout<<std::endl;
    
    Matrix C(4,4);
    C.init();
    C.print();
    std::cout<<std::endl;
    C.set(3,2,0);
    std::cout<<std::endl;
    std::cout<<C.get(3,2)<<std::endl;
    
    Matrix D;
    D.init();
    D.print();
    std::cout<<std::endl;
    for(int i=0;i<D.getRows();i++){
        for(int j=0;j<D.getColumns();j++){
            D.set(i,j,5);
        }
    }
    D.print();
    
    delete A;

    return 0;
}