#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<ctime>
#include<numeric>
#include<fstream>
using namespace std;
class SpeechManager
{
public:
	//���캯��
	SpeechManager();
	//��ʾ�˵�
	void Show_Menu();
	//��ʼ������������
	void initSpeech();
	//����12��ѡ��
	void createSpeaker();
	//��ʼ����
	void StartSpeech();
	//��ǩ
	void chouqian();
	//����
	void speechContest();
	//���������¼
	void savescore();
	//��ȡ��¼
	void loadscore();
	//��ʾ����÷�
	void showsscore();
	//��������¼
	void clearscore();
	//��ʾ��������
	void showScore();
	//�˳��ݽ�����ϵͳ
	void Exitsystem();
	//��������
	~SpeechManager();
	//��Ա����
	//�����һ�ֱ���ѡ�ֱ������
	vector<int>v1;
	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;
	//ʤ��ǰ����ѡ���������
	vector<int>v3;
	//��ű���Լ���Ӧ�ľ���ѡ������
	map<int, Speaker>m_speaker;
	//��ű���������
	int m_Index;
	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool fileIsEmpty = 0;
	//��������¼������
	map<int, vector<string>>m_Record;
};