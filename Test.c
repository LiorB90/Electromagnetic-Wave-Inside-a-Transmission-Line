#include <ansi_c.h>
#include <math.h>
#include <cvirte.h>		
#include <userint.h>  
#include <analysis.h> 
#include "toolbox.h"
#include "Test.h"
#define e 2.71828   
#define  c 300000000
#define  n 0.000000001
#define  M 1000000
#define  G 1000000000 
static int panelHandle,panelHandle2,panelHandle1,panelHandle3,d,k,flag,flag1;
static  float vl, il, Er,vg,l,length,z0,rg,zg;
static  float v_pos1,v_neg1,v_neg_t0,A[3],vph;
static  float il0;
static float T, tao, dt=0.01,i,j,cp,rl;
static float vlv[150*M],ilv[150*M];



void plot1()
{
	
 	SetCtrlVal (panelHandle, PANEL_Go, 0);
    SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);
	SetCtrlVal (panelHandle3, PANEL_4_Go, 0);
	SetCtrlAttribute (panelHandle3, PANEL_4_TIMER, ATTR_ENABLED, 0);
    DisplayPanel (panelHandle2);
    DeleteGraphPlot (panelHandle2, PANEL_2_GRAPH, -1, VAL_DELAYED_DRAW);
    DeleteGraphPlot (panelHandle2, PANEL_2_GRAPH_2, -1, VAL_DELAYED_DRAW);
    PlotWaveform (panelHandle2, PANEL_2_GRAPH_2, vlv, d, VAL_FLOAT, 1.0, 0.0, 0.0, 0.1, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
    PlotWaveform (panelHandle2, PANEL_2_GRAPH, ilv, d, VAL_FLOAT, 1.0, 0.0, 0.0, 0.1, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_GREEN);
    SetCtrlAttribute (panelHandle2, PANEL_2_Cursor, ATTR_ENABLED, 1);	
}
 /*******************************************************************************************/ 
void reset1()
{
	SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);
	z0=0;
	zg=0;
	vph=0;
	T=0;	
	tao =0;
	v_pos1=0;
	vl=0;
	il=0;
	Er=0;
	for(k=0;k<d;k++)
	{
		vlv[k]=0;
		ilv[k]=0;
	}
	k=0;
	d=0;
	i=0;
	j=0;
	SetCtrlVal (panelHandle, PANEL_Vl, 0.0);
	SetCtrlVal (panelHandle, PANEL_Il, 0.0);
	SetCtrlVal (panelHandle,  PANEL_V_Pos,-length);
	SetCtrlVal (panelHandle, PANEL_Go, 0);
	CanvasClear (panelHandle, PANEL_CANVAS, VAL_ENTIRE_OBJECT);
}
 /*******************************************************************************************/
void reset2()
{
	SetCtrlAttribute (panelHandle3, PANEL_4_TIMER, ATTR_ENABLED, 0);
	z0=0;
	zg=0;
	vph=0;
	rg=0;
	rl=0;
	T=0;
	v_pos1=0;
	vl=0;
	il=0;
	Er=0;
	flag=0;
	for(k=0;k<d;k++)
	{
		vlv[k]=0;
		ilv[k]=0;
	}
	k=0;
	d=0;
	i=0;
	j=0;
	SetCtrlVal (panelHandle3, PANEL_4_Vl, 0.0);
	SetCtrlVal (panelHandle3, PANEL_4_Il, 0.0);
	SetCtrlVal (panelHandle3, PANEL_4_V_Pos,-length);
	SetCtrlVal (panelHandle3, PANEL_4_Go, 0);
	CanvasClear (panelHandle3,PANEL_4_CANVAS, VAL_ENTIRE_OBJECT);	
	
}
 /*******************************************************************************************/ 
int main (int argc, char *argv[])
{

	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "Test.uir", PANEL)) < 0)
		return -1;
	if ((panelHandle1 = LoadPanel (0, "Test.uir", PANEL_3)) < 0)
		return -1;
	if ((panelHandle2 = LoadPanel (0, "Test.uir", PANEL_2)) < 0)
		return -1;
	if ((panelHandle3 = LoadPanel (0, "Test.uir", PANEL_4)) < 0)
		return -1;
	
	
	DisplayPanel (panelHandle1);
	RunUserInterface ();

	DiscardPanel (panelHandle); 
	DiscardPanel (panelHandle1); 
	DiscardPanel (panelHandle2);
	DiscardPanel (panelHandle3);
	
	return 0;
}
/*******************************************************************************************/

