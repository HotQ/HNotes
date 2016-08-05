#include "ncurses.h"
#include "mysql.h"

#include "hn_dbLogin.h"
#include "hn_mysqlOperation.h"


Status db_login(MYSQL *conn_ptr){

	char	user[50]="",
			password[50]="",
			password_verify[100]="";
	// start_color();
	// init_color(COLOR_BLACK, 0, 0, 0);
	// init_pair(1, COLOR_GREEN, COLOR_BLACK);


	printw("mysql user:\t");
	scanw("%s",user);

	printw("mysql password:\t");
	noecho();  
        scanw("%s",password);   
    echo();
	printw("\n");

	refresh();
        
    conn_ptr=mysql_init(NULL);
    conn_ptr = mysql_real_connect(conn_ptr, "localhost", user, password, NULL, 0, NULL, 0);

    char input_ch;

    if(conn_ptr){
    	attron(A_BOLD);
    	   printw("[ info  @%s]  Connect successfully!\n",user);
    	attroff(A_BOLD);
    	refresh();
    }else{
    	attron(A_BOLD);
    	   printw("[ info  @%s]  Fucked~\n",user);
    	attroff(A_BOLD);
    	refresh();
    	return Status_Forbidden;
    }


	if(mysql_query(conn_ptr, "use HNotes")){
		printw("[ query @%s]  Create database? [Y/n] :  ",user);refresh();
		scanw("%c",&input_ch);
		if(input_ch=='Y' || input_ch=='y' ){
            if(!mysql_query(conn_ptr, "create DATABASE HNotes;")){
            	//mysql_query(conn_ptr, "create table ;")
            	printw("[");    	
            	attron(COLOR_PAIR(1));
                attron(A_BOLD);
            	   printw("  OK");
            	attroff(COLOR_PAIR(1));
                attroff(A_BOLD);
            	printw("   @%s]  Create database already.\n",user);
            	mysql_query(conn_ptr, "use HNotes");
            	printw("[ info  @%s]  Enter database already.\n ",user);

            }

		}
		if(input_ch=='N' || input_ch=='n' ){
			    printw("[");
            	attron(COLOR_PAIR(2));
                attron(A_BOLD);
            	   printw("  NO");
            	attroff(COLOR_PAIR(2));
                attroff(A_BOLD);
            	printw("   @%s]  Refuse to create database.\n",user);
		}
		refresh();
	}else{
		attron(A_BOLD);
		printw("[ info  @%s]  Enter database already.\n ",user);
		attroff(A_BOLD);
	}

	refresh();
	//ShowQueryResult_Select(conn_ptr,"show databases;");
    mysql_query(conn_ptr,"use HNotes;"); 
    ShowQueryResult_Select(stdscr,conn_ptr,"select * from demo1;");



	return Status_OK;
    

}


