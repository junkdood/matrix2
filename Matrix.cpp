
#include <stdexcept>
#include <iostream>
#include <map>
#include <vector>
#include "Matrix.hpp"
using namespace std;


void Matrix::resize(int nrow, int ncol){
	if(!data.empty()){
		data.resize(nrow);
		for( int i = 0; i < nrow; i++ ){
		 	data[i].resize(ncol);
		}
	}
	 else{
	 	for( int i = 0; i < nrow; i++ ){
		 	vector<int> t;
		 	t.resize(ncol);
		 	data.push_back(t);
		 }
	 }
}

pair<int, int> Matrix::size() const{
	if(data.empty()){
		pair<int, int> a(0,0); 
		return a;
	}
	else{
		pair<int, int> a(data.size(),(*data.begin()).size()); 
		return a;
	}
}

vector<int>& Matrix::operator[](int r) throw(std::out_of_range){
	if(r>size().first-1)throw(out_of_range("catch out_of_range exception"));
	return data[r]; 
}

const vector<int>& Matrix::operator[](int r) const throw(std::out_of_range){
	if(r>size().first-1)throw(out_of_range("catch out_of_range exception"));
	return data[r]; 
}

Matrix Matrix::operator+(const Matrix& other) throw(std::invalid_argument){
	if(size().first==other.size().first&&size().second==other.size().second){
		Matrix t(size().first,size().second);
		for(int i=0;i<size().first;i++){
			for(int ii=0;ii<size().second;ii++){
				t[i][ii]=(*this)[i][ii]+other[i][ii];
			}
		}
		
		return t;
	}
	else{
		throw(std::invalid_argument("catch invalid_argument exception"));
	}
}

Matrix Matrix::operator-(const Matrix& other) throw(std::invalid_argument){
	if(size().first==other.size().first&&size().second==other.size().second){
		Matrix t(size().first,size().second);
		for(int i=0;i<size().first;i++){
			for(int ii=0;ii<size().second;ii++){
				t[i][ii]=(*this)[i][ii]-other[i][ii];
			}
		}
		
		return t;
	}
	else{
		throw(std::invalid_argument("catch invalid_argument exception"));
	}
}

Matrix Matrix::operator*(const Matrix& other) throw(std::invalid_argument){
	if(size().second==other.size().first){
		Matrix t(size().first,other.size().second);
		for(int i=0;i<size().first;i++){
			for(int ii=0;ii<other.size().second;ii++){
				t[i][ii]=0;
				for(int iii=0;iii<size().second;iii++){
					t[i][ii]+=(*this)[i][iii]*other[iii][ii];
				}
			}
		}
		
		return t;
	}
	else{
		throw(std::invalid_argument("catch invalid_argument exception"));
	}
}

Matrix Matrix::dotProduct(const Matrix& other) throw(std::invalid_argument){
	if(size().first==other.size().first&&size().second==other.size().second){
		Matrix t(size().first,size().second);
		for(int i=0;i<size().first;i++){
			for(int ii=0;ii<size().second;ii++){
				t[i][ii]=(*this)[i][ii]*other[i][ii];
			}
		}
		
		return t;
	}
	else{
		throw(std::invalid_argument("catch invalid_argument exception"));
	}
}

Matrix Matrix::innerProduct(const Matrix& other) throw(std::invalid_argument){
	return (*this)*other;
}

  /**
   * For example: 3x3 identity matrix
   *   1 0 0
   *   0 1 0
   *   0 0 1
   */
void Matrix::print(){
	for(int i=0;i<size().first;i++){
		int ii;
		for(ii=0;ii<size().second-1;ii++){
			cout<<(*this)[i][ii]<<' ';
		}
		cout<<(*this)[i][ii]<<endl;
	}
}

