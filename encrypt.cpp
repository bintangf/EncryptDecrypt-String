// Bintang Fadhli Muhammad
#include <iostream>
#include <string>

using namespace std;

class enkripsi{
	private :
	string sandi;
	public :
	void set(string masuk){
		this->sandi=masuk;
	}
	
	string get(){
		return this->sandi;
	}
	
	void kunci(int sandi){
		char bantu;
		for(int i=0;this->sandi[i]!='\0';++i){
	        bantu=this->sandi[i];
	        if(bantu>='a' && bantu<='z'){
	            bantu=bantu+sandi;
	            if(bantu>'z'){
	                bantu=bantu-'z'+'a'-1;
	            }
	            this->sandi[i]=bantu;
	        }
	        else if(bantu>= 'A' && bantu<= 'Z'){
	            bantu=bantu+sandi;
	            if(bantu>'Z'){
	                bantu=bantu-'Z'+'A'- 1;
	            }       
	            this->sandi[i]=bantu;
	        }
	    }
	}
	
	void buka(int sandi){
		char bantu;
		for(int i=0;this->sandi[i]!='\0';++i){
			bantu=this->sandi[i];
			if(bantu>='a' && bantu<='z'){
				bantu=bantu-sandi;
				if(bantu<'a'){
					bantu=bantu+'z'-'a'+1;
				}
				this->sandi[i]=bantu;
			}
			else if(bantu>='A' && bantu<='Z'){
				bantu=bantu-sandi;
				if(bantu>'a'){
					bantu=bantu+'Z'-'A'+1;
				}
				this->sandi[i]=bantu;
			}
		}
	}
};

int main(){
	enkripsi super;
	int choice, sandi;
	string masuk;
	
	system("color 3F");
	cout<<"Input Your String : ";
	getline(cin,masuk);
	super.set(masuk);
	
	do{	
		system("cls");
		cout<<"Encryption Tools"<<endl;
		cout<<"=========================="<<endl;
		cout<<"Your string : "<<super.get()<<endl;
		cout<<"=========================="<<endl;
		cout<<"1. Input New String"<<endl;
		cout<<"2. Encryption"<<endl;
		cout<<"3. Decryption"<<endl;
		cout<<"4. Exit"<<endl<<endl;
		cout<<"Input your choice : ";
		cin>>choice;
		cout<<endl;
		switch(choice){
			case 1:	cout<<"Input Your New String : ";
					getchar();
					getline(cin,masuk);
					super.set(masuk);
					break;
			
			case 2:	cout<<"Enter the number of Key Encryption : ";
					cin>>sandi;
					super.kunci(sandi);
					break;
					
			case 3:	cout<<"Enter the number of Key Decryption : ";
					cin>>sandi;
					super.buka(sandi);
					break;
		}
	}while(choice!=4);
return 0;
}
