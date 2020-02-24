#include <cstdlib>
#include <iostream>
#include<cstdio>
using namespace std;

struct dugum{ //Liste yap˝s˝
 int veri;
 struct dugum *sonra;
} *basla; //dugum turunde yapi
class bagli_liste{ //liste S˝n˝f˝ 
      public:
             dugum *olustur(int);
             void basa_ekle();
             void sonuna_ekle();
             //void arastir();
             void sil();
             void goster();
             bagli_liste(){ //constructer (yap˝c˝ metod)
                           basla=NULL;
             }         
};
      
int main(int argc, char *argv[])
{
    int secim,i;
    bagli_liste listem;
    basla=NULL;
    while(1){
         cout<<endl<<"______________________________"<<endl;
               cout<<"      Liste Operasyonları     "<<endl;
         cout<<endl<<"______________________________"<<endl;
               cout<<"   1-Basa deger ekle"<<endl;
               cout<<"   2-Sona Deger ekle"<<endl;
               cout<<"   3-Deger sil"<<endl;
               cout<<"   4-Goster"<<endl;
               cout<<"   5-CIKIS"<<endl;
               cout<<"______________________________"<<endl;
               cout<<"SECIM:";
               cin>>secim;
               switch(secim){
                    case 1:
                         listem.basa_ekle();
                         cout<<endl;
                         break;
                    case 2:
                         listem.sonuna_ekle();
                         cout<<endl;
                         break;
                    case 3:
                         listem.sil();
                         cout<<endl;
                         break;
                    case 4:
                         listem.goster();
                         cout<<endl;
                         break;
                    case 5:
                         exit(0);
                         break;
                    default:
                            cout<<"Hatali giris!"<<endl;
               }
                
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

dugum *bagli_liste::olustur(int sayi){
      struct dugum *tmp;
      tmp=new(struct dugum);
      if(tmp==NULL){
         cout<<"Bellek adreslenemedi"<<endl;
         return NULL;               
      }else{
            tmp->veri=sayi;
            tmp->sonra=NULL;
            return tmp ;              
      }   
}
void bagli_liste::basa_ekle(){
  int deger;
  cout<<"Deger gir (Basa):";
  cin>>deger;
  struct dugum *tmp, *p;
  tmp=olustur(deger);
  if(basla==NULL){
         basla=tmp;
         basla->sonra=NULL;
  }else{
        p=basla;
        basla=tmp;
        basla->sonra=p; 
  }
      
}

void bagli_liste::sonuna_ekle(){
      int deger;
      cout<<"Deger Gir (Sona):";
      cin>>deger;
      struct dugum *tmp, *p;
      tmp=olustur(deger);
      if(basla==NULL){
         basla=tmp;
         basla->sonra=NULL;
  		}else{  			
     		 p=basla;
      		while(p->sonra!=NULL){
          		 p=p->sonra;
      		}
      }
      p->sonra=tmp;

}
void bagli_liste::sil(){
      int deger;
      cout<<"Silinecek deger:";
      cin>>deger;
      struct dugum *tmp, *p;
      tmp=basla;
      while(tmp!=NULL){
            if(tmp->veri==deger){
               if(tmp==basla){
                  basla=tmp->sonra;
                  free(tmp);
				  return ;  
               }else{
                 p->sonra=tmp->sonra;
                 free(tmp);
                 return ;
               }
            }else{
                  p=tmp;
                  tmp=tmp->sonra;
            }
      }    
}
void bagli_liste::goster(){
     struct dugum *tmp;
     if(basla==NULL){
        cout<<"Liste BOS!"<<endl;
        return;                
     }
     tmp=basla;
   
     cout<<"=========================="<<endl;
     cout<<"=           LISTE        ="<<endl;
     cout<<"=========================="<<endl;
     while(tmp!=NULL){
         cout<<tmp->veri<<"-->";
         tmp=tmp->sonra;
     }
     cout<<"NULL"<<endl;
}


