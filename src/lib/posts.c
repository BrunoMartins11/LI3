#include <stdlib.h>
#include <date.h>

typedef struct posts{	//esta struct tem campos de perguntas e respostas, 
						//para que consiga conter ambos, tornando possivel ter perguntas e respostas no mesmo array(por exemplo).	
	long postID;		
	char* postTitle;
	int postType; 		//1 -> pergunta, 2-> resposta
	long parentID; 		// 0 no caso de ser uma pergunta
	long score;
	struct date	data;
	long answerCount;
	long commentCount;
	char** tags;		//basicamente um array de strings. As tags sao strings.
	
}

