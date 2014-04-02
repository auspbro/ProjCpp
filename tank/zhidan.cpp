# include "tanke.h"

////////////////////////////////////////坦克 子弹
void JBox(int (*x)[2][3],int * x_, int * y_, int * z,int * r, int * sd, int *zhidan,int *color1)
{	
	int h = 0;//图片的方向
	int k , k1, k2;//k循环，k1,k2装有的方向
	IMAGE img;
	loadimage(&img, _T("res\\player1.bmp"));
	if (x[*z + 1][0][1] == 0 &&	x[*z  + 1][0][2] == -1)//w
		h = 0;
	
	if (x[*z + 1][0][1] == 0 &&	x[*z + 1][0][2] ==  1)//s
		h = 2;
	
	if (x[*z + 1][0][1] == -1 && x[*z + 1][0][2] ==  0)//a
		h = 3;
	
	if (x[*z + 1][0][1] == 1 &&	x[*z + 1][0][2] ==  0)//d
		h = 1;
	
	if (GetAsyncKeyState('J'))//发射子弹
	{
		*z = *z + 1;
		
		x[*z + 1][0][1] = x[*z ][0][1] ;//x坐标中的方向
		x[*z + 1][0][2] = x[*z ][0][2] ;//

		if (x[*z][0][1] == 0 &&	x[*z][0][2] == -1)//w
		{
			x[*z][0][0] = *x_ + 34;
			x[*z][1][0] = *y_ + 14;
		}
		if (x[*z][0][1] == 0 &&	x[*z][0][2] ==  1)//s
		{
			x[*z][0][0] = *x_ + 34;
			x[*z][1][0] = *y_ + 48;	
		}
		if (x[*z][0][1] == -1 && x[*z][0][2] ==  0)//a
		{
			x[*z][0][0] = *x_ + 17;
			x[*z][1][0] = *y_ + 33;
		}
		if (x[*z][0][1] == 1 &&	x[*z][0][2] ==  0)//d
		{
			x[*z][0][0] = *x_ + 48;
			x[*z][1][0] = *y_ + 33;
		}
		keybd_event(74,0,KEYEVENTF_KEYUP,0);
	}
	putimage( *x_,  *y_, 28 , 28 , &img, 28 * (*color1) , 28 * h );

	for (k = 0; k<40; k++)
	{		
		k1 = x[k][0][1];
		k2 = x[k][0][2];
		if(*r % *sd == 0)//己方子弹的的速度
		{
			if ( k1 == 1 && k2 == 0 && x[k][0][0] != 0)
				x[k][0][0] = x[k][0][0] + 4;
			
			if ( k1 == 0 && k2 == 1 && x[k][0][0] != 0)
				x[k][1][0] = x[k][1][0] + 4;
			
			if ( k1 == -1 && k2 == 0 && x[k][0][0] != 0)
				x[k][0][0] = x[k][0][0] - 4;
			
			if ( k1 == 0 && k2 == -1 && x[k][0][0] != 0)
				x[k][1][0] = x[k][1][0] - 4;			
		}
		
		if ( (x[k][0][0] -20) >= 640 || (x[k][0][0] - 20)<= 0)
			x[k][0][0] = 0 ;//子弹到边界 就初始化数组坐标x为0
		if ( (x[k][1][0] -20) >= 480 || (x[k][1][0] - 20)<= 0)
			x[k][0][0] = 0 ;
		
		solidcircle(x[k][0][0] - 20,  x[k][1][0] - 20, *zhidan);
	}
	
	if (*z >= 38)//数组 要满时就循环
	{
		x[1][0][1] = x[*z ][0][1] ;
		x[1][0][2] = x[*z ][0][2] ;
		x[1][1][1] = x[*z ][1][1] ;
		x[1][1][2] = x[*z ][1][2] ;
		*z = 0;
	}
	
	return ;
}