int CVICALLBACK Resistor (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 DisplayPanel (panelHandle3);
			   HidePanel  (panelHandle1);
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK Diff (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			   DisplayPanel (panelHandle);
			   HidePanel  (panelHandle1);
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK Quit (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK Quit1 (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel (panelHandle); 
			reset1();
			DisplayPanel (panelHandle1);
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK Quit2 (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute (panelHandle2, PANEL_2_Cursor, ATTR_ENABLED, 0); 
			 HidePanel (panelHandle2);
			 
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK Quit3 (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 HidePanel (panelHandle3); 
			reset2();
			DisplayPanel (panelHandle1);
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK RST (int panel, int control, int event,
					 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			reset1();
			reset2();
		
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK LENGTH (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{   float t;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_Longtitude, &length);
			t=length/0.3;
			if(t-(int)t!=0)
				length=0.6;  
			SetCtrlVal (panelHandle, PANEL_V_Pos, -length);
			SetCtrlVal (panelHandle, PANEL_Longtitude, length);
			SetCtrlAttribute (panelHandle, PANEL_V_Pos, ATTR_MIN_VALUE, -length);
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK LENGTH1 (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{   float t;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle3, PANEL_4_Longtitude, &length);
			t=length/0.3;
			if(t-(int)t!=0)
				length=0.6;  
			SetCtrlVal (panelHandle3, PANEL_4_V_Pos, -length);
			SetCtrlVal (panelHandle3, PANEL_4_Longtitude, length);
			SetCtrlAttribute (panelHandle3, PANEL_4_V_Pos, ATTR_MIN_VALUE, -length);
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK PLOT (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT: 
			plot1();
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK Go1 (int panel, int control, int event,
					void *callbackData, int eventData1, int eventData2)
{
	static int x;
	
	switch (event)
	{
		case EVENT_COMMIT:
			if(length ==0)
			{
				GetCtrlVal (panelHandle, PANEL_Longtitude, &length);
				SetCtrlVal (panelHandle, PANEL_V_Pos, -length);
				SetCtrlVal (panelHandle, PANEL_Longtitude, length);
				SetCtrlAttribute (panelHandle, PANEL_V_Pos, ATTR_MIN_VALUE, -length);
			}
			GetCtrlVal (panelHandle, PANEL_Go, &x);
			GetCtrlVal (panelHandle, PANEL_RG, &zg);
			SetCtrlVal (panelHandle, PANEL_Z0, zg);
			GetCtrlVal (panelHandle, PANEL_VSource, &vg);
			GetCtrlVal (panelHandle, PANEL_L, &l);
			GetCtrlVal (panelHandle, PANEL_Er, &Er);
			GetCtrlVal (panelHandle, PANEL_Check_Point, &cp);
			if(cp>length)
			{
				cp=0;
				SetCtrlVal (panelHandle, PANEL_Check_Point, 0.0);
			}
			z0=zg;
			vph=c/sqrt(Er);
			T=(length/(vph))*G;	
			tao =(l/z0);
			v_pos1=(z0/(z0+zg))*vg;
			SetCtrlVal (panelHandle, PANEL_Vph, vph);  
			SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, x);
			SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_INTERVAL, dt);
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK TIMER1 (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{ 
	static int t; 
	Point a,b;
	int q=i*100;
	switch (event)
	{
		case EVENT_TIMER_TICK:
			
			t=floor(i) ;
			SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_COLOR, VAL_RED);
		
			a=MakePoint(i*135/((length/0.6)*(sqrt(Er))),10);
			b=MakePoint(i*135/((length/0.6)*(sqrt(Er))),297);
			if(t<T)
			{
				if(q%10==0 || a.x==273)
					CanvasDrawLine (panelHandle, PANEL_CANVAS, a,b);
				if(cp>0 && i>=T-(((cp*10)/(length/0.6))/6)*T)
				{
					vl=v_pos1;
					il=(v_pos1/z0);
					SetCtrlVal (panelHandle, PANEL_Vl, vl);
					SetCtrlVal (panelHandle, PANEL_Il, il*1000);
					
				}
			}
			if(t>= T && i!=0)
			{
				q=j*100+5;
				if(t==T && i<=(T+0.01))  //start cond
				{   
					a=MakePoint(273,10);
					b=MakePoint(273,297);
					CanvasDrawLine (panelHandle, PANEL_CANVAS, a,b); 
					v_neg_t0= v_pos1-il0*z0  ;
					A[0]=v_neg_t0+v_pos1;
					if(cp==0)
					{
						vl=v_pos1;
						il=(v_pos1/z0);
					}
				}
				SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_COLOR, VAL_GREEN);
				a=MakePoint(273-j*135/((length/0.6)*(sqrt(Er))),10);
				b=MakePoint(273-j*135/((length/0.6)*(sqrt(Er))),297);
				if(q%10==0 && a.x>=0) 
					CanvasDrawLine (panelHandle, PANEL_CANVAS, a,b);
				v_neg1=  A[0]*(pow(e,(-(i-(T+(((cp*10)/(length/0.6))/6)*T))/tao)))-(v_pos1); 
				if(i>=(T+(((cp*10)/(length/0.6))/6)*T))
				{
					vl=v_pos1+v_neg1;
					il=(v_pos1/z0)-(v_neg1/z0);
				}
				SetCtrlVal (panelHandle, PANEL_Vl, vl);
				SetCtrlVal (panelHandle, PANEL_Il, il*1000); 
			    if((il>=(vg/zg)-0.000005) || (d==150*M-1))
			    {
					plot1();
			    }
			    j+=0.01;  
			}

		vlv[d]=vl;
		ilv[d]=il*1000; 
		i+=0.01;
		d++;   
			break;
	}
	return 0;
} 
/*******************************************************************************************/
int CVICALLBACK Go2 (int panel, int control, int event,
					void *callbackData, int eventData1, int eventData2)
{
	static int x;
	
	switch (event)
	{
		case EVENT_COMMIT:
			if(length ==0)
			{
				GetCtrlVal (panelHandle3, PANEL_4_Longtitude, &length);
				SetCtrlVal (panelHandle3, PANEL_4_V_Pos, -length);
				SetCtrlVal (panelHandle3, PANEL_4_Longtitude, length); 
				SetCtrlAttribute (panelHandle, PANEL_4_V_Pos, ATTR_MIN_VALUE, -length);
			} 
			GetCtrlVal (panelHandle3, PANEL_4_Go, &x);
			GetCtrlVal (panelHandle3, PANEL_4_RG, &zg);
			GetCtrlVal (panelHandle3, PANEL_4_VSource, &vg);
			GetCtrlVal (panelHandle3, PANEL_4_RL, &l);
			GetCtrlVal (panelHandle3, PANEL_4_Er, &Er);
			GetCtrlVal (panelHandle3, PANEL_4_Check_Point, &cp); 
			GetCtrlVal (panelHandle3, PANEL_4_Z0, &z0); 
			if(cp>length)
			{
				cp=0;
				SetCtrlVal (panelHandle3, PANEL_4_Check_Point, 0.0);
			}
			vph=c/sqrt(Er);
			rl=(l-z0)/(l+z0);
			rg=((zg-z0)/(z0+zg));
			T=(length/(vph))*G;
			v_pos1=(z0/(z0+zg))*vg;
			SetCtrlVal (panelHandle3, PANEL_4_Vph, vph);  
			SetCtrlAttribute (panelHandle3, PANEL_4_TIMER, ATTR_ENABLED, x);
			SetCtrlAttribute (panelHandle3, PANEL_4_TIMER, ATTR_INTERVAL, dt);
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
/*******************************************************************************************/
int CVICALLBACK TIMER2 (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{ 
	static int t; 
	Point a,b;
	int q=i*100,p=j*100+5,t1=0,t2;
	switch (event)
	{
		case EVENT_TIMER_TICK:
		 
		 t2=100*vg*(l/(l+zg));
		 t=floor(i) ;
		 if(rl!=0)
		 {
			if(t<T)	   // V+
			{ 
			
				if(flag==0)
					SetCtrlAttribute (panelHandle3, PANEL_4_CANVAS, ATTR_PEN_COLOR, VAL_CYAN);
				if(flag==2)
					SetCtrlAttribute (panelHandle3, PANEL_4_CANVAS, ATTR_PEN_COLOR, VAL_YELLOW);
				if(flag==4)
					SetCtrlAttribute (panelHandle3, PANEL_4_CANVAS, ATTR_PEN_COLOR, VAL_RED);
				a=MakePoint(i*135/((length/0.6)*(sqrt(Er))),10);
				b=MakePoint(i*135/((length/0.6)*(sqrt(Er))),297);
				if(i==0)
					CanvasDrawLine (panelHandle3, PANEL_4_CANVAS,a,b);
				if(i+0.01>T)
				{
					a=MakePoint(273,10);
					b=MakePoint(273,297);
					v_neg1=rl*v_pos1;
					CanvasDrawLine (panelHandle3, PANEL_4_CANVAS,a,b);
					flag++;
					if(cp==0 && ((int)(100*i)+1)%200==0) 
					{
						vl+=v_pos1+v_neg1;
						il+=(v_pos1/z0)-(v_neg1/z0);
						SetCtrlVal (panelHandle3, PANEL_4_Vl, vl);
						SetCtrlVal (panelHandle3, PANEL_4_Il, il*1000);		
					}
					t1=(vl+0.005)*100; 
					if(t1==t2 || (d==150*M-1)) // print if needed
					{  
						plot1();
				  	}
		
				}
				else
				{
					if(q%10==0 || a.x==273)
						CanvasDrawLine (panelHandle3, PANEL_4_CANVAS, a,b);

				}
				if(cp>0 && i>=T-(((cp*10)/(length/0.6))/6)*T && i-0.01<T-(((cp*10)/(length/0.6))/6)*T)
				{  
					if(cp<length)
					{
						vl+=v_pos1;
						il+=(v_pos1/z0);
					}
					else
						if(flag1==0)
						{
							vl+=v_pos1;
							il+=(v_pos1/z0);
							flag1++;
						}
					
					SetCtrlVal (panelHandle3, PANEL_4_Vl, vl);
					SetCtrlVal (panelHandle3, PANEL_4_Il, il*1000);
				} 
		
			}
			else //V-
			{
			  if(rl!=0)
			  {
		
				if(flag==1)
					SetCtrlAttribute (panelHandle3, PANEL_4_CANVAS, ATTR_PEN_COLOR, VAL_GREEN);
				if(flag==3)
					SetCtrlAttribute (panelHandle3, PANEL_4_CANVAS, ATTR_PEN_COLOR, VAL_BLACK);
				if(flag==5)
					SetCtrlAttribute (panelHandle3, PANEL_4_CANVAS, ATTR_PEN_COLOR, VAL_MAGENTA);
				a=MakePoint(273-j*135/((length/0.6)*(sqrt(Er))),10);
				b=MakePoint(273-j*135/((length/0.6)*(sqrt(Er))),297);
				if(cp>0 && i+0.01>=(T+(((cp*10)/(length/0.6))/6)*T)&& i<=T+(((cp*10)/(length/0.6))/6)*T)
				{
					if(cp<length)
					{
						vl+=v_neg1;
						il+=-(v_neg1/z0);
					}
					else
						if(flag1==1)
						{
							vl+=v_neg1;
							il+=-(v_neg1/z0);
							flag1--;
						}
					
					SetCtrlVal (panelHandle3, PANEL_4_Vl, vl);
					SetCtrlVal (panelHandle3, PANEL_4_Il, il*1000);
				}
				if(j+0.02>T)
				{
					if(rg==0)
						plot1();
					a=MakePoint(0,10);
					b=MakePoint(0,297);
					CanvasDrawLine (panelHandle3, PANEL_4_CANVAS,a,b);
					v_pos1=v_neg1*rg;
					j=-0.01;
					i=-0.01;
					flag++;
					if(flag==6)
						flag=0;
					if(t1==t2 || (d==150*M-1))  //print if needed
					{
						 plot1();
					}
				}
				if(p%10==0 && a.x>=0) 
					CanvasDrawLine (panelHandle3, PANEL_4_CANVAS, a,b);
	
			  } 

			  j+=0.01;  
			}
		   }
		   else   // if Rl==z0
		   {
			 SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_COLOR, VAL_RED);
			 a=MakePoint(i*135/((length/0.6)*(sqrt(Er))),10);
			 b=MakePoint(i*135/((length/0.6)*(sqrt(Er))),297);
	
			if(q%10==0 || a.x==273)
				CanvasDrawLine (panelHandle3, PANEL_4_CANVAS, a,b);
			if(cp>0 && i>=T-(((cp*10)/(length/0.6))/6)*T && i-0.01<T-(((cp*10)/(length/0.6))/6)*T)
			{
				vl=v_pos1;
				il=(v_pos1/z0);
				SetCtrlVal (panelHandle3, PANEL_4_Vl, vl);
				SetCtrlVal (panelHandle3, PANEL_4_Il, il*1000);
				
			}

			if(((i+0.01>=T) || (d==150*M-1)) && i>=T) //print when end of line
			  {  
			     plot1();
			  }
			   
		   }
			vlv[d]=vl;
			ilv[d]=il*1000; 
			i+=0.01;
			d++;   
			break;
	}
	return 0;
} 
/*******************************************************************************************/

int CVICALLBACK Cursor (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		double x1,y1,x2,y2;
		case EVENT_TIMER_TICK:
		    GetGraphCursor (panelHandle2, PANEL_2_GRAPH_2, 1, &x1, &y1);
			GetGraphCursor (panelHandle2, PANEL_2_GRAPH, 1, &x2, &y2);;
			SetCtrlVal (panelHandle2, PANEL_2_I_GRAPH, y2);
			SetCtrlVal (panelHandle2, PANEL_2_T_IL, x2);
			SetCtrlVal (panelHandle2, PANEL_2_VL_GRAPH, y1);
			SetCtrlVal (panelHandle2, PANEL_2_T_VL, x1);
			break;
	}
	return 0;
}

