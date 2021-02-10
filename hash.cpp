#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

int a0, a1, a2;

class  Key_Index_Pair{
  public:
	char key[40];
	int index;
};


int  collision = 0;
int  Hash_Size;
Key_Index_Pair*  Mapping;   // dynamically creating m-sized Map to map keys to indices for searching   Mapping = new Key_Index_Pair [17863]()



//--------------------------- LINEAR HASHING ---------------------------
class  Linear_Hash_Table {
	char **slots;   //  Pointer to a char pointer in order to create pointer array of size m, each pointing a specific string
  public:
  	Linear_Hash_Table(int);
  	void  insert_token(char*, int);
  	void  search_token(char*);
  	void  print();
};


Linear_Hash_Table::Linear_Hash_Table(int size){
	slots = new char* [size];
	for(int i = 0; i < size; i++){
		slots[i] = NULL;
	}
}


void  Linear_Hash_Table::insert_token(char* str, int ind){
	int i, pos;
	
	for(i = 0; i < Hash_Size; i++){  //  i --> [0,m-1]
		pos = (ind + i) % Hash_Size;  // Linear Hash Funtion
		if(slots[pos] == NULL) break;  // if empty slot is found
		collision++;	// if not, then increment collision by 1
	}
	if(i == Hash_Size){
		cout << "LINEAR HASH TABLE is full, new token couldn't be inserted!!\n\n\n";
		return;
	}
	slots[pos] = new char [strlen(str)+1];
	strcpy( slots[pos], str );
}


void  Linear_Hash_Table::search_token(char* str){
	int j;
	for(j = 0; j < Hash_Size; j++){
		if ( strcmp(Mapping[j].key, str) == 0 )  break;  // if searcehd token is found in Mapping
	}
	if( j == Hash_Size ){
		cout << "Token searched is not found in LINEAR HASH TABLE!!\n\n\n";
		return;
	}
	int ind = Mapping[j].index;
	
	
	
	int i, pos;
	
	for(i = 0; i < Hash_Size; i++){  //  i --> [0,m-1]
		pos = (ind + i) % Hash_Size;  // Linear Hash Funtion
		if(strcmp(slots[pos], str) == 0) break;  // if empty slot is found
		collision++;	// if not, then increment collision by 1
	}
}


void  Linear_Hash_Table::print(){
	cout << endl << endl;
	
	for(int i = 0; i < Hash_Size; i++){
		cout << "LINEAR HASH:  Slot[" << i << "] :  " << slots[i] << endl;
	}
}



//--------------------------- DOUBLE HASHING ---------------------------
class  Double_Hash_Table {
	char **slots;   //  Pointer to a char pointer in order to create pointer array of size m, each pointing a specific string
  public:
  	Double_Hash_Table(int);
  	void  insert_token(char*, int);
  	void  search_token(char*);
  	void  print();
};


Double_Hash_Table::Double_Hash_Table(int size){
	slots = new char* [size];
	for(int i = 0; i < size; i++){
		slots[i] = NULL;
	}
}


void  Double_Hash_Table::insert_token(char* str, int ind){
	int i, pos;
	int p = 13399;   // prime number
	
	for(i = 0; i < Hash_Size; i++){  //  i --> [0,m-1]
		pos = (   (ind % Hash_Size) + i*( p-(ind % p) )   ) % Hash_Size;  // Double Hashing
		if(slots[pos] == NULL) break;  // if empty slot is found
		collision++;	// if not, then increment collision by 1
	}
	if(i == Hash_Size){
		cout << "DOUBLE HASH TABLE is full, new token couldn't be inserted!!\n\n\n";
		return;
	}
	slots[pos] = new char [strlen(str)+1];
	strcpy( slots[pos], str );
	//cout << " " << str << "\t is inserted..!!!\n\n\n";
}



void  Double_Hash_Table::search_token(char* str){
	int j;
	for(j = 0; j < Hash_Size; j++){
		if ( strcmp(Mapping[j].key, str) == 0 )  break;  // if searcehd token is found in Mapping
	}
	if( j == Hash_Size ){
		cout << "Token searched is not found in DOUBLE HASH TABLE!!\n\n\n";
		return;
	}

	int ind = Mapping[j].index;

	int i, pos;
	int p = 13399;   // prime number
	
	for(i = 0; i < Hash_Size; i++){  //  i --> [0,m-1]
		pos = (   (ind % Hash_Size) + i*( p-(ind % p) )   ) % Hash_Size;  // Double Hashing
		if(strcmp(slots[pos], str) == 0) break;  // if empty slot is found
		collision++;	// if not, then increment collision by 1
	}
}


