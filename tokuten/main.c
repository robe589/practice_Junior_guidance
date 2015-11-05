#include<stdio.h>

struct Human
{
	char name[50];//名前
	int score[5];//5教科の得点
};

struct Analysis_data
{
	int max_score;
	int min_score;
	int average_score;
};

//教科番号用定数
enum subject
{
	JAPAN_LANGUAGE,
	MATHEMATICS,
	SOCIETY,
	ENGLISH_LANGUAGE,
	SCIENCE,
};

//プロトタイプ宣言
void read_score_from_file(struct Human *human);
void analysis_score_each_personal(struct Human *human,struct Analysis_data *analysis_data);
void analysis_score_each_subject(struct Human *human,struct Analysis_data *analysis_data);
int find_max_score(int *);
int find_min_score(int *);
double find_average_score(int *);

int main()
{
	struct Human human[5];//5人分の点数を格納
	struct Analysis_data analysis_personal_data;
	struct Analysis_data analysis_subject_data;

	//ファイルから得点を取得して、構造体に格納
	read_score_from_file(human);
	//個人ごとの5教科の平均点、最大得点、最小得点を求める
	analysis_score_each_personal(human,&analysis_personal_data);
	//教科ごとの5教科の平均点、最大得点、最小得点を求める
	analysis_score_each_subject(human,&analysis_subject_data);

	return 0;
}

void read_score_from_file(struct Human *human)
{
}

void analysis_score_each_personal(struct Human *human,struct Analysis_data *analysis_data)
{
	int max_score,min_score;
	double average_score;

	max_score=find_max_score(human[0].score);
	min_score=find_min_score(human[0].score);
	average_score=find_min_score(human[0].score);

	return;
}

int find_max_score(int *score)
{
	return 0;
}
int find_min_score(int *score)
{
	return 0;
}

double find_average_score(int *score)
{
	return 0;
}

void analysis_score_each_subject(struct Human *human,struct Analysis_data *analysis_data)
{

	return;
}

