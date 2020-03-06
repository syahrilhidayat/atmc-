#include <iostream>
using namespace std;  
typedef struct {
 	char nama_user[30];
	char alamat_user[30]; 
	int jumalah_saldo;
	int no_pin;
	int no_rekening; 
}struct_user;  
	
	int no_data;
	struct_user data[30]; 
 
bool daftar(){  
	awal:
	system("cls");
	struct_user struct_user_baru; 
	int cari;
	cout<<"=================================="<<endl;
	cout<<"Daftar"<<endl;
	cout<<"=================================="<<endl; 
	cout<<"Nama        : "; cin>>struct_user_baru.nama_user;
	cout<<"Alamat      : "; cin>>struct_user_baru.alamat_user;
	cout<<"Rekening    : "; cin>>struct_user_baru.no_rekening;
	cout<<"Pin         : "; cin>>struct_user_baru.no_pin; 
	cout<<"Saldo       : "; cin>>struct_user_baru.jumalah_saldo;  
	cout<<"=================================="<<endl; 
 	while(cari<=30){
		if(data[cari].no_rekening == struct_user_baru.no_rekening){
		no_data = cari;
		break;
		}
		cari++;
	}	    
	if(no_data == 0){
 		int i=1;
 		while(i<=30){
			if(data[i].no_rekening == 0 or data[i].no_rekening == struct_user_baru.no_rekening){
				data[i] = struct_user_baru;
	 			break;
			}
			i++;
		}	 
	    data[no_data] = struct_user_baru;  
	    return true;
    }else{
    	return false;
	}
}
  
bool login(){  
	awal:
	system("cls"); 
	int no_rekening, no_pin,cari;
 	cout<<"=================================="<<endl;
	cout<<"Login"<<endl;
	cout<<"=================================="<<endl; 
	cout<<"Masukan No Rekening Anda : "; cin>>no_rekening;
	cout<<"Masukan No Pin Anda      : "; cin>>no_pin;
	cout<<"=================================="<<endl;  
	while(cari<=30){
		if(data[cari].no_rekening == no_rekening){
		no_data = cari;
		break;
		}
		cari++;
	}	    
 	if(data[no_data].no_pin == no_pin){
 		return true;
	}else{
 		return false;
	} 
}
 
void menabung(){
	system("cls");
	int nominal;
 	cout<<"=================================="<<endl;
	cout<<"Menabung"<<endl;
	cout<<"=================================="<<endl;
	cout<<"Masukan Nominal : Rp.";cin>>nominal;
	cout<<"=================================="<<endl;   
	data[no_data].jumalah_saldo = data[no_data].jumalah_saldo + nominal;
 	cout<<"Menabung Berhasil."<<endl;    
	cout<<"=================================="<<endl;   
}

void tariktunai(){
	system("cls");
	int nominal;
	cout<<"=================================="<<endl;
	cout<<"Tarik Tunai"<<endl; 
	cout<<"=================================="<<endl;
	cout<<"Mauskan Nominal            : Rp.";cin>>nominal;
	cout<<"=================================="<<endl;    
 	data[no_data].jumalah_saldo = data[no_data].jumalah_saldo  - nominal;
 	cout<<"Penarikan Tunai Berhasil."<<endl;    
	cout<<"=================================="<<endl;   
}
  

void transfer(){
	system("cls");
 	int nominal, no_rekening,tujuan,cari; 
	cout<<"============================"<<endl;
	cout<<"Transfer"<<endl; 
	cout<<"============================"<<endl;
	cout<<"Masukan No Rekening Tujuan : "; cin>>no_rekening;
	cout<<"Masukan Nominal            : Rp.";cin>>nominal; 
	cout<<"============================"<<endl;
	while(cari<=30){
		if(data[cari].no_rekening == no_rekening){
		tujuan = cari;
		break;
		}
		cari++;
	}	       
	if(data[tujuan].no_rekening == no_rekening){
 		data[no_data].jumalah_saldo = data[no_data].jumalah_saldo - nominal;
 		data[tujuan].jumalah_saldo = data[tujuan].jumalah_saldo + nominal;
	 	cout<<"Transfer Berhasil."<<endl; 
	}else{
		cout<<"No Rekening Tujuan Salah!"<<endl;   
	}
	cout<<"=================================="<<endl;   
}
  
void ceksaldo(){ 
	system("cls");
	cout<<"=================================="<<endl;
	cout<<"Cek Saldo"<<endl;
	cout<<"=================================="<<endl;
    cout<<" Nama Lengkap    : "<<data[no_data].nama_user<<endl;
    cout<<" Alamat          : "<<data[no_data].alamat_user<<endl;
    cout<<" No Rekening     : "<<data[no_data].no_rekening<<endl;
    cout<<" No Pin          : "<<data[no_data].no_pin<<endl;   
   	cout<<" Saldo           : Rp."<<data[no_data].jumalah_saldo<<endl;
   	cout<<"=================================="<<endl;   
}
 
 

int main(){ 
	int pilih; char ulangi;
	bool berhasil;
	awal:
	system("cls");
	cout<<"=================================="<<endl;
	cout<<"Program ATM Bank"<<endl;
	cout<<"=================================="<<endl;
	cout<<"1. Daftar"<<endl;
	cout<<"2. Login"<<endl;
	cout<<"3. Keluar"<<endl;
	cout<<"=================================="<<endl;
	cout<<"Masukan Pilihan Anda : ";cin>>pilih;	
	switch(pilih){
		case 1:  
		    berhasil = daftar();
			if(berhasil==true){
				goto kemenu;
			}else{
				goto awal;
			} 
		case 2:
			berhasil = login();
			if(berhasil==true){
				goto kemenu;
			}else{
				goto awal;
			} 
			break; 
			break;
		case 3:
		 	return 0; 
		default:
			goto awal;
			break;
	}	 
	kemenu: 
	system("cls");  
	cout<<"=================================="<<endl;
	cout<<"Menu"<<endl;
	cout<<"=================================="<<endl;
	cout<<"1. Menabung"<<endl;
	cout<<"2. Transfer"<<endl;
	cout<<"3. Tarik Tunai"<<endl;
	cout<<"4. Cek Saldo"<<endl;
	cout<<"5. Keluar"<<endl;
	cout<<"=================================="<<endl;
	cout<<"Masukan Pilihan Anda : ";cin>>pilih;
	switch(pilih){
		case 1: 
			menabung(); 
			break; 
		case 2:
		 	transfer(); 
			break;
		case 3: 
			tariktunai(); 
			break;
		case 4: 
			ceksaldo(); 
			break;
		case 5: 
			goto awal;
			break;
		default:
			goto kemenu;
			break;
	} 
 	cout<<"Transaksi Lainnya (y/t) : ";cin>>ulangi;
 	if(ulangi=='y'){
 		goto kemenu;
	}
	goto awal;
	return 0;
}