void  Double_Hash_Table::print(){
	cout << endl << endl;
	
	for(int i = 0; i < Hash_Size; i++){
		cout << "DOUBLE HASHING:  Slot[" << i << "] :  " << slots[i] << endl;
	}
}



//--------------------------- UNIVERSAL HASHING ---------------------------
class  Universal_Hash_Table {
	char **slots;   //  Pointer to a char pointer in order to create pointer array of size m, each pointing a specific string
  public:
  	Universal_Hash_Table(int);
  	void  insert_token(char*, int);
  	void  search_token(char*);
  	void  print();
};


Universal_Hash_Table::Universal_Hash_Table(int size){
	slots = new char* [size];
	for(int i = 0; i < size; i++){
		slots[i] = NULL;
	}
}


void  Universal_Hash_Table::insert_token(char* str, int ind){
	int i, pos;
	int K, k0, k1, k2;
	
	K = ind;
	k0 = K % 100;
	
	K = K / 100;
	k1 = K % 100;
	
	K = K / 100;
	k2 = K % 100;

	for(i = 0; i < Hash_Size; i++){  //  i --> [0,m-1]
		pos =  (a0*k0 + a1*k1 + a2*k2 + i)  %  Hash_Size;   // Universal Hashing
		if(slots[pos] == NULL) break;  // if empty slot is found
		collision++;	// if not, then increment collision by 1
	}
	
	if(i == Hash_Size){
		cout << "UNIVERSAL HASH TABLE is full, new token couldn't be inserted!!\n\n\n";
		return;
	}
	slots[pos] = new char [strlen(str)+1];
	strcpy( slots[pos], str );
}



void  Universal_Hash_Table::search_token(char* str){
	int j;
	for(j = 0; j < Hash_Size; j++){
		if ( strcmp(Mapping[j].key, str) == 0 )  break;  // if searcehd token is found in Mapping
	}
	if( j == Hash_Size ){
		cout << "Token searched is not found in UNIVERSAL HASH TABLE!!\n\n\n";
		return;
	}
	int ind = Mapping[j].index;

	int i, pos;
	int K, k0, k1, k2;
	
	K = ind;
	k0 = K % 100;
	
	K = K / 100;
	k1 = K % 100;
	
	K = K / 100;
	k2 = K % 100;

	for(i = 0; i < Hash_Size; i++){  //  i --> [0,m-1]
		pos =  (a0*k0 + a1*k1 + a2*k2 + i)  %  Hash_Size;   // Universal Hashing
		if(strcmp(slots[pos], str) == 0) break;  // if empty slot is found
		collision++;	// if not, then increment collision by 1
	}
}



void  Universal_Hash_Table::print(){
	cout << endl << endl;
	
	for(int i = 0; i < Hash_Size; i++){
		cout << "UNIVERSAL HASHING:  Slot[" << i << "] :  " << slots[i] << endl;
	}
}



