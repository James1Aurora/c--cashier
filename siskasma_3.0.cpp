#include <iostream>
#include <iomanip>

using namespace std;

int kode_barang[100]={1001,1002,1003,1004,1005,1006,1007,1008};
int harga_barang[100]={7000,5000,15000,10000,3000,5000,5000,12000};    
int daftar_pesanan[100];
int banyak_barang[100];
string daftar_barang[100]={"Susu","Milo","Kebab","Potato","Kopi","Ultra Milk","Susu Jahe","Tisu"};

int index = 8;

int mencari_data(int kode_barang[], int banyak_barang, int mencari){
    for (int i = 0; i < banyak_barang; ++i)
	{
		if (kode_barang[i] == mencari )
		{
			return i;
		}
	}
	return -1;
}

int deleting(int pesanan[], int size, int cari)
{
    for (int i = 0; i < size; ++i)
	{
		if (pesanan[i] == cari)
		{
			return i;
		}
	}
	return -1;
}

void filter_1(){
    int list = 0, input_barang,total_barang,edit,edit_jumlah,hapus,cari_hapus,uang_pembayaran;
    int hargatotal1,hargatotal3, hargatotal2 = 0,harga1,edit_nama;
    int sizea = sizeof(kode_barang)/sizeof(kode_barang[0]);
    int sizeb = sizeof(daftar_pesanan)/sizeof(daftar_pesanan[0]);

    cout<<"\n||================================================||\n";
    cout<<"||                 INPUT PEMBELIAN                ||\n";
    cout<<"||================================================||\n";
    string konfirmasi;
    awal :
    do
    {
        cout<<"\n ketik '0' jika sudah selesai \n";
        cout<<" Masukan Kode barang     : ";
        cin>>input_barang;
        int info = mencari_data(kode_barang, sizea-1, input_barang); 
        if (input_barang == 0)
        {
            break;
        }else{

            if (info == -1)
            {
                cout<<"\n Barang Tidak Ditemukan \n ";
            }
            else{
                cout<<" Jumlah Barang           : ";
                cin>>banyak_barang[list];
                cout<<"\n||================================================||\n";
                cout<<"|| Kode Barang   : "<<setiosflags(ios::left)<<setw(31)<<kode_barang[info]<<"||\n";
                cout<<"|| Harga Barang  : Rp."<<setiosflags(ios::left)<<setw(28)<<harga_barang[info]<<"||\n";
                cout<<"|| Nama Barang   : "<<setiosflags(ios::left)<<setw(31)<<daftar_barang[info]<<"||\n";
                cout<<"|| Jumlah Barang : "<<setiosflags(ios::left)<<setw(31)<<banyak_barang[list]<<"||\n";
                cout<<"|| Total Harga   : Rp."<<setiosflags(ios::left)<<setw(28)<<banyak_barang[list]*harga_barang[info]<<"||\n";
                cout<<"||================================================||\n";            
                daftar_pesanan[list] = info;
                }  
            list = list + 1;
        }
    } while (list <= 100);
    hargatotal2 = hargatotal2 - hargatotal2;
    struk : 
    cout<<"\n||================================================||\n";
    cout<<"||                 STRUK PEMBELIAN                ||\n";
    cout<<"||================================================||\n";
    cout<<"||kode|| Barang     ||jml||harga    ||harga total ||\n";
    cout<<"||================================================||\n";
    for (int i = 0;i < list;i++)
    {
        total_barang = daftar_pesanan[i];
        hargatotal1 = harga_barang[total_barang]*banyak_barang[i];

        cout<<"||"<<setw(4)<< kode_barang[total_barang]<<"|| "<<setw(10)<< daftar_barang[total_barang]<<" || "<<setw(2)<<banyak_barang[i]
                   <<"||Rp."<<setw(5)<<harga_barang[total_barang]<<" || Rp."<<setw(8)<<hargatotal1<<"||\n";
        hargatotal2 = hargatotal2 + hargatotal1;
    }
    cout<<"||================================================||\n";
    cout<<"|| Total Harga : "<<setw(22)<<""<<setiosflags(ios::left)<<"Rp."<<setw(8)<<hargatotal2<<"||\n";
    cout<<"||================================================||\n";
    cout<<"|| 1. Hapus Barang dari List                      ||\n";
    cout<<"|| 2. Tambah barang ke dalam list                 ||\n";
    cout<<"|| 3. Selesai                                     ||\n";
    cout<<"||================================================||\n";
    cout<<"\n Pilih     : ";
    cin>>edit;

    if (edit == 1)
    {
        cout<<"Masukkan kode Barang     : ";
        cin>>edit_nama;

        cari_hapus = mencari_data(kode_barang, sizea-1 , edit_nama);
        if (cari_hapus == -1) {
            cout<<"Barang Tidak Ditemukan\n";
            cout<<"Masukkan Nama Barang Yang Benar!\n\n";
            goto struk;
        }else {
            cout<<"Jumlah Barang            : ";cin>>edit_jumlah;
            hapus = deleting(daftar_pesanan, sizeb-1, cari_hapus);
            banyak_barang[hapus] = banyak_barang[hapus] - edit_jumlah;
            hargatotal2 = hargatotal2 - hargatotal2;
            goto struk;
        }
    }else if (edit == 2){
        cout<<"\n";
        goto awal;
    }else if (edit == 3){
        cout<<"\n Input Uang Pembayaran : ";
        cin>>uang_pembayaran;
        if (uang_pembayaran >= hargatotal2)
        {
            cout<<"\n||================================================||\n";
            cout<<"||                 STRUK PEMBELIAN                ||\n";
            cout<<"||================================================||\n";
            cout<<"||kode|| Barang     ||jml||harga    ||harga total ||\n";
            cout<<"||================================================||\n";
            for (int i = 0;i < list;i++)
            {   
                total_barang = daftar_pesanan[i];
                hargatotal1 = harga_barang[total_barang]*banyak_barang[i];

                cout<<"||"<<setw(4)<< kode_barang[total_barang]<<"|| "<<setw(10)<< daftar_barang[total_barang]<<" || "<<setw(2)<<banyak_barang[i]
                   <<"||Rp."<<setw(5)<<harga_barang[total_barang]<<" || Rp."<<setw(8)<<hargatotal1<<"||\n";
                hargatotal3 += hargatotal1;
            }
            cout<<"||================================================||\n";
            cout<<"|| Total Harga       : "<<setw(16)<<""<<setiosflags(ios::left)<<"Rp."<<setw(8)<<hargatotal2<<"||\n";
            int kembalian = uang_pembayaran - hargatotal2;
            cout<<"||================================================||\n";
            cout<<"|| Uang Pembayaran   : "<<setw(16)<<""<<setiosflags(ios::left)<<"Rp."<<setw(8)<<uang_pembayaran<<"||\n";
            cout<<"|| kembalian         : "<<setw(16)<<""<<setiosflags(ios::left)<<"Rp."<<setw(8)<<kembalian<<"||\n";
            cout<<"||        Terima Kasih Sudah Berbelanja!          ||\n";
            cout<<"||================================================||\n";
        }

    }else {
        cout<<" Maaf pilihan tidak ada\n";
    }          
    }