void DBox(int (*x)[2][3],int * x_, int * y_, int * z, int *r, int * color)
{	
	int h = 0;
	int k , k1, k2;
	IMAGE img;
	loadimage(&img,_T("res\\enemy.bmp"));
	if (x[*z + 1][0][1] == 0 &&	x[*z  + 1][0][2] == -1)//w
		h = 0;
	
	if (x[*z + 1][0][1] == 0 &&	x[*z + 1][0][2] ==  1)//s
		h = 2;
	
	if (x[*z + 1][0][1] == -1 && x[*z + 1][0][2] ==  0)//a
		h = 3;
	
	if (x[*z + 1][0][1] == 1 &&	x[*z + 1][0][2] ==  0)//d
		h = 1;
	if ((*r) % 80 == 0)//敌坦克发子弹频率
	{
		*z = *z + 1;
		
		x[*z + 1][0][1] = x[*z ][0][1] ;//给方向
		x[*z + 1][0][2] = x[*z ][0][2] ;
		
		if (x[*z][0][1] == 0 &&	x[*z][0][2] == -1)//w
		{
			x[*z][0][0] = *x_ + 34;
			x[*z][1][0] = *y_ + 14;
		}
		if (x[*z][0][1] == 0 &&	x[*z][0][2] ==  1)//s
		{
			x[*z][0][0] = *x_ + 34;
			x[*z][1][0] = *y_ + 48;
			
		}
		if (x[*z][0][1] == -1 && x[*z][0][2] ==  0)//a
		{
			x[*z][0][0] = *x_ + 17;
			x[*z][1][0] = *y_ + 33;
		}
		if (x[*z][0][1] == 1 &&	x[*z][0][2] ==  0)//d
		{
			x[*z][0][0] = *x_ + 48;
			x[*z][1][0] = *y_ + 33;
		}
	}
	
	putimage( *x_,  *y_, 28 , 28 , &img, *color , 28 * h );
	for (k = 0; k<40; k++)
	{		
		k1 = x[k][0][1];
		k2 = x[k][0][2];
		if(*r % 1 == 0)//敌坦克子弹速度
		{
			if ( k1 == 1 && k2 == 0 && x[k][0][0] != 0)
				x[k][0][0] = x[k][0][0] + 2;
			
			if ( k1 == 0 && k2 == 1 && x[k][0][0] != 0)
				x[k][1][0] = x[k][1][0] + 2;
			
			if ( k1 == -1 && k2 == 0 && x[k][0][0] != 0)
				x[k][0][0] = x[k][0][0] - 2;
			
			if ( k1 == 0 && k2 == -1 && x[k][0][0] != 0)
				x[k][1][0] = x[k][1][0] - 2;			
		}
		
		if ( (x[k][0][0] -20) >= 640 || (x[k][0][0] - 20)<= 0)
			x[k][0][0] = 0 ;
		if ( (x[k][1][0] -20) >= 480 || (x[k][1][0] - 20)<= 0)
			x[k][0][0] = 0 ;
		
		fillcircle(x[k][0][0] - 20,  x[k][1][0] - 20, 5);
	}
	
	if (*z >= 38)
	{
		x[1][0][1] = x[*z ][0][1] ;
		x[1][0][2] = x[*z ][0][2] ;
		x[1][1][1] = x[*z ][1][1] ;
		x[1][1][2] = x[*z ][1][2] ;
		*z = 0;
	}
	
	return ;
}