int main(int argc, char *argv[]){
	FILE* fptr;
	char choice;
	char token[40];

	srand(time(NULL));

	char *vcb;
	char *srch;
	
	vcb = new char [strlen("vocab.txt")+1];
	strcpy(vcb, "vocab.txt");
	
	srch = new char [strlen("search.txt")+1];
	strcpy(srch, "search.txt");

	if( argv[1] != NULL && argv[2]  != NULL ){
		delete [] vcb;
		delete [] srch;

		vcb = new char [strlen(argv[1])+1];
		strcpy(vcb, argv[1]);
		
		srch = new char [strlen(argv[2])+1];
		strcpy(srch, argv[2]);
		
		cout << "\nNew text files are accepted as parameter";
	}
	else {
		cout << "\nDefault Text files (i.e, vocab.txt & search.txt) are accepted as parameters";
	}

	cout << "\n\nChoose a Hash Size (m)\nEnter a (for 17863) or b (for 21929): ";
	cin >> choice;
	
	while(1){
		
		if(choice == 'a'   ||  choice == 'A'){
			Hash_Size = 17863;
			break;
		}
		else if(choice == 'b'   ||  choice == 'B'){
			Hash_Size = 21929;
			break;
		}
		cout << "Error, type a or b: ";
		cin >> choice;
	}

	a0 = rand() % Hash_Size;
	a1 = rand() % Hash_Size;
	a2 = rand() % Hash_Size;

	Mapping = new Key_Index_Pair [Hash_Size];
	
	Linear_Hash_Table  MyLinear(Hash_Size);
	Double_Hash_Table  MyDouble(Hash_Size);
	Universal_Hash_Table  MyUniversal(Hash_Size);

	fptr = fopen(vcb,"r");
	if(!fptr){
		cout << endl << "ERROR:  Text file(s) specified does not exist!!" << endl;
		return -1;
	}
	
	collision = 0;
	int j = 0;
	while(!feof(fptr)){
		fscanf (fptr, "%s", token);
		
		if (feof(fptr)){
			break;
		}

		MyLinear.insert_token(token, j);
		strcpy(Mapping[j].key, token);
		Mapping[j].index = j;
		j++;
		if(j==Hash_Size)  break;
	}
	cout << endl;
	cout << "HASH SIZE (m): " << Hash_Size << ",\tTotal Collisions in Linear probing (INSERTION): " << collision << endl;
	fclose(fptr);

	fptr = fopen(srch,"r");
	if(!fptr){
		cout << endl << "ERROR:  Text file(s) specified does not exist!!" << endl;
		return -1;
	}
	collision = 0;
	j = 0;
	while(!feof(fptr)){
		fscanf (fptr, "%s", token);
		
		if (feof(fptr)){
			break;
		}

		MyLinear.search_token(token);
		j++;
		if(j==Hash_Size)  break;
	}

	cout << "HASH SIZE (m): " << Hash_Size << ",\tTotal Collisions in Linear probing (SEARCHING): " << collision << endl;
	fclose(fptr);

	fptr = fopen(vcb,"r");
	
	collision = 0;
	j = 0;
	while(!feof(fptr)){
		fscanf (fptr, "%s", token);
		
		if (feof(fptr)){
			break;
		}

		MyDouble.insert_token(token, j);
		j++;
		if(j==Hash_Size)  break;
	}

	cout << "HASH SIZE (m): " << Hash_Size << ",\tTotal Collisions in Double Hashing (INSERTION): " << collision << endl;
	fclose(fptr);

	fptr = fopen(srch,"r");
	
	collision = 0;
	j = 0;
	while(!feof(fptr)){
		fscanf (fptr, "%s", token);
		
		if (feof(fptr)){
			break;
		}

		MyDouble.search_token(token);
		j++;
		if(j==Hash_Size)  break;
	}

	cout << "HASH SIZE (m): " << Hash_Size << ",\tTotal Collisions in Double Hashing (SEARCHING): " << collision << endl;
	fclose(fptr);

	fptr = fopen(vcb,"r");
	
	collision = 0;
	j = 0;
	while(!feof(fptr)){
		fscanf (fptr, "%s", token);
		
		if (feof(fptr)){
			break;
		}
		MyUniversal.insert_token(token, j);
		j++;
		if(j==Hash_Size)  break;
	}

	cout << "HASH SIZE (m): " << Hash_Size << ",\tTotal Collisions in Universal Hashing (INSERTION): " << collision << endl;
	fclose(fptr);

	fptr = fopen(srch,"r");
	
	collision = 0;
	j = 0;
	while(!feof(fptr)){
		fscanf (fptr, "%s", token);
		
		if (feof(fptr)){
			break;
		}
		MyUniversal.search_token(token);
		j++;
		if(j==Hash_Size)  break;
	}

	cout << "HASH SIZE (m): " << Hash_Size << ",\tTotal Collisions in Universal Hashing (SEARCHING): " << collision << endl;
	fclose(fptr);


	char input;
	
	cout << endl << endl <<
	"PRINT TABLE" << endl <<
	"---------------------" << endl <<
	"Linear Hash Table (L)" << endl <<
	"Double Hash Table (D)" << endl <<
	"Universal Hash Table (U)" << endl <<
	"Exit without printing (E)" << endl <<
	"Choice: ";
	cin >> input;
	
	if(input == 'L'  ||  input == 'l'){
		MyLinear.print();	
	}
	
	else if(input == 'D'  ||  input == 'd'){
		MyDouble.print();	
	}
	
	else if(input == 'U'  ||  input == 'u'){
		MyUniversal.print();	
	}

	cout << endl << endl;
	return 0;
	getchar();
}