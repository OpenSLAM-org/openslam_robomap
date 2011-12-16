#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;


namespace ROBOMAP {

	ref class c104LSItemPolar;
 ref class c104LSItemXY;

//**********************************************************
//**********************************************************

	public ref class c104LSScan
	{

public:
	double MinX_Polar;
	double MaxX_Polar;
	double MinY_Polar;
	double MaxY_Polar;

	double MinX_XY;
	double MaxX_XY;
	double MinY_XY;
	double MaxY_XY;

	double RHeadX;
	double RHeadY;


public:
		array<c104LSItemPolar^>^ LSItemPolar;
		array<c104LSItemXY^>^ LSItemXY;
		array<c104LSItemXY^>^ LSItemXYrot;
	
public:
	 double x;
		double y;

public:
  	
		  c104LSScan(UInt16 c)
				{ 
					 
					LSItemPolar = gcnew array<c104LSItemPolar^>(c);
   		LSItemXY = gcnew array<c104LSItemXY^>(c);
  		 LSItemXYrot = gcnew array<c104LSItemXY^>(c);
					

     MinX_Polar = 0;
     MaxX_Polar = 0;
	    MinY_Polar = 0;
	    MaxY_Polar = 0;

     MinX_XY = 0;
	    MaxX_XY = 0;
	    MinY_XY = 0;
	    MaxY_XY = 0;

					RHeadX = 0;
					RHeadY = 0; 
				}

			 ~c104LSScan()
				{
					delete( LSItemPolar );
					delete( LSItemXY );
					delete( LSItemXYrot );
				}// c104LSScan()


};// 	public ref class c104LSScan 

//**********************************************************
//**********************************************************

public ref class c104LSItemXY 
{
private:
  double x;
		double y;
	
public:
		  c104LSItemXY()
				{ 
					x=0;
					y=0;
				}

				~c104LSItemXY()
				{
				}

virtual property double X 
    {
        double get() { return x; }
								void set(double value){ x = value;  }

    }// virtual property double X 

virtual property double Y 
    {
        double get() { return y; }
								void set(double value){ y = value;  }

    }// virtual property double Y 

};// public ref class c104LSItemXY


//**********************************************************
//**********************************************************

public ref class c104LSItemPolar 
{
private:
  double l;

		Boolean correct;

public:
		  c104LSItemPolar()
				{ 
					l = 0;
					correct = true;
 			}

				~c104LSItemPolar(){
				}

virtual property double PolarLength 
    {
        double get() { return l; }
								void set( double value ){ l = value;  }

    }// virtual property UInt16 Length

virtual property Boolean Correct 
    {
        Boolean get() { return correct; }
								void set( Boolean value ){ correct = value;  }

    }// virtual property UInt16 Length

};// public ref class c104LSItemPolar


//**********************************************************
//**********************************************************

public ref class c104TriangleItem 
{
public:
	 System::Double X1;
		System::Double Y1;
	 System::Double X2;
		System::Double Y2;

public:
		  c104TriangleItem()
				{ 
				
					X1=0;
					Y1=0;
     X2=0;
					Y2=0;
 			}

				~c104TriangleItem(){
				}

};// public ref class c104TriangleItem

//**********************************************************
//**********************************************************
public ref class c104LineItem //: public IEnumerator
{

public:

 		double X1;
			double Y1;
			double X2;
			double Y2;
			double LengthSQR;    // not used
			double diffX;        // not used
			double diffY;        // not used
			double Length;       // not used
			
   double Wx1;
			double Wx2;
   double Wy1;
			double Wy2;

			double a2;
			double b2;
			double c2;

			double a1;
			double b1;
			double c1;

			double u1;
			double u2;

			Int32 Tag;

  	 
public:
		  c104LineItem()
				{ 
	   		X1 = 0;
 			  Y1 = 0;
			   X2 = 0;
			   Y2 = 0;
			   LengthSQR = 0;     // not used
			   diffX = 0;         // not used
			   diffY = 0;         // not used
			   Length = 0;        // not used
			
      Wx1 = 0;
			   Wx2 = 0;
      Wy1 = 0;
			   Wy2 = 0;

			   a2 = 0;
			   b2 = 0;
			   c2 = 0;

			   a1 = 0;
			   b1 = 0;
			   c1 = 0;

			   u1 = 0;
			   u2 = 0;

						Tag = 0;
						
				}

				~c104LineItem()
				{ 
			 }

};// public ref class c104LineItem


//**********************************************************
//**********************************************************

public ref class c104LSBeamItem  
{

public:
	  
			double fX1;
			double fY1;
			double fX2;
			double fY2;

 		double mX1;
			double mY1;
			double mX2;
			double mY2;

			double cosX;
			double sinY;

			double PolarLength;
			double CalculatedLength;

			double a1;
			double b1;
			double c1;

			double Bx1;
			double Bx2;
			double By1;
			double By2;

			double BeamAngle;

 	 
public:
		  c104LSBeamItem ()
				{ 

		   fX1 = 0;
			  fY1 = 0;
			  fX2 = 0;
			  fY2 = 0;

 		  mX1 = 0;
			  mY1 = 0;
			  mX2 = 0; 
			  mY2 = 0;

					cosX = 0;
			  sinY = 0;

			  PolarLength  = 0;
					CalculatedLength = 0;

     a1 = 0;
			  b1 = 0;
			  c1 = 0;

			  Bx1 = 0;
			  Bx2 = 0;
			  By1 = 0;
			  By2 = 0;

					BeamAngle = 0;

				}

				~c104LSBeamItem()
				{ 
			 }

};// public ref class c104LSBeamItem 

//**********************************************************
//**********************************************************

public ref class c104SimPosItem
{
public:
  double X;
		double Y;
		double Evaluation;
		double EvaluationSQRT;
		//double BeamsLength;
		double Angle;
	
public:
		  c104SimPosItem()
				{ 
					X = 0;
					Y = 0;
					Evaluation = 0;
					EvaluationSQRT = 0;
					Angle = 0;
				}

				~c104SimPosItem()
				{
				}

};// public ref class cSimPositionItem

//**********************************************************
//**********************************************************

