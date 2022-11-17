#include <iostream>
#include <math.h>

using namespace std;

struct TypeAllFriend
{
	int id;
	float NeFriend;
	float NiFriend;
	float TeFriend;
	float TiFriend;
	float SeFriend;
	float SiFriend;
	float FeFriend;
	float FiFriend;
	float Distance;
	string FriendName;
	string Ptype;
} types[54];

int main()
{
	float arr[54] = {};
	int id[54] = {401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,426,427,428,429,430,431,432,433,434,436,437,439,440,441,442,443,444,445,446,447,449,450,451,452,453,454,248,219,234,202};
	float NeF[54] = {28.2,26.4,24.4,41,24.2,28,22.4,26,31,19.8,40.2,41.6,26,27,29.2,26.2,35,22.8,24.8,22.6,26.4,20.4,37.4,37,39.4,27.8,29.6,30.4,29,28.2,25,24,26.6,24.8,36.4,22.8,41.2,35,31,29.6,21,29.6,25.8,21,35.4,26.4,23.8,22.6,30.4,40,18.6,34.2,27.6,32.8};
	float NiF[54] = {22,24,14,26.4,21.4,23.8,22,17.6,29.8,19,30,36.6,25,19,18.6,26.6,32,24,24.6,25,24.6,21,31.4,19.8,34,19.6,28.6,35.4,21.6,17.6,25,25.8,26,21.8,38.2,23.6,30.8,27.8,28.6,25.6,25.4,30,36,26.6,28,26.4,26,12.6,21.4,32.2,30.2,27,23,34.4};
	float TeF[54] = {20,30,30,44,27,34,31,23,38,34,31,25,24,26,31,30,30,28,26,34,24,26,27,35,26,29,27,34,27,35,21,42,24,27,32,25,31,27,29,44,25,20,27,26,38,33,34,29,30,20,31,32,30,34};
	float TiF[54] = {30,28,26,38,28,34,29,29,19,25,30,18,36,20,36,33,34,32,32,25,30,29,38,23,24,32,23,26,19,39,27,35,28,35,31,27,41,40,33,39,30,29,34,26,29,39,28,32,31,32,27,41,33,35};
	float SeF[54] = {27,32,31,43,31,36,34,21,27,21,32,27,33,28,27,32,28,22,33,24,30,23,22,31,30,29,28,26,26,26,21,38,31,28,23,28,32,39,31,38,30,24,22,19,25,21,28,24,20,22,27,29,35,29};
	float SiF[54] = {27,31,31,36,30,37,38,21,31,29,36,32,33,33,30,37,30,33,34,28,24,22,30,29,37,28,27,35,28,37,27,35,36,36,27,28,33,38,29,42,32,30,28,30,30,30,21,41,27,44,25,32,34,27};
	float FeF[54] = {27,24,24,34,33,36,35,25,30,26,37,32,26,24,25,32,27,25,28,26,23,20,43,35,30,27,23,33,23,28,23,33,27,27,25,24,43,41,26,32,27,28,28,21,36,23,22,23,19,16,19,32,38,34};
	float FiF[54] = {20,26,17,32,25,30,19,17,32,22,40,40,21,15,22,29,24,17,16,25,25,15,28,27,32,19,30,22,25,20,24,36,27,22,32,25,25,33,25,33,22,20,9,24,27,26,17,15,10,27,19,26,32,30};
	string FriendName[54] = {"Chanunya Srathongtha","Nattapon Pongkao","Thanachote Wattanakhantijarone","Thanyapisit Buaprakhong","Punnapa Thianchai","Pakawat Kulchot","Varintorn SIthisint","Sirawit Pongsawet","Awirut Pusansa-ad","Kantapon Hiranchatchawal","Kittpot Onnomdee","Jaruwit Singsom","Chananan sudjairak","Yanisa Limjantra","Thalit Chaimunin","Thatsamaphon Boonchuntuk","Panachai Likhitpanyarat","Pawaris Chaideesripraphan","Pimpatcha Singh","Walaiporn Khumplub","Watcharapol Treesatthayasakul","Apiwich Visarnlerdsiri","Kanok Vongsaroj","Kanokwan Rungruengchokchai","Jittapat Chanyarungroj","Jirapat Jirayanamit","Chaninat Phongam","Chutphon Kanokpannachot","Noppawut Iamwongsri","Nutthanon Thongcharoen","Tuangsub Rattanathai","Thana Prajonkla","Teerapong Pongdarnpet","Nanthawat Sukkam","Nitiphat Unrrom","Puntana Saengchot","Parichart Sae-yhooong","Pongpayom Monplub","Ponragrit Pasurakarn","Pumipat Korncharornpisuit","Rawisada Anuruttikun","Waritnan Panpimyai","Warisara Kanyaprasit","Watchara Buasrirattana","Vitchakorn Charoenying","Sinthon Wilke","Siraphat Ninprasert","Onicha Nitilappool","Alisa Wongcharoensatit","Panicha Kunanuntapong","Sutida Chankaew","Thanphitcha Khuenyotha","Natchanon Sareetee","Kuntida Meekam"
};
	string Ptype[54] = {"ENFJ","ISTP","ESTP","ENTJ","ISFJ","ESTP","ESTP","ESFP","ESFP","ESTP","ENFP","INTP","ESTJ","ENFP","ESTJ","ISTJ","INTP","ISFJ","ESTJ","ESTJ","ESTJ","ENFP","ESFJ","ESFP","INTP","ESTP","INTP","ISTP","ENTP","ESTJ","ISFJ","ESTJ","INTP","ISFJ","INTP","ISFJ","ESFJ","ISTJ","ESTP","ISTJ","ISFJ","INTP","INFJ","ISTP","INFP","INTP","ISTP","ISTJ","INTP","INTP","ENTP","ENTJ","ISTJ","INFJ"};
	float MyNe = 28.4;
	float MyNi = 31.2;
	float MyTe = 18.0;
	float MyTi = 25.0;
	float MySe = 21.0;
	float MySi = 24.0;
	float MyFe = 22.0;
	float MyFi = 18.0;
	for (int i = 0; i < 54; i++)
	{
		types[i].id = id[i];
		types[i].NeFriend = NeF[i];
		types[i].NiFriend = NiF[i];
		types[i].TeFriend = TeF[i];
		types[i].TiFriend = TiF[i];
		types[i].SeFriend = SeF[i];
		types[i].SiFriend = SiF[i];
		types[i].FeFriend = FeF[i];
		types[i].FiFriend = FiF[i];
		types[i].FriendName = FriendName[i];
		types[i].Ptype = Ptype[i];
	}
	// cout << "ID\tDistance" << endl;
	for (int i = 0; i < 54; i++)
	{
		arr[i] = sqrt(pow(MyNe - types[i].NeFriend, 2) + pow(MyNi - types[i].NiFriend, 2) + pow(MyTe - types[i].TeFriend, 2) + pow(MyTi - types[i].TiFriend, 2) + pow(MySe - types[i].SeFriend, 2) + pow(MySi - types[i].SiFriend, 2) + pow(MyFe - types[i].FeFriend, 2) + pow(MyFi - types[i].FiFriend, 2));
		types[i].Distance = arr[i];
		// cout << types[i].id << "\t" << types[i].Distance << endl;
	}
	float min0 = arr[0];
	float min1 = arr[0];
	float min2 = arr[0];
	int index0 = 0;
	int index1 = 0;
	int index2 = 0;

	for (int i = 0; i < 54; i++)
	{
		if (arr[i] < min0)
		{
			min0 = arr[i];
			index0 = i;
		}
	}
	cout << "The First closest friend is " << types[index0].id << " with type " << types[index0].Ptype << " FriendName " << types[index0].FriendName << endl;
	// Find second closest friend
	for (int i = 0; i < 54; i++)
	{
		if (arr[i] < min1 && arr[i] != min0)
		{
			min1 = arr[i];
			index1 = i;
		}
	}
	cout << "The Second closest friend is " << types[index1].id << " with type " << types[index1].Ptype << " FriendName " << types[index1].FriendName << endl;
	// Find third closest friend
	for (int i = 0; i < 54; i++)
	{
		if (arr[i] < min2 && arr[i] != min0 && arr[i] != min1)
		{
			min2 = arr[i];
			index2 = i;
		}
	}
	cout << "The Third closest friend is " << types[index2].id << " with type " << types[index2].Ptype << " FriendName " << types[index2].FriendName << endl;

	string findMyType0 = types[index0].Ptype;
	string findMyType1 = types[index1].Ptype;
	string findMyType2 = types[index2].Ptype;

	if (findMyType0 == findMyType1 && findMyType1 == findMyType2)
	{
		cout << "Your friend have type : " << findMyType0 << endl;
	}
	else if (findMyType0 == findMyType1)
	{
		cout << "Your friend have type : " << findMyType0 << " and " << findMyType2 << endl;
	}
	else if (findMyType0 == findMyType2)
	{
		cout << "Your friend have type : " << findMyType0 << " and " << findMyType1 << endl;
	}
	else if (findMyType1 == findMyType2)
	{
		cout << "Your friend have type : " << findMyType1 << " and " << findMyType0 << endl;
	}
	else
	{
		cout << "Your friend have type : " << findMyType0 << ", " << findMyType1 << " and " << findMyType2 << endl;
	}

	char firstChar0 = findMyType0[0];
	char firstChar1 = findMyType1[0];
	char firstChar2 = findMyType2[0];
	char secondChar0 = findMyType0[1];
	char secondChar1 = findMyType1[1];
	char secondChar2 = findMyType2[1];
	char thirdChar0 = findMyType0[2];
	char thirdChar1 = findMyType1[2];
	char thirdChar2 = findMyType2[2];
	char fourthChar0 = findMyType0[3];
	char fourthChar1 = findMyType1[3];
	char fourthChar2 = findMyType2[3];

	if (firstChar0 == firstChar1 && firstChar1 == firstChar2)
	{
		cout << firstChar0 << endl;
	}
	else if (firstChar0 == firstChar1)
	{
		cout << firstChar0 << endl;
	}
	else if (firstChar1 == firstChar2)
	{
		cout << firstChar1 << endl;
	}
	else if (firstChar0 == firstChar2)
	{
		cout << firstChar0 << endl;
	}

	if (secondChar0 == secondChar1 && secondChar1 == secondChar2)
	{
		cout << secondChar0 << endl;
	}
	else if (secondChar0 == secondChar1)
	{
		cout << secondChar0 << endl;
	}
	else if (secondChar1 == secondChar2)
	{
		cout << secondChar1 << endl;
	}
	else if (secondChar0 == secondChar2)
	{
		cout << secondChar0 << endl;
	}

	if (thirdChar0 == thirdChar1 && thirdChar1 == thirdChar2)
	{
		cout << thirdChar0 << endl;
	}
	else if (thirdChar0 == thirdChar1)
	{
		cout << thirdChar0 << endl;
	}
	else if (thirdChar1 == thirdChar2)
	{
		cout << thirdChar1 << endl;
	}
	else if (thirdChar0 == thirdChar2)
	{
		cout << thirdChar0 << endl;
	}

	if (fourthChar0 == fourthChar1 && fourthChar1 == fourthChar2)
	{
		cout << fourthChar0 << endl;
	}
	else if (fourthChar0 == fourthChar1)
	{
		cout << fourthChar0 << endl;
	}
	else if (fourthChar1 == fourthChar2)
	{
		cout << fourthChar1 << endl;
	}
	else if (fourthChar0 == fourthChar2)
	{
		cout << fourthChar0 << endl;
	}
}