#include "typeExprTable.h"

int main(){
    
    char programname[201];

    grammar G;
    G.grammar_rules = (cell_node*)calloc(NO_OF_RULES,sizeof(cell_node));
    for(int  i = 0;i<NO_OF_RULES;i++)
    {
        (G.grammar_rules)[i].first_rhs = NULL;
        (G.grammar_rules)[i].last_rhs = NULL;
    }
    char grammarname[50] = "grammar.txt";
    readGrammar(grammarname,G.grammar_rules);


    printf("Enter program file: \n");
    scanf("%s",programname);
    tokenStream* head = (tokenStream*)calloc(1,sizeof(tokenStream)); 
    tokeniseSourcecode(programname,head);
    int choice;
    int fc[2];
    parseTree *t = calloc(1,sizeof(parseTree));
    typeExpressionTable T=calloc(1,sizeof(type_expression_table));
    do{
        
        printf("Please enter a choice(0-4): \n");
        scanf("%d",&choice);
       
        switch(choice){
            case 0: break;
            case 1:
                if(!fc[0]){
                    t = calloc(1,sizeof(parseTree));
                    createParseTree(t,head,G);
                    fc[0]=1;
                }
                else{
                    printf("Parse Tree already created!\n");
                }
                break;
            case 2:
                if(!fc[0]){
                    printf("Warning! Parse Tree not created! Creating...\n");
                    t = calloc(1,sizeof(parseTree));
                    createParseTree(t,head,G);
                    fc[0]=1;
                }
                if(!fc[1]){
                    traverseParseTree(t,  T);
                    fc[1]=1;
                }
                
                break;
            case 3:
                if(!fc[0]){
                    printf("Warning! Parse Tree not created! Creating...\n");
                    t = calloc(1,sizeof(parseTree));
                    createParseTree(t,head,G);
                    fc[0]=1;
                    
                }
                printParseTree(t);
                break;
            case 4:
                if(!fc[0]){
                    printf("Warning! Parse Tree not created! Creating...\n");
                    t = calloc(1,sizeof(parseTree));
                    createParseTree(t,head,G);
                    fc[0]=1;
                    
                }
                if(!fc[1]){
                    printf("Warning! Type Expression Table not created! Creating...\n");
                    traverseParseTree(t,  T);
                    fc[1]=1;
                    
                }
                printTypeExpressionTable(T);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=0);
}