void DBoxBig(int (*x)[2][3],int * x_, int * y_, int * z, int *r, int * color)
{	
	int h = 0;
	int k , k1, k2;
	IMAGE img;
	loadimage(&img,_T("res\\enemy.bmp"));
	if (x[*z + 1][0][1] == 0 &&	x[*z  + 1][0][2] == -1)//w
		h = 0;
	
	if (x[*z + 1][0][1] == 0 &&	x[*z + 1][0][2] ==  1)//s
		h = 2;
	
	if (x[*z + 1][0][1] == -1 && x[*z + 1][0][2] ==  0)//a
		h = 3;
	
	if (x[*z + 1][0][1] == 1 &&	x[*z + 1][0][2] ==  0)//d
		h = 1;
	if ((*r) % 30 == 0)//敌坦克发子弹频率
	{
		*z = *z + 1;
		
		x[*z + 1][0][1] = x[*z ][0][1] ;
		x[*z + 1][0][2] = x[*z ][0][2] ;		
		if (x[*z][0][1] == 0 &&	x[*z][0][2] == -1)//w
		{
			x[*z][0][0] = *x_ + 34;
			x[*z][1][0] = *y_ + 14;
		}
		if (x[*z][0][1] == 0 &&	x[*z][0][2] ==  1)//s
		{
			x[*z][0][0] = *x_ + 34;
			x[*z][1][0] = *y_ + 48;
			
		}
		if (x[*z][0][1] == -1 && x[*z][0][2] ==  0)//a
		{
			x[*z][0][0] = *x_ + 17;
			x[*z][1][0] = *y_ + 33;
		}
		if (x[*z][0][1] == 1 &&	x[*z][0][2] ==  0)//d
		{
			x[*z][0][0] = *x_ + 48;
			x[*z][1][0] = *y_ + 33;
		}
		keybd_event(74,0,KEYEVENTF_KEYUP,0);
	}
	
	putimage( *x_,  *y_, 28 , 28 , &img, *color , 112 + (28 * h) );
	for (k = 0; k<40; k++)
	{		
		k1 = x[k][0][1];
		k2 = x[k][0][2];
		if(*r % 2 == 0)//敌坦克子弹速度
		{
			if ( k1 == 1 && k2 == 0 && x[k][0][0] != 0)
				x[k][0][0] = x[k][0][0] + 15;
			
			if ( k1 == 0 && k2 == 1 && x[k][0][0] != 0)
				x[k][1][0] = x[k][1][0] + 15;
			
			if ( k1 == -1 && k2 == 0 && x[k][0][0] != 0)
				x[k][0][0] = x[k][0][0] - 15;
			
			if ( k1 == 0 && k2 == -1 && x[k][0][0] != 0)
				x[k][1][0] = x[k][1][0] - 15;			
		}
		
		if ( (x[k][0][0] -20) >= 640 || (x[k][0][0] - 20)<= 0)
			x[k][0][0] = 0 ;
		if ( (x[k][1][0] -20) >= 480 || (x[k][1][0] - 20)<= 0)
			x[k][0][0] = 0 ;
		
		fillcircle(x[k][0][0] - 20,  x[k][1][0] - 20, 5);
	}
	
	if (*z >= 38)
	{
		x[1][0][1] = x[*z ][0][1] ;
		x[1][0][2] = x[*z ][0][2] ;
		x[1][1][1] = x[*z ][1][1] ;
		x[1][1][2] = x[*z ][1][2] ;
		*z = 0;
	}
	
	return ;
}

void DBoxFeiJi(int (*x_9)[2][3],int (*x_10)[2][3],int (*x_11)[2][3],int * x_, int * y_, int * z, int *r)
{	
	int k;
	IMAGE img;
	loadimage(&img, _T("res\\feiji.jpg"));
	
	HDC	dstDC = GetImageHDC();  
	HDC	srcDC = GetImageHDC(&img);

	TransparentBlt(dstDC,*x_,*y_, 65, 65, srcDC, 0, 0, 65, 65, RGB(0,0,0));//飞机
	
	if ((*r) % 13 == 0)//敌坦克发子弹频率
	{	
		*z = *z + 1;
		x_9[*z][0][0] = *x_ + 52;
		x_9[*z][1][0] = *y_ + 85;
		
		x_10[*z][0][0] = *x_ + 52;
		x_10[*z][1][0] = *y_ + 85;
		
		x_11[*z][0][0] = *x_ + 52;
		x_11[*z][1][0] = *y_ + 85;
	}
	for (k = 0; k<40; k++)
	{		
		if(*r % 5 == 0 && x_10[k][0][0] != 0)//敌坦克子弹速度
		{	
			x_9[k][1][0] = x_9[k][1][0] + 15;
			
			x_10[k][0][0] = x_10[k][0][0] + 15;
			x_10[k][1][0] = x_10[k][1][0] + 15;
			
			x_11[k][0][0] = x_11[k][0][0] - 15;
			x_11[k][1][0] = x_11[k][1][0] + 15;					
		}
		
		if ( (x_9[k][1][0] -20) >= 480 )
			x_9[k][0][0] = 0 ;
		if ( (x_10[k][1][0] -20) >= 480)
			x_10[k][0][0] = 0 ;
		if ( (x_11[k][1][0] -20) >= 480)
			x_11[k][0][0] = 0 ;

		fillcircle(x_9[k][0][0] - 20,  x_9[k][1][0] - 20, 7);
		fillcircle(x_10[k][0][0] - 20,  x_10[k][1][0] - 20, 7);
		fillcircle(x_11[k][0][0] - 20,  x_11[k][1][0] - 20, 7);
	}	
	
	if (*z >= 38)
		*z = 0;	
	return ;
}


