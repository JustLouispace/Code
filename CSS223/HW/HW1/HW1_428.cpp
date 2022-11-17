#include <iostream>
#include <math.h>
#include <typeinfo>
#include <sstream>
#include<string>
using namespace std;
struct  typeF{
	int idF;
	string NameF;
	float NeF;
	float NiF;
	float TeF;
	float TiF;
	float SeF;
	float SiF;
	float FeF;
	float FiF;
	string TypeF;
	float Distance;
}type[54] ;

int main(){
	//Me
	int Myid = 64090500428;
	string MyName = "Chaninat Phongam";
	float MyNe = 29.6;
	float MyNi = 28.6;
	float MyTe = 27;
	float MyTi = 23;
	float MySe = 28;
	float MySi = 27;
	float MyFe = 23;
	float MyFi = 30;
	string MyType = "INTP";
	//Friend
	float a[54] = {};
	int idAll[54] = {64090500401,64090500402,64090500403,64090500404,64090500405,64090500406,64090500407,64090500408,64090500409,64090500410,
	64090500411,64090500412,64090500413,64090500414,64090500415,64090500416,64090500417,64090500418,64090500419,64090500420,64090500421,64090500422,
	64090500423,64090500424,64090500425,64090500426,64090500427,64090500429,64090500430,64090500431,64090500432,64090500433,64090500434,64090500436,
	64090500437,64090500439,64090500440,64090500441,64090500442,64090500443,64090500444,64090500445,64090500446,64090500447,64090500449,64090500450,
	64090500451,64090500452,64090500453,64090500454,63090500248,63090500219,63090500234,63090500202};
	string NameAll[54] = {"Chanunya Srathongtha","Nattapon Pongkao","Thanachote Wattanakhantijarone","Thanyapisit Buaprakhong","Punnapa Thianchai",
	"Pakawat Kulchot","Varintorn SIthisint","Sirawit Pongsawet","Awirut Pusansa-ad","Kantapon Hiranchatchawal","Kittpot Onnomdee","Jaruwit Singsom",
	"Chananan sudjairak","Yanisa Limjantra","Thalit Chaimunin","Thatsamaphon Boonchuntuk","Panachai Likhitpanyarat","Pawaris Chaideesripraphan",
	"Pimpatcha Singh","Walaiporn Khumplub","Watcharapol Treesatthayasakul","Apiwich Visarnlerdsiri","Kanok Vongsaroj","Kanokwan Rungruengchokchai",
	"Kollawat Ruanghirun","Jittapat Chanyarungroj","Jirapat Jirayanamit","Chutphon Kanokpannachot","Noppawut Iamwongsri","Nutthanon Thongcharoen",
	"Tuangsub Rattanathai","Thana Prajonkla","Teerapong Pongdarnpet","Nanthawat Sukkam","Nitiphat Unrrom","Puntana Saengchot","Parichart Sae-yhooong",
	"Pongpayom Monplub","Ponragrit Pasurakarn","Pumipat Korncharornpisuit","Rawisada Anuruttikun","Waritnan Panpimyai","Warisara Kanyaprasit",
	"Watchara Buasrirattana","Vitchakorn Charoenying","Sinthon Wilke","Siraphat Ninprasert","Onicha Nitilappool","Alisa Wongcharoensatit",
	"Panicha Kunanuntapong","Sutida Chankaew","Thanphitcha Khuenyotha","Natchanon Sareetee","Kuntida Meekam"};
	float NeAll[54] = {28.2,26.4,24.4,41,24.2,28,22.4,26,31,19.8,40.2,41.6,26,27,29.2,26.2,35,22.8,24.8,22.6,26.4,20.4,37.4,37,28.4,39.4,27.8,
	30.4,29,28.2,25,24,26.6,24.8,36.4,22.8,41.2,35,31,29.6,21,29.6,25.8,21,35.4,26.4,23.8,22.6,30.4,40,18.6,34.2,27.6,32.8};
	float NiAll[54] = {22,24,14,26.4,21.4,23.8,22,17.6,29.8,19,30,36.6,25,19,18.6,26.6,32,24,24.6,25,24.6,21,31.4,19.8,31.2,34,19.6,35.4,21.6,
	17.6,25,25.8,26,21.8,38.2,23.6,30.8,27.8,28.6,25.6,25.4,30,36,26.6,28,26.4,26,12.6,21.4,32.2,30.2,27,23,34.4};
	float TeAll[54] = {20,30,30,44,27,34,31,23,38,34,31,25,24,26,31,30,30,28,26,34,24,26,27,35,18,26,29,34,27,35,21,42,24,27,32,25,31,27,29,44,
	25,20,27,26,38,33,34,29,30,20,31,32,30,34};
	float TiAll[54] = {30,28,26,38,28,34,29,29,19,25,30,18,36,20,36,33,34,32,32,25,30,29,38,23,25,24,32,26,19,39,27,35,28,35,31,27,41,40,33,39,
	30,29,34,26,29,39,28,32,31,32,27,41,33,35};
	float SeAll[54] = {27,32,31,43,31,36,34,21,27,21,32,27,33,28,27,32,28,22,33,24,30,23,22,31,21,30,29,26,26,26,21,38,31,28,23,28,32,39,31,38,
	30,24,22,19,25,21,28,24,20,22,27,29,35,29};
	float SiAll[54] = {27,31,31,36,30,37,38,21,31,29,36,32,33,33,30,37,30,33,34,28,24,22,30,29,24,37,28,35,28,37,27,35,36,36,27,28,33,38,29,42,
	32,30,28,30,30,30,21,41,27,44,25,32,34,27};
	float FeAll[54] = {27,24,24,34,33,36,35,25,30,26,37,32,26,24,25,32,27,25,28,26,23,20,43,35,22,30,27,33,23,28,23,33,27,27,25,24,43,41,26,32,
	27,28,28,21,36,23,22,23,19,16,19,32,38,34};
	float FiAll[54] = {20,26,17,32,25,30,19,17,32,22,40,40,21,15,22,29,24,17,16,25,25,15,28,27,18,32,19,22,25,20,24,36,27,22,32,25,25,33,25,33,
	22,20,9,24,27,26,17,15,10,27,19,26,32,30};
	string TypeAll[54] = {"ENFJ","ISTP","ESTP","ENTJ","ISFJ","ESTP","ESTP","ESFP","ESFP","ESTP","ENFP","INTP","ESTJ","ENFP","ESTJ","ISTJ","INTP",
	"ISFJ","ESTJ","ESTJ","ESTJ","ENFP","ESFJ","ESFP","INFP","INTP","ESFJ","ISTP","ENTP","ESTJ","ISFJ","ESTJ","INTP","ISFJ","INTP","ISFJ","ESFJ",
	"ISTJ","ESTP","ISTJ","ISFJ","INTP","INFJ","ISTP","INFP","INTP","ISTP","ISTJ","INTP","INTP","ENTP","ENTJ","ISTJ","INFJ"};

	for (int i = 0; i < 54; i++){
		type[i].NeF = NeAll[i];
		type[i].NiF = NiAll[i];
		type[i].TeF = TeAll[i];
		type[i].TiF = TiAll[i];
		type[i].SeF = SeAll[i];
		type[i].SiF = SiAll[i];
		type[i].FeF = FeAll[i];
		type[i].FiF = FiAll[i];
		type[i].TypeF = TypeAll[i];
		type[i].NameF = NameAll[i];
		type[i].idF = idAll[i];
	//Euclidean
		a[i] = sqrt(pow(MyNe - type[i].NeF, 2) + pow(MyNi - type[i].NiF, 2) + pow(MyTe - type[i].TeF, 2) 
					+ pow(MyTi - type[i].TiF, 2) + pow(MySe - type[i].SeF, 2) + pow(MySi - type[i].SiF, 2) + pow(MyFe - type[i].FeF, 2)
					+ pow(MyFi - type[i].FiF, 2));
		type[i].Distance = a[i]; 
	//	cout << a[i] << "\t";
	cout << type[i].NameF << " : " <<type[i].Distance << endl;
	}
	// sort find closet
	int near1 = 0, near2 = 0, near3 = 0;
	for (int i = 1; i < 54; i++){
        if (a[i] < a[near1]){
            near3 = near2;
            near2 = near1;
            near1 = i;
        }
        else if (a[i] < a[near2]){
            near3 = near2;
            near2 = i;
        }
        else if (a[i] < a[near2]){
            near3 = i;
        }
    }
    //closet friend
    cout << "Nearest Neighbors 1 : " << type[near1].NameF << endl;
    cout << "Nearest Neighbors 2 : " << type[near2].NameF << endl;
    cout << "Nearest Neighbors 3 : " << type[near3].NameF << endl; 

	cout << "MBTI 1 : " << type[near1].TypeF << endl;
    cout << "MBTI 2 : " << type[near2].TypeF << endl;
    cout << "MBTI 3 : " << type[near3].TypeF << endl; 

}