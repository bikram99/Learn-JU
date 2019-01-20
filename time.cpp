#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<time.h>
using namespace std;

class time_
{
    //Class to store the time provided by the user .
    
    string hour;
    string minutes;
    string seconds;
    
    public:
    int flag_time,flag_ap;
    time_()
    {
        flag_time=0;
        flag_ap =0;
        hour="";
        minutes="";
        seconds="";
       }
    
    void input24hour(string time_24)
    {
        hour=hour + time_24.substr(0,2);
        minutes=minutes + time_24.substr(2,2);
        
        seconds=seconds + time_24.substr(4,2);
        if(stoi(hour)>23 ||stoi(minutes)>59||stoi(seconds)>59)
            {
                cout<<"Error time";exit(0);
                
                }
        else
        {
        cout<<"The time is in 24 hour format\n";
        cout<<hour<<":"<<minutes<<":"<<seconds<<"\n";
        flag_time=0;}
        
    }
    
    void inputAM_PM(string time_ap,int flag)
    {
        hour=hour + time_ap.substr(0,2);
        minutes=minutes + time_ap.substr(2,2);
        seconds=seconds + time_ap.substr(4,2);
        
        if(stoi(hour)>12 ||stoi(minutes)>59||stoi(seconds)>59)
          {
            cout<<"Error time";
            exit(0);
            }
       else
       { 
        cout<<"The time is in AM/PM format\n";
        cout<<hour<<":"<<minutes<<":"<<seconds;
        if(flag==0)
        {
            cout<<"AM\n";
            flag_ap=0;
            }
        else 
        {
            cout<<"PM\n";
            flag_ap=1;
        }
        flag_time=1;
        }
            
    }
    
    void add_minutes(int minute)
    {
        int hours = minute/60;
        int in_minute = minute%60;
        hours = stoi(hour) + hours;
        in_minute = stoi(minutes) + in_minute;
        if(in_minute>=60)
           {
             hours=hours+(in_minute/60);
             in_minute= in_minute%60;
            }
        if(flag_time==0)
        {
            hours = hours%24;
        }
        else
        {   
            if(flag_ap==0 && hours>12)
            {
                hours=hours%12;
                flag_ap=1;
            }
            else if(flag_ap==1 && hours>=12)
            {
                hours=hours%12;
                flag_ap=0;
             }
             
        }
        
        hour = to_string(hours);
        minutes = to_string(in_minute);
        
        if(flag_time==0)
            cout<<hour<<":"<<minutes<<":"<<seconds<<"\n";
        else
        {
            cout<<hour<<":"<<minutes<<":"<<seconds;
            if(flag_ap==0)
                cout<<"AM";
            else
                cout<<"PM";
         }
    }

    void compare_time()
    {
	    time_t now ;
	    time(&now);
	    tm *ltm = localtime(&now);
	    int hour_sys =  1+ ltm->tm_hour;
	    int minute_sys = 1+ ltm->tm_min;
	    int second_sys = 1+ ltm->tm_sec;

		 int time_sys = hour_sys*3600 +minute_sys*60 + second_sys;


	    if(flag_time==0)
	   {
		   
		   int time_now = stoi(hour)*3600 + stoi(minutes)*60 + stoi(seconds);

		   if(time_sys>time_now)
			   cout<<"System time is greater.\n";
		   else if(time_sys<time_now)
			   cout<<"System time is smaller.\n";
		   else
			   cout<<"The times are equal\n";
	}
	    else if (flag_time==1)
	    {
		    if(flag_ap==0)
		    {
			   int time_now = (stoi(hour)%12)*3600 + stoi(minutes)*60 +stoi(seconds);

			 if(time_sys>time_now)
			   cout<<"System time is greater.\n";
		   else if(time_sys<time_now)
			   cout<<"System time is smaller.\n";
		   else
			   cout<<"The times are equal\n";
		}
		    else
		    {

			int time_now = (stoi(hour)%12)*3600 + stoi(minutes)*60 +stoi(seconds);
			time_now+=12*3600;

			if(time_sys>time_now)
			   cout<<"System time is greater.\n";
		   else if(time_sys<time_now)
			   cout<<"System time is smaller.\n";
		   else
			   cout<<"The times are equal\n";
		}
	    }

    }






	
    
};
        
        
        
        
int main()
{
    class time_ t;
    string time,time1;
    int flag,check;
    time1="";
    cout<<"Enter the time\n";
    cin>>time;
    if(time.length()==8)
    {
        for(int i=0;i<time.length();i++)
        {
            if((time[i]>='0'&&time[i]<='9')|| time[i]==':')
            {
                if(time[i]>='0'&&time[i]<='9')
                {
                    time1= time1+ time.substr(i,1);
                }
                }
            
            
            else 
            {
                cout<<"Invalid Format\n";
                break;exit(0);
            }
            }
         
         check=0;
     }
     else if(time.length()==10)
     {
        for(int i=0;i<time.length()-2;i++)
        {
            if((time[i]>='0'&&time[i]<='9')|| time[i]==':')
            {   
                
                if(time[i]>='0'&&time[i]<='9')
                {
                    time1= time1+ time.substr(i,1);
                }
            }
            else 
            {
                cout<<"Invalid Format\n";
                break;
                exit(0);
            }
        if(!(time.substr(8,2)).compare("am")) 
            flag=0;
        else if(!(time.substr(8,2)).compare("pm"))
            flag=1;
        check=1;
      }
      }
      else
      {
        cout<<"Invalid format";exit(0);}
      
      if(check==0)
        t.input24hour(time1);
      else if(check==1)
        t.inputAM_PM(time1,flag);

      cout<<"1.Add minutes to time entered\n";
      cout<<"2.Compare with system time\n";

      int choice;
      cin>>choice;

      switch(choice)
      {
	      case 1: int minutes;
      			cout<<"Enter number of minutes to add\n";
     			 cin>>minutes;
     			 t.add_minutes(minutes);break;

        
	      case 2:	t.compare_time();break;
		default : cout<<"Wrong choice!\n";
	}

        
      
        
   
 return 0;
}
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
