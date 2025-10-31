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
                    for(int i=0;i<m_rows;i++){
                        delete[] m_matrix[i];
                    }
                    delete[] m_matrix;
                    
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
        Matrix& operator++(){
            for(int i=0;i<m_rows;i++){
                for(int j=0;j<m_columns;j++){
                    m_matrix[i][j]++;;
                }
            }
            return *this;
        }
        Matrix operator++(int){
            Matrix temp=*this;
            for(int i=0;i<m_rows;i++){
                for(int j=0;j<m_columns;j++){
                    m_matrix[i][j]++;;
                }
            }
            return temp;
        }
        Matrix operator*(const Matrix& other){
            if(this->m_columns!=other.m_rows){
                std::cout<<"Operation can not be done! "<<std::endl;
                return *(new Matrix(0,0));
            }
            else{
                int sum=0;
                Matrix* multiplication=new Matrix(this->m_rows,other.m_columns);
                for(int i=0;i<this->m_rows;i++){
                    for(int j=0;j<other.m_columns;j++){
                        for(int k=0;k<this->m_columns;k++){
                            sum+=(this->m_matrix[i][k])*(other.m_matrix[k][j]);
                        }
                        multiplication->m_matrix[i][j]=sum;
                        sum=0;
                    }
                }
                return *multiplication;
            }
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
        void rotate(){
            if(m_rows!=m_columns){
                std::cout <<"Can't rotate"<<std::endl;
            }
            else{
                (*this).rotateAboutDiagonal();
                (*this).rotateAboutMid();
            }
        }
        private:
            void rotateAboutDiagonal(){
                int temp;
                for(int i=0;i<m_rows;i++){
                    for(int j=0;j<i;j++){
                        temp=m_matrix[i][j];
                        m_matrix[i][j]=m_matrix[j][i];
                        m_matrix[j][i]=temp;
                    }
                }
            }
            void rotateAboutMid(){
                int temp;
                for(int i=0;i<m_rows;i++){
                    for(int j=0;j<m_columns/2;j++){
                        temp=m_matrix[i][j];
                        m_matrix[i][j]=m_matrix[i][m_rows-j-1];
                        m_matrix[i][m_rows-j-1]=temp;
                    }
                }
            }
        public:
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
    
    
    Matrix C(4,4);
    Matrix G(4,5);
    C.init();
    G.init();
    C.print();
    std::cout<<std::endl;
    G.print();
    Matrix Bla=C*G;
    std::cout<<std::endl;
    Bla.print();
    std::cout<<std::endl;

    delete A;

    return 0;
}