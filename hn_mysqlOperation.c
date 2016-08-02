#include <string.h>

#include "ncurses.h"
#include "mysql.h"

#include "hn_mysqlOperation.h"
#include "hn_memoryManager.h"

int width_scrs(char *src,int size){
    int i=0,width_scr=0;
    while(i < size){
        if(src[i]==-30  && src[i+1]==-128){
            width_scr++;
            i+=3;
        }else if(src[i]<0){
            width_scr+=2;
            i=i+3;
        }else{
            width_scr++;
            i++;
        }
    }
    return width_scr;
}


void ShowQueryResult_Select(MYSQL *conn_ptr,char * query){
    MYSQL_RES   *res_ptr;
    MYSQL_ROW    sqlrow;
    MYSQL_FIELD *sqlfield;
    
    int *field_max_length;

    int res, i, j,fNum;
    unsigned long rNum;	

    char ***res_select,tempStr[300];
    int **width_scr,
        **width_chr,
        strlenSqlrowJ;


    if (conn_ptr) {
        res = mysql_query(conn_ptr, query);//select * from db"); //
        if (res) {
            printw("SELECT error:%s\n",mysql_error(conn_ptr));
        } else {
            res_ptr = mysql_store_result(conn_ptr);             //
            if(res_ptr) {
                rNum = (unsigned long)mysql_num_rows(res_ptr);
                fNum = mysql_num_fields(res_ptr);
                

                printw("\n\n******************\n%lu Rows   %d Field\n******************\n\n",rNum,fNum);

                field_max_length =  (int *)malloc(sizeof(int)*fNum);RecordMalloc(sizeof(int)*fNum,"ShowQueryResult_Select  field_max_length");
                res_select =        (char***)malloc(sizeof(char**)*rNum);RecordMalloc(sizeof(char**)*rNum,"ShowQueryResult_Select  res_select");
                width_scr =         (int**)malloc(sizeof(int*)*rNum);RecordMalloc(sizeof(int*)*rNum,"ShowQueryResult_Select  width_scr");


                for(i=0;i<rNum;i++){
                    sqlrow = mysql_fetch_row(res_ptr);
                    res_select[i] = (char**)malloc(sizeof(char*)*fNum);sprintf(tempStr,"ShowQueryResult_Select  res_select[%d]",i);RecordMalloc(sizeof(char*)*fNum,tempStr);
                    width_scr[i] =  (int *)malloc(sizeof(int)*fNum);sprintf(tempStr,"ShowQueryResult_Select  width_scr[%d]",i);RecordMalloc(sizeof(int)*fNum,tempStr);

                    
                    for(j=0;j<fNum;j++){
                        strlenSqlrowJ = strlen(sqlrow[j]);
                        res_select[i][j] = (char*)malloc(sizeof(char)*(strlenSqlrowJ+1));sprintf(tempStr,"ShowQueryResult_Select  res_select[%d][%d]",i,j);RecordMalloc(sizeof(char)*(strlenSqlrowJ+1),tempStr);
                        strcpy(res_select[i][j],sqlrow[j]);
                        width_scr[i][j] = width_scrs(sqlrow[j],strlenSqlrowJ);
                        
                    }
                }




                for(j=0;j<fNum;j++){
                    field_max_length[j]=0;
                    for(i=0;i<rNum;i++){
                        if(field_max_length[j] < width_scr[i][j]  )
                            field_max_length[j] = width_scr[i][j];
                    }
                }


                printw("+");
                for(i=0;i<fNum;i++){
                    for(j=0;j<field_max_length[i]+2;j++){
                        printw("-");
                    }
                    printw("+");
                }
                printw("\n");

                int temp;
                for(i=0;i<rNum;i++){
                    printw("| ");
                    for(j=0;j<fNum;j++){
                        temp = field_max_length[j]- width_scr[i][j];
                        printw("%s%*s| ",res_select[i][j],temp+1," ");
                        sprintf(tempStr,"ShowQueryResult_Select  res_select[%d][%d]",i,j);RecordFree(sizeof(char)*(strlen(res_select[i][j])+1),tempStr);
                        free(res_select[i][j]);
                    }
                    printw("\n");

                    free(res_select[i]);    sprintf(tempStr,"ShowQueryResult_Select  res_select[%d]",i);RecordFree(sizeof(char*)*fNum,tempStr);
                    free(width_scr[i]);     sprintf(tempStr,"ShowQueryResult_Select  width_scr[%d]",i);RecordFree(sizeof(int)*fNum,tempStr);

                }
                
                printw("+");
                for(i=0;i<fNum;i++){
                    for(j=0;j<field_max_length[i]+2;j++){
                        printw("-");
                    }
                    printw("+");
                    
                }
                printw("\n");

                free(field_max_length); RecordFree(sizeof(int)*fNum,"ShowQueryResult_Select  field_max_length");
                free(res_select);RecordFree(sizeof(char**)*rNum,"ShowQueryResult_Select  res_select");
                free(width_scr);RecordFree(sizeof(int*)*rNum,"ShowQueryResult_Select  width_scr");

                if (mysql_errno(conn_ptr)) {
                    //fprintf(stderr,"Retrive error:s\n",mysql_error(conn_ptr));
                }
            }
            refresh();
            mysql_free_result(res_ptr);
        }
    }
}