void filter_2(){
    cout<<"\n||================================================||\n";
    cout<<"||                  Daftar Barang                 ||\n";
    cout<<"||================================================||\n";
    cout<<"|| kode barang ||   Nama Barang   || Harga Barang ||\n";
    cout<<"||================================================||\n";
        for (int i = 0; i < index; i++)
        {
        cout<<"|| "<<setiosflags(ios::left)<<setw(12)<<kode_barang[i]<<"|| ";
        cout<<setiosflags(ios::left)<<setw(16)<<daftar_barang[i]<<"|| Rp.";
        cout<<setiosflags(ios::left)<<setw(9)<<harga_barang[i]<<" ||\n";
        }
        cout<<"||================================================||\n";
        
    }

void filter_3(){
    int jumlah_barang,index_barang;
    cout<<"\n||================================================||\n";
    cout<<"||                Menambahkan Barang              ||\n";
    cout<<"||================================================||\n\n";
    cout<<" Berapa Barang yang ingin ditambah   : ";
    cin>>jumlah_barang;
    for (int i = 0; i < jumlah_barang; i++)
    {
        cout<<"\n Barang Ke-"<<i+1<<"\n";
        int b = i + 8;
        int index_barang_terakhir = 7+1;
        cout<<" Nama Barang     : ";
        cin>>daftar_barang[b];
        cout<<" Harga Barang    : ";
        cin>>harga_barang[b];
        kode_barang[b] = 1001+b;
    }
    index = index + jumlah_barang;
    filter_2();
}

void daftar_menu (){
    cout<<"\n||================================================||\n";
    cout<<"||                  FITUR SISKASMA                ||\n";
    cout<<"||================================================||\n";
    cout<<"|| 1. Input Pembelian                             ||\n";
    cout<<"|| 2. Daftar Barang                               ||\n";
    cout<<"|| 3. Tambah Barang                               ||\n";
    cout<<"||================================================||\n";
}

int main(){
    string konfirmasi;
    int filter,i = 1;
    string username = "admin", password = "admin",input_username,input_password;

    do
    {   
        cout<<"\n||================================================||\n";
        cout<<"||                 LOGIN SISKASMA                 ||\n";
        cout<<"||================================================||\n";
        cout<<" \n Username       : ";cin>>input_username;
        cout<<" Password       : ";cin>>input_password;
        if (username == input_username && password == input_password)
        {
            do
            {
            system("CLS");
            daftar_menu();

            cout<<"\n Pilih fitur  : ";
            cin>>filter;
            if (filter == 1)
            {
                system("CLS");
                filter_1();
            }else if (filter == 2){
                system("CLS");
                filter_2();
            }else if (filter == 3){
                system("CLS");
                filter_3();
            }else {
                cout<<"\n||================================================||\n";
                cout<<"|| Maaf Filter Tidak Ditemukan                    ||\n";
                cout<<"||================================================||\n";
            }
            
            cout<<"|| (tekan 'y' untuk kembali ke menu)              ||\n";
            cout<<"|| (tekan apa saja untuk kembali ke login)        ||\n";
            cout<<"||================================================||\n";
            cout<<"\nApakah anda ingin kembali ke menu ? ";
            cin>>konfirmasi;
            
            } while (konfirmasi == "y");
            cout<<"\n||================================================||\n";
            cout<<"|| Terima Kasih                                   ||\n";
            cout<<"||================================================||\n";
        }else
        {
        cout << " Username atau password anda salah (" << i << "x)" << endl;
        i = i + 1;
        }
    } while (i <= 3 );
    cout<<"\n||================================================||\n";
    cout<<"|| Maaaf anda tidak dapat memasuki SISKASMA       ||\n";
    cout<<"||================================================||\n";}