#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<cstring>
#include<conio.h>
#include<cstdlib>
#include<sstream>


using namespace std;

class Base {
public:

	enum result { Kaybetmek = 0, Beraberlik=1, Kazanmak=2 };

	enum result rs1 = Kaybetmek;
	enum result rs2 = Beraberlik;
	enum result rs3 = Kazanmak;
	virtual string getColor()const {
		return " ";
	}
	virtual int compare( Base *base) = 0;


};

class Red : public Base {
public:
	string getColor()const {
		return "R";
	}

	

		int compare( Base *base) {
		if (getColor() == base->getColor())
		{
			return rs2;
			
			
		}
		else if(base->getColor() == "D")
		{
			return base->rs3;
		}
		else if(base->getColor() == "G")
		{
			return rs3;
		}
		else if (base->getColor() == "B")
		{
			return base->rs3;
		}
	
	}


};

class Green : public Base {
public:
	string getColor()const {
		return "G";
	}



	int compare(Base *base) {
		if (getColor() == base->getColor())
		{
			return rs2;
		}
		else if (base->getColor() == "R")
		{
			return base->rs3;
		}
		else if (base->getColor() == "D")
		{
			return rs3;
		}
		else if (base->getColor() == "B")
		{
			return rs3;
		}

	}


};

class Blue : public Base {
public:
	string getColor()const {
		return "B";
	}



	int compare( Base *base) {
		if (getColor() == base->getColor())
		{
			return rs2;
		}
		else if (base->getColor() == "D")
		{
			return base->rs3;
		}
		else if (base->getColor() == "G")
		{
			return base->rs3;
		}
		else if (base->getColor() == "R")
		{
			return rs3;
		}

	}


};

class DarkRed : public Base {
public:
	string getColor()const {
		return "D";
	}



	int compare( Base *base) {
		if (getColor() == base->getColor())
		{
			return rs2;
		}
		else if (base->getColor() == "R")
		{
			return rs3;
		}
		else if (base->getColor() == "G")
		{
			return base->rs3;
		}
		else if (base->getColor() == "B")
		{
			return rs3;
		}

	}


};

class list : public Base {


	Red R1;
	Green G1;
	Blue  B1;
	DarkRed D1;

};

void Display()
{
	 int oyuncu1_puan[22]={0,2,1,0,2,2,2,0,2,2,0,2,2,0,1,0,2,1,2,0,1,0};
	 int oyuncu2_puan[22]={2,0,1,2,0,0,0,2,0,0,2,0,0,2,1,2,0,1,0,2,1,2};
	cout<<endl<<endl;
	cout<<"puan1= ";
for(int i=0;i<22;i++)
{
	cout<<oyuncu1_puan[i]<<" ";
}
    
	cout<<"\npuan2= ";
for(int i=0;i<22;i++)
{
	cout<<oyuncu2_puan[i]<<" ";
}

	int oyuncu1_beraberlik=0;
	int oyuncu1_kaybetme=0;
	int oyuncu1_kazanmak=0;
	
		int oyuncu2_beraberlik=0;
	int oyuncu2_kaybetme=0;
	int oyuncu2_kazanmak=0;
	for(int i=0; i<22;i++)
	{
		if(oyuncu1_puan[i]==oyuncu2_puan[i])
		{
			
		}
	}
	cout<<endl<<endl;
	cout<<"skor1= "<<endl;
	cout<<"skor2= "<<endl;
	
		cout<<endl<<endl;
	
	
	
}

int main() {
	Base* kart1[22];
	Base* kart2[22];

	string oyuncu_1, oyuncu_2;


	ifstream dosya;
	dosya.open("Kartlar.txt");
	while (!dosya.eof()) {
		getline(dosya, oyuncu_1);
		stringstream oyuncu_1_sectigi_kartlar(oyuncu_1);

		getline(dosya, oyuncu_2);
		stringstream oyuncu_2_sectigi_kartlar(oyuncu_2);
	cout <<"1. oyuncunun sectigi kartlar: "<< oyuncu_1 << endl;
		cout <<"2. oyuncunun sectigi kartlar: " <<oyuncu_2 << endl;
		Display();

		
		char karakter;
		for (int i = 0; i < oyuncu_1.length(); i++) {
			getline(oyuncu_1_sectigi_kartlar, oyuncu_1, ',');
		getline(oyuncu_2_sectigi_kartlar, oyuncu_2, ',');
		
  while(getline(oyuncu_1_sectigi_kartlar, oyuncu_1, ',')){
                   

    while ( dosya.get(karakter) ){
      
      
      if(karakter=='R')
      {
      	kart1[i]=new Red();
      	
	  }
	  
	  else if(karakter=='D'){
	  		kart1[i]=new DarkRed();
	  }
      
        
	  else if(karakter=='G'){
	  		kart1[i]=new Green();
	  }
	    
	  else if(karakter=='B'){
	  		kart1[i]=new Blue();
	  }

    }
		
	}
	
	  while(getline(oyuncu_2_sectigi_kartlar, oyuncu_2, ',')){
                   

    while ( dosya.get(karakter) ){
      
      
      if(karakter=='R')
      {
      	kart2[i]=new Red();
      	
	  }
	  
	  else if(karakter=='D'){
	  		kart2[i]=new DarkRed();
	  }
      
        
	  else if(karakter=='G'){
	  		kart2[i]=new Green();
	  }
	    
	  else if(karakter=='B'){
	  		kart2[i]=new Blue();
	  }

    }
		
	}
	
	}
	
}
for(int i=0;i<21;i++)
{
	kart1[i]->compare(kart2[i]);
	

}
dosya.close();


	return 0;
}