	public ref class c104ObstacleItem
{
	public:
 Boolean Obstacle;
	
public:
		  c104ObstacleItem()
				{ 
     Obstacle = false;
				}

				~c104ObstacleItem()
				{
				}

};// public ref class c104ObstacleItem

//**********************************************************
//**********************************************************

	public ref class c104FoundPosition
{

public:
	double DsMinX_Polar;
	double DsMaxX_Polar;
	double DsMinY_Polar;
	double DsMaxY_Polar;

	double DsMinX_XY;
	double DsMaxX_XY;
	double DsMinY_XY;
	double DsMaxY_XY;

	double DsRHeadX;
	double DsRHeadY;

	double DfMinX_XY;
	double DfMaxX_XY;
	double DfMinY_XY;
	double DfMaxY_XY;

	double PosX;
	double PosY;
 double Angle;
	double Optimum;

	double XYAttrib;
	double NoiseLevel;

	UInt32 Sample;


public:
		array<c104LSItemPolar^>^ LSItemDsPolar;
		array<c104LSItemXY^>^ LSItemDsXY;
		array<c104LSItemXY^>^ LSItemDfXY;
		array<c104ObstacleItem^>^ Obstacle;

public:
  	
		  c104FoundPosition(UInt16 DmCount, UInt16 DsCount)
				{ 

     LSItemDsPolar = gcnew array<c104LSItemPolar^>(DsCount);
   		LSItemDsXY = gcnew array<c104LSItemXY^>(DsCount);
   		LSItemDfXY = gcnew array<c104LSItemXY^>(DsCount);
   		Obstacle = gcnew array<c104ObstacleItem^>(DsCount);
					
					DsRHeadX = 0;
					DsRHeadY = 0; 

	    PosX = 0;
	    PosY = 0;
     Angle = 0;
					Optimum = 0;

					Sample = 0;

					XYAttrib = 0;
					NoiseLevel = 0;

				}

		  c104FoundPosition()
				{ 
					delete( LSItemDsPolar );
					delete( LSItemDsXY  );
					delete( LSItemDfXY );
					delete( Obstacle );
				}

};// 	public ref class c29FoundedPosition 

//**********************************************************
//**********************************************************
	
public ref class c104PopItem
{

public:
	  
			double Xdec;
			double Ydec;
			double Angle;

 		double Fitness;
			double Fitness2nd;
	
			Byte Tag;
 
public:
		  c104PopItem ()
				{ 

					Xdec = 0;
			  Ydec = 0;
					Angle = 0;

					Fitness = 0;
					Fitness2nd = 0;

					Tag = 0;
				}

				~c104PopItem()
				{ 
			 }

};// public ref class c104PopItem 

//**********************************************************
//**********************************************************

public ref class c104StartPoses
{
public:
	 String^ Name;
  double X;
		double Y;
		double Angle;
		String^ Info;
	
public:
		  c104StartPoses ()
				{ 
					Name = "";
					X = 0;
					Y = 0;
					Angle = 0;
					Info = "";
				}

				~c104StartPoses()
				{
				}

};// public ref class cSimPositionItem

//**********************************************************
//**********************************************************

}//;namespace ROBOMAP 