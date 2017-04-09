#include<stdio.h>
#include<mysql/mysql.h>

int main(){
    MYSQL *info;
    MYSQL_RES *res_ptr;
    MYSQL_FIELD *field;
    MYSQL_ROW result_row;
    unsigned short i,j;
    int row,column;
    char *from;
    from = "select * from userinfo;";

    info = mysql_init(NULL);
    info = mysql_real_connect(info,NULL,NULL,"","MirrorChat",0,NULL,0);
    mysql_query(info,from);
    res_ptr =  mysql_store_result(info);
    column = mysql_num_fields(res_ptr);
    row = mysql_num_rows(res_ptr);
    printf("%d %d\n",column,row);
    while(field = mysql_fetch_field(res_ptr)){
        printf("%-20s",field->name);
    }
    printf("\n");

    for(i = 0;i < row;i++){
        result_row = mysql_fetch_row(res_ptr);
        for(j = 0;j < column;j++){
            printf("%-20s",result_row[j]);
        }
        printf("\n");
    }

    mysql_close(info);
    return 0;
}
