#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<string>

using namespace std;
SYSTEMTIME sys;

//��ʾ����
const string title="���Գ���";//����
const string ibate="sv1.3.4",t_cx="2024.04.12 20:00";//��������
string set_link="items/set.ini";//��������

//��������
string bate,t_day,t_time,made_by,made_co;//��������
int gold=6;//����
int ten=10;//ʮ������
int card=8,page=1;//��ǰѡ��
int all=0,res=0;//��������,��פ��
bool resp[300];//��פ�ж�
string from[300],name[300],five[300],four[300][3];//��������
int mfive=0,mfour=0,mthree=0;//ͨ������
string afive[10],afour[150],athree[50];//ͨ������
bool first=true;//��������

//�鿨��¼
bool big=false;//���׻���
int small=1;//����ͳ��
int alt=0,now=0;//ͳ��
string history[100000],level[100000];//�洢

//������
int ads_max=3;
string ads[20]= {"���¸��£���������ʾ",\
                 "���λ����!!!",\
                 "��'(?)_�ߧ�*?(����ε���)"\
                };

//������
void ads_show();
void save();

int main () {
	//��ʼ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	SetConsoleTitle("Main Design Project");
	system("cls");
	//����
	if (first==true) {
		ifstream ain("items/ads.ini");//������
		int ads_plus=0;
		ain>>ads_plus;
		if (ads_plus>0&&(ads_plus+ads_max)<=20) for (int ls=0; ls!=ads_plus; ls++,ads_max++) ain>>ads[ads_max];
		ain.close();
		ifstream tin("items/temp.ini");//������ʱ�ļ�
		tin>>page>>card>>gold>>ten;
		tin>>set_link;
		tin.close();
		ifstream fin(set_link);//��������
		fin>>made_by>>made_co>>bate>>t_day>>t_time;
		fin>>mfive;
		for (int ls=0; ls!=mfive; ls++) {//����
			fin>>afive[ls];
		}
		fin>>mfour;
		for (int ls=0; ls!=mfour; ls++) {//����
			fin>>afour[ls];
		}
		fin>>mthree;
		for (int ls=0; ls!=mthree; ls++) {//����
			fin>>athree[ls];
		}
		fin>>all>>res;
		for (int ls=0; ls!=res; ls++) {//���볣פ
			int temp=0;
			fin>>temp;
			resp[temp]=true;
		}
		for (int ls=1; ls!=all+1; ls++) {//���뿨��
			fin>>from[ls]>>name[ls]>>five[ls]>>four[ls][0]>>four[ls][1]>>four[ls][2];
		}
		//У��
		if (made_by=="\0") {	//ԭ�����ļ�ʧЧ
			set_link="items/set.ini";
			save();
			main();
		}
		bool wrong=false;
		if (card<1||card>all) wrong=true;
		if (page<1||page>(all-1)/9+1) wrong=true;
		if (gold<1||gold>1000) wrong=true;
		if (ten<1||ten>10000) wrong=true;
		if (wrong==true) {
			int tcin[4]= {1,1,6,10};
			for (int ls=0; ls!=4; ls++) fin>>tcin[ls];
			page=tcin[0],card=tcin[1],gold=tcin[2],ten=tcin[3];
			save();
			cout<<"[#�����޸������ļ�]"<<endl;
		}
		fin.close();
		first=false;
	}
	//��ʾ
	cout<<"��"<<title<<"���鿨ģ����"<<endl;
	cout<<"������: ���"<<endl;
	cout<<"���ذ汾: "<<bate<<endl;
	ads_show();
	cout<<"--------------------------------------"<<endl;
	cout<<from[card]<<endl;
	if (resp[card]==false) cout<<"�޶�";
	else cout<<"��פ";
	cout<<"-"<<name[card]<<endl;
	cout<<"�ѳ�:"<<now<<"��"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"���� UP������Ϊ:"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<" S "<<five[card]<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	cout<<"���� UP������Ϊ:"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	for (int ls=0; ls!=3; ls++) cout<<" R "<<four[card][ls]<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	cout<<"--------------------------------------"<<endl;
	cout<<">E.���γ�ȡ"<<endl;
	cout<<">Q.��γ�ȡ"<<endl;
	cout<<">A.�鿴��¼"<<endl;
	cout<<">D.�������"<<endl;
	cout<<">S.��������"<<endl;
	cout<<"--------------------------------------"<<endl;
	char choose=getch();
	system("cls");
	if (choose=='S'||choose=='s') {
		cout<<"��"<<title<<"���鿨ģ����"<<endl;
		cout<<"������: ���"<<endl;
		cout<<"����汾: "<<ibate<<endl;
		ads_show();
		cout<<"--------------------------------------"<<endl;
		cout<<"           �����ڳ����ļ���"<<endl;
		cout<<"����Ȩ��: ���"<<endl;
		cout<<"��Ȩ����: XiCi.co"<<endl;
		cout<<"����汾: "<<ibate<<endl;
		cout<<"�������ʱ��: "<<t_cx<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"           �����ڿ����ļ���"<<endl;
		cout<<"����Ȩ��: "<<made_by<<endl;
		cout<<"��Ȩ����: "<<made_co<<".co"<<endl;
		cout<<"���ذ汾: "<<bate<<endl;
		cout<<"���ظ���ʱ��: "<<t_day<<" "<<t_time<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<">��S�鿴��������"<<endl;
		cout<<">��X���������ļ�"<<endl;
		cout<<">��������˳���ҳ��"<<endl;
		cout<<"--------------------------------------"<<endl;
		choose=getch();
		if (choose=='X'||choose=='x') {
jset:
			//����
			int i=0;
			int j=0;
			char str[50] = "items/";
			char path[55][50]= {};
			char musicPath[20]="items\\set*.ini";
			WIN32_FIND_DATA findFileData;
			//��ȡ
			HANDLE hFind=FindFirstFile(musicPath,&findFileData);
			//��ʾ
			system("cls");
			cout<<"��"<<title<<"���鿨ģ����"<<endl;
			cout<<"������: ���"<<endl;
			cout<<"����汾: "<<ibate<<endl;
			ads_show();
			cout<<"--------------------------------------"<<endl;
			if(hFind==INVALID_HANDLE_VALUE) {
				cout<<"[Error]'items\\'·����δ��ѯ�������ļ�."<<endl;
				main();
			} else {
				cout<<"�����ļ��б�"<<endl;
				while(1) {
					if(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
					} else {
						memcpy(str+6, findFileData.cFileName, strlen(findFileData.cFileName));
						sprintf(path[i],str);
						i++;
						printf("%3d : %s\n",i,findFileData.cFileName);
					}
					if(!FindNextFile(hFind,&findFileData))	break;
				}
				FindClose(hFind);
			}
			cout<<"--------------------------------------"<<endl;
			cout<<"������Ŷ�ȡ�����ļ���";
			cin>>j;
			while('\n'!=getchar());
			if(j<1||j>i) cout<<"�Ƿ����룡"<<endl;
			else {
				set_link=path[j-1];
				cout<<endl<<"�����ļ�'"<<set_link<<"'��ȡ�ɹ���"<<endl;
				save();
				first=true;
				Sleep(1500);
			}
			main();
		} else if (choose=='S'||choose=='s') {
			//����
			int max[200],npage=1;
			string beta[200],day[200],time[200],out[200][15];
			//��ȡ
			ifstream fin("items/news.ini");
			fin>>max[0];
			for (int ls=1; ls<=max[0]; ls++) {
				fin>>beta[ls]>>day[ls]>>time[ls]>>max[ls];
				for (int cs=0; cs<=max[ls]; cs++) {
					getline(fin,out[ls][cs]);
				}
			}
			fin.close();
			//��ʾ
			while (true) {
				system("cls");
				cout<<beta[npage]<<"����˵��("<<npage<<"/"<<max[0]<<")"<<endl;
				cout<<"����ʱ��:"<<day[npage]<<" "<<time[npage]<<endl;
				cout<<"--------------------------------------"<<endl;
				for (int ls=1; ls<=max[npage]; ls++) {
					cout<<out[npage][ls]<<endl;
				}
				cout<<"--------------------------------------"<<endl;
				cout<<">��'A'��'D'�л�ҳ��"<<endl;
				cout<<">��������˳���ҳ��..."<<endl;
				choose=getch();
				if (choose=='A'||choose=='a') {
					if (npage>1) npage-=1;
				} else if (choose=='D'||choose=='d') {
					if (npage<max[0]) npage+=1;
				} else main();
			}
		}
	} else if (choose=='A'||choose=='a') {//�鿴��¼
		cout<<"��ʷ��¼"<<endl;
		cout<<"--------------------------------------"<<endl;
		int tj=1,S=0,R=0,A=0;
		if (alt<=0) cout<<"��ʱ��û�г鿨��¼Ŷ����ȥ�鿨�ɡ�"<<endl;
		for (int ls=0; ls!=alt; ls++) {
			if (level[ls]=="S") {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
				S+=1;
			} else if (level[ls]=="R") {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
				R+=1;
			} else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
				A+=1;
			}
			if (tj<10) cout<<"0";
			cout<<tj<<" "<<level[ls]<<" "<<history[ls]<<endl;
			if (level[ls]=="S") {
				tj=0;
				Sleep(1500);
			}
			tj+=1;
			Sleep(20);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
		cout<<"--------------------------------------"<<endl;
		cout<<"���Ƴ���:"<<alt<<"��"<<endl;
		cout<<"����:"<<S<<"��"<<endl;
		cout<<"����:"<<R<<"��"<<endl;
		cout<<"����:"<<A<<"��"<<endl;
		Sleep(9000);
		main();
	} else if (choose=='D'||choose=='d') {//�������
		cout<<"�������"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"����:"<<alt<<"��"<<endl;
		if (big==true) cout<<"[��";
		else cout<<"[С";
		cout<<"����]�ѵ�:"<<now<<"��"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<">Q.�˳�����"<<endl;
		cout<<">I.������¼"<<endl;
		cout<<">O.���㱣��"<<endl;
		cout<<">P.��ռ�¼"<<endl;
		cout<<">J.��ȡ����"<<endl;
		cout<<">K.�޸ĸ���"<<endl;
		cout<<">L.�л�����"<<endl;
		cout<<"--------------------------------------"<<endl;
		choose=getch();
		system("cls");
		if (choose=='Q') { //�˳�����
			save();
			exit(0);
		} else if (choose=='I') {//������¼
			int best=0,R=0,S=0,A=0;
			if (alt!=0) {
				ofstream fout("history.txt",ios::app);
				GetLocalTime(&sys);
				fout<<sys.wYear<<"/"<<sys.wMonth<<"/"<<sys.wDay<<" "<<sys.wHour<<":"<<sys.wMinute<<":"<<sys.wSecond;
				fout<<" �ĳ鿨��¼:"<<endl;
				fout<<"-------------------------"<<endl;
				if (alt<=0) cout<<"��ʱ��û�г鿨��¼Ŷqaq��"<<endl;
				for (int ls=0; ls!=alt; ls++) {
					best+=1;
					if (level[ls]=="S") S+=1;
					if (level[ls]=="R") R+=1;
					if (level[ls]=="A") A+=1;
					if (best<10) fout<<"0";
					fout<<best<<" "<<level[ls]<<" "<<history[ls]<<endl;
					if (level[ls]=="S") best=0;
				}
				fout<<"-------------------------"<<endl;
				fout<<"���Ƴ���:"<<alt<<"��"<<endl;
				fout<<"����:"<<S<<"��"<<endl;
				fout<<"����:"<<R<<"��"<<endl;
				fout<<"����:"<<A<<"��"<<endl;
				fout<<"--------------------------------------"<<endl;
				cout<<endl;
				fout.close();
			} else {
				MessageBox(NULL,"���޳鿨��¼���Ե���","��ʾ",MB_OK+16);
			}
			main();
		} else if (choose=='O') {//���㱣��
			if (MessageBox(NULL,"ȷ��Ҫ���㱣����","��ʾ",MB_YESNO+64)==6) {
				now=0;
				big=false;
				small=0;
			}
			main();
		} else if (choose=='P') {//��ռ�¼
			if (MessageBox(NULL,"ȷ��Ҫ��ռ�¼��","��ʾ",MB_YESNO+64)==6) {
				alt=0,now=0;
				big=false;
				small=0;
			}
			main();
		} else if (choose=='J') {//�޸Ĵ���
			cout<<"��γ�ȡ"<<endl;
			cout<<"--------------------------------------"<<endl;
			cout<<"��ȡ����(��ѡ��:1~1000[Ĭ��:10]):";
			cin>>ten;
			if(ten<1||ten>1000) ten=10;
			save();
			main();
		} else if (choose=='K') {//�޸ĸ���
			cout<<"�޸ĸ���"<<endl;
			cout<<"--------------------------------------"<<endl;
			cout<<"��ǰ������:"<<gold<<endl;
			cout<<"�޸ĳ�����(0-1000[Ĭ��:6]):";
			cin>>gold;
			if (gold<0||gold>1000) gold=6;
			save();
			main();
		} else if (choose=='L') {//�����л�
			bool tch[10]= {false};
			while (true) {
				system("cls");
				cout<<"�����л�"<<endl;
				cout<<"--------------------------------------"<<endl;
				for (int ls=1; ls!=10; ls++) {
					if(name[(page-1)*9+ls]!="\0"&&((page-1)*9+ls)<=all) {
						cout<<ls<<".��"<<name[(page-1)*9+ls]<<"��"<<endl;
						cout<<" >�ɻ��: ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
						cout<<five[(page-1)*9+ls]<<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
						tch[(page-1)*9+ls]=true;
					}
				}
				cout<<"--------------------------------------"<<endl;
				if (all/9+1>=10) cout<<" A.��ҳ         P"<<page<<"/"<<(all-1)/9+1<<"         ��ҳ.D"<<endl;
				else cout<<" A.��ҳ          P"<<page<<"/"<<(all-1)/9+1<<"          ��ҳ.D"<<endl;
				cout<<"--------------------------------------"<<endl;
				choose=getch();
				if (choose!='A'&&choose!='D'&&(choose<'1'||choose>'9')) {
					main();
				} else if (choose=='A'&&page>1) {
					page-=1;
					save();
				} else if (choose=='D'&&page<(all-1)/9+1) {
					page+=1;
					save();
				} else if (choose>='1'&&choose<='9') {
					if (tch[(page-1)*9+choose-'0']==true) {//У�鿨���Ƿ����
						card=(page-1)*9+choose-'0';
						save();
						main();
					}
				}
			}
		} else main();
	} else if (choose=='E'||choose=='Q') {//�鿨
		int again=1;
		if (choose=='Q') again=ten;
		while (again!=0) {
			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			mt19937 generator (seed);
			int ls1=generator()%1000+1;
			int pro=gold;//74������
			if (now>=74) pro=6+(60*(now-73));//74�鼰����
			int tro=949-pro;
			small+=1;
			if (small==9) tro=439-pro;
			if (small>=10) tro=0;
			if (ls1<=pro) {//����
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
				unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
				mt19937 generator (seed);
				int ls2=generator()%2+1;
				now=-1;
				level[alt]="S";
				if (ls2==1&&big==false) {//����
					unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
					mt19937 generator (seed);
					int ls3=generator()%mfive;
					big=true;
					history[alt]=afive[ls3];
				} else {//û��
					big=false;
					history[alt]=five[card];
				}
			} else if (ls1<=tro) {//����
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
				unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
				mt19937 generator (seed);
				int ls2=generator()%mthree;
				level[alt]="A";
				history[alt]=athree[ls2];
			} else {//����
				small=0;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
				unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
				mt19937 generator (seed);
				int ls2=generator()%2+1;
				level[alt]="R";
				if (ls2==1) {//����
					unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
					mt19937 generator (seed);
					int ls3=generator()%mfour;
					history[alt]=afour[ls3];
				} else {//û��
					unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
					mt19937 generator (seed);
					int ls3=generator()%3;
					history[alt]=four[card][ls3];
				}
			}
			cout<<level[alt]<<" "<<history[alt]<<endl;
			alt+=1;
			now+=1;
			again-=1;
			if (choose=='Q') Sleep(20);
		}
		if (choose=='E') Sleep(200);
		else Sleep(950);
		main();
	}
	main();
	return 0;
}

//������

void ads_show() {
	//������
	if (ads_max>0) {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		mt19937 generator (seed);
		int ads_no=generator()%ads_max;
		cout<<"#"<<ads[ads_no]<<endl;
	}
}

void save() {
	//����
	ofstream fout("items/temp.ini");
	fout<<page<<" "<<card<<" "<<gold<<" "<<ten<<endl;
	fout<<set_link;
	fout.close();
}
