// MapBuilding_LM102

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;


namespace ROBOMAP {

//**********************************************************
//**********************************************************

public ref class c100LineItem 
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
		  c100LineItem()
				{ 
	   		X1 = 0;
 			  Y1 = 0;
			   X2 = 0;
			   Y2 = 0;
			   LengthSQR = 0;    // not used
			   diffX = 0;        // not used
			   diffY = 0;        // not used
			   Length = 0;       // not used
			
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

				~c100LineItem()
				{ 
			 }

};// public ref class c100LineItem

//**********************************************************
//**********************************************************

public ref class c100LSRayBunchItem 
{
public:
	 double X;
		double Y;
  double PolarLength;
		Byte Status;
		Int32 Group;
		Int32 PosIndex;

public:
		  c100LSRayBunchItem()
				{ 
   		PolarLength = 0;
					PosIndex = 0;
					Status = 0;
					Group = 0;
					X = 0;
					Y = 0;
 			}

				~c100LSRayBunchItem(){
				}

};// public ref class c100LSRayBunchItem

//**********************************************************
//**********************************************************
	
public ref class c100ApproxLineItem
{
public:
	 double X1;
		double Y1;
	 double X2;
		double Y2;

		Int32 Tag;

public:
			List<Object^>^ BeamArray;

public:
		   c100ApproxLineItem()
				{ 
				 	BeamArray = gcnew List<Object^>();
																		
		    X1 = 0;
		    Y1 = 0;
	     X2 = 0;
		    Y2 = 0;

						Tag = -1;
 			}

				~c100ApproxLineItem(){
					  delete( BeamArray );
				}

};// public ref class c100LineAtom

//**********************************************************
//**********************************************************

public ref class c100PointAtom
{
public:
	 double X;
		double Y;

public:
	   c100PointAtom()
				{ 
		    X = 0;
		    Y = 0;
 			}

				~c100PointAtom(){
				}

};// public ref class c100PointAtom

//**********************************************************
//**********************************************************

public ref class c100MultiLineApproximationA 
{
public:

	List<Object^>^ OriginalBeamBunch;
	List<Object^>^ OriginalWallsBunch;

	List<Object^>^ WallsBunch_1; 
	List<Object^>^ WallsBunch_2; 
	List<Object^>^ BeamBunch_1; 

	array<Boolean>^ RBeam;

	double g_distanceLimit_pointToLine; 
	double g_distanceLimit_pointTopoint;

	
public:
		 	c100MultiLineApproximationA( List<Object^>^ b1, List<Object^>^ w1, array<Boolean>^ rb )
				{

     OriginalBeamBunch = b1;
					OriginalWallsBunch = w1;

     RBeam = rb;

   		BeamBunch_1 = gcnew List<Object^>();
     WallsBunch_1 = gcnew List<Object^>(); 
					WallsBunch_2 = gcnew List<Object^>(); 

     g_distanceLimit_pointToLine = 10;
					g_distanceLimit_pointTopoint = 10;


				} // 

private:
				~c100MultiLineApproximationA()
				{

						delete( BeamBunch_1 );
      delete( WallsBunch_1 );
						delete( WallsBunch_2 );

				}// 


public: System::Boolean checkDistance( Int32 P1, Int32 P2 ) {

double a = 0;
double b = 0;
double c = 0;

double R1 = 0;

//*******************

      a = safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ P1 ] )->Y - safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ P2 ] )->Y;
      b = safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ P2 ] )->X - safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ P1 ] )->X;
						c = ( safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ P1 ] )->X*safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ P2 ] )->Y - 
							     safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ P2 ] )->X*safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ P1 ] )->Y );

						for ( Int32 i=P1; i <= P2; i++ ){

							   R1 = Math::Abs( a*safe_cast<c100LSRayBunchItem^>( BeamBunch_1[i] )->X + b*safe_cast<c100LSRayBunchItem^>( BeamBunch_1[i] )->Y + c ) /
											    Math::Sqrt( Math::Pow( a,2 ) + Math::Pow( b,2 ) );	 

										if ( R1 > g_distanceLimit_pointToLine ){
             return false;
										}// if 

						}// for 

      return true;


}// public: System::Boolean checkDistance( Int32 a, Int32 b )

public: System::Int32 recursiveLineSplitting( Int32 P1, Int32 P2 ) {

									if ( (P2-P1) <= 1 ){
										  return 0;
									}// if

									if ( checkDistance( P1, P2 ) == false ){

									  	recursiveLineSplitting( P1, Convert::ToInt32( P1+((P2-P1)*0.5) ) );
										  recursiveLineSplitting( Convert::ToInt32( P1+((P2-P1)*0.5) ), P2 );

									} else
									{
										  c100ApproxLineItem^ item = gcnew c100ApproxLineItem();

												item->X1 = safe_cast<c100LSRayBunchItem^>( BeamBunch_1[P1] )->X; 
												item->Y1 = safe_cast<c100LSRayBunchItem^>( BeamBunch_1[P1] )->Y;
												item->X2 = safe_cast<c100LSRayBunchItem^>( BeamBunch_1[P2] )->X; 
												item->Y2 = safe_cast<c100LSRayBunchItem^>( BeamBunch_1[P2] )->Y;

												for ( Int32 i=P1; i <= P2; i++ ){
													   item->BeamArray->Add( safe_cast<c100LSRayBunchItem^>( BeamBunch_1[i] ) );
												}// for

												WallsBunch_1->Add( item );

									}// if else

									return 0;

}// public: System::Int32 recursiveLineSplitting( startPoint, endPoint )

public: System::Int32 Run(){
									                   

Int32 RI1 = 0;
Int32 RI2 = 0;

double R1 = 0;

Int32 group = 0;
Int32 counter = 0;

double x1 = 0;
double y1 = 0;
double x2 = 0;
double y2 = 0;

double a = 0;
double b = 0;
double c = 0;

Int32 startPoint = 0;
Int32 endPoint = 0;
Int32 maxGroup = 0;

Boolean result = false;

Boolean exitStatus = false;

//*************************************


     // extract all single points, XY coordinates
					for ( Int32 i=0;i < Convert::ToInt32( OriginalBeamBunch->Count );i++ ){

						   result = false;
									for ( Int32 j=0;j < Convert::ToInt32( OriginalBeamBunch->Count );j++ ){

										   if ( RBeam == nullptr ){

										      if ( i != j ){ 
														 
												  		   R1 = Math::Sqrt( Math::Pow( safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[i] )->X - 
																	                              safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[j] )->X, 2 ) +  
														  	                   Math::Pow( safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[i] )->Y - 
																									   								           safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[j] )->Y, 2 ) ); 
														     if ( R1 <= g_distanceLimit_pointTopoint ){
														        result = true;
   														  }// if 

			   										}// if 

													} else
													{

										      if ( i != j && RBeam[i] == true && RBeam[j] == true ){ 
														 
												  		   R1 = Math::Sqrt( Math::Pow( safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[i] )->X - 
																	                              safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[j] )->X, 2 ) +  
														  	                   Math::Pow( safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[i] )->Y - 
																									   								           safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[j] )->Y, 2 ) ); 
														     if ( R1 <= g_distanceLimit_pointTopoint ){
														        result = true;
   														  }// if 

			   										}// if 

													}// if else


									}// for 

									if ( result == true ){

   									c100LSRayBunchItem^ Beam = gcnew c100LSRayBunchItem();

						      Beam->PolarLength = safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[i] )->PolarLength; 
									   Beam->X = safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[i] )->X;
									   Beam->Y = safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[i] )->Y;
										  Beam->Group = -1; 
 								   Beam->Status = 0; 
									   Beam->PosIndex = safe_cast<c100LSRayBunchItem^>( OriginalBeamBunch[i] )->PosIndex; 
  
										  BeamBunch_1->Add(Beam);

									}// if 

					}// for 

     // create groups of points, XY coordinates
					group = 0;
					safe_cast<c100LSRayBunchItem^>( BeamBunch_1[0] )->Group = 0;
					for ( Int32 i=0;i < Convert::ToInt32( BeamBunch_1->Count-1 );i++ ){ // -1 because RI1 = i+1

						   RI1 = i + 1;
									R1 = Math::Sqrt( Math::Pow( safe_cast<c100LSRayBunchItem^>( BeamBunch_1[i] )->X - safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ RI1 ] )->X, 2 ) +  
										                Math::Pow( safe_cast<c100LSRayBunchItem^>( BeamBunch_1[i] )->Y - safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ RI1 ] )->Y, 2 ) ); 
									if ( R1 > g_distanceLimit_pointTopoint ){
										  group = group + 1;
									} else
									{
									   safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ RI1 ] )->Group = group;
									}// if 

					}// for 
					maxGroup = group;


					// line recursive splitting previously groupped points
					startPoint = 0;
					endPoint = 0;
					for ( Int32 i=0; i <= maxGroup ; i++ ){

						   exitStatus = false;
					    do
					    {
						     endPoint = endPoint + 1;

											if ( endPoint >= BeamBunch_1->Count-1 ){
												  exitStatus = true;
											} else
											{
											   if ( safe_cast<c100LSRayBunchItem^>( BeamBunch_1[ endPoint ] )->Group != i ){
												     exitStatus = true;
											   }// if 
											}// if 

					    } while ( exitStatus == false );

									endPoint = endPoint - 1;

								//	Console::WriteLine("recursive {0} {1}", startPoint, endPoint ); 

									if ( endPoint - startPoint > 1 ){ 
					       recursiveLineSplitting( startPoint, endPoint );
									}// if 

									startPoint = endPoint + 1;
									endPoint = endPoint + 1;

					}// for 


					/*
					// joining adjacent lines, alternative  No regresion algorithm
					for ( Int32 i=0;i < WallsBunch_1->Count-1; i++ ){

						   RI1 = i+1;

						   x1 = safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X1;
									y1 = safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y1;
						   x2 = safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->X2;
									y2 = safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->Y2;

         a = y1 - y2;
         b = x2 - x1;
         c = x1*y2 - x2*y1;

									result = true;
									for ( Int32 j=0;j < safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray->Count; j++){
										   
							      R1 = Math::Abs( a*safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[j] )->X +
														               b*safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[j] )->Y + c ) /
											       Math::Sqrt( Math::Pow( a,2 ) + Math::Pow( b,2 ) );	 

										   if ( R1 > 10 ){
                result = false;
										   }// if 

									}// for
									for ( Int32 j=0;j < safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray->Count; j++){
										   
							      R1 = Math::Abs( a*safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray[j] )->X +
														               b*safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray[j] )->Y + c ) /
											       Math::Sqrt( Math::Pow( a,2 ) + Math::Pow( b,2 ) );	 

										   if ( R1 > 10 ){
                result = false;
										   }// if 

									}// for
									R1 = Math::Sqrt( Math::Pow( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X2 - safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->X1, 2 ) + 
										                Math::Pow( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y2 - safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->Y1, 2 ) );
									if ( R1 > g_distanceLimit ){
										  result = false;
									}// if 
										    
									if ( result == true ){

										  //safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X2 = safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->X2;
										  //safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y2 = safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->Y2;

										  RI2 = safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray->Count - 1;

										  safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X1 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[0] )->X;
										  safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y1 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[0] )->Y;
										  safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X2 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray[RI2] )->X;
										  safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y2 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray[RI2] )->Y;

												/// join point clout from RI1 to i 
												for ( Int32 j=0; j < RI2; j++ ){

													   safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray->Add( safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray[j] );
													   
												}// for 

												safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray->Clear();
												Object^ dummy = WallsBunch_1[RI1];
												WallsBunch_1->Remove( dummy );
												delete( dummy );

												i = 0; // RESET i

									}/// if 

					}// for
					*/


					// merge two lines if it is possible, based on linear regression  
					for ( Int32 i=0;i < WallsBunch_1->Count-1; i++ ){

						   RI1 = i+1;

    					if ( canBeMerged(i,RI1) == true ){

										  RI2 = safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray->Count - 1;

										  safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X1 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[0] )->X;
										  safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y1 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[0] )->Y;
										  safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X2 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray[RI2] )->X;
										  safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y2 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray[RI2] )->Y;

					    		 // join two clouds of points, from RI1 to i 
												for ( Int32 j=0; j < RI2; j++ ){

													   safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray->Add( safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray[j] );
													   
												}// for 

												safe_cast<c100ApproxLineItem^>( WallsBunch_1[RI1] )->BeamArray->Clear();
												Object^ dummy = WallsBunch_1[RI1];
												WallsBunch_1->Remove( dummy );
												delete( dummy );

												i = 0; // RESET i

									}// if 
        
					}// if 


     // line improvement - LINEAR REGRESSION
					lineImprovement();

					// move set of lines to output array
					for ( Int32 i=0; i < WallsBunch_1->Count ; i++ ){

						   ROBOMAP::c100ApproxLineItem^ line = gcnew c100ApproxLineItem();

						   line->X1  = safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X1;
						   line->Y1  = safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y1;
						   line->X2  = safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X2;
						   line->Y2  = safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y2;

         OriginalWallsBunch->Add( line );

					}// for 

					return 0;

}// public: System::Int32 Run(){ 


public: System::Boolean canBeMerged( Int32 item_1, Int32 item_2 ){

Int32 RI1 = 0;

double R1 = 0;
double R2 = 0;
double R3 = 0;

double xi = 0;
double yi = 0;

double cmass_X = 0;
double cmass_Y = 0;

double sumXiYi = 0;
double sumXi = 0;
double sumYi = 0;
double sumXi2 = 0;

double param_n = 0;
double param_k = 0;
double param_q = 0;
double param_sign = 0;

double A_x = 0;
double A_y = 0;
double B_x = 0;
double B_y = 0;
double C_x = 0;
double C_y = 0;
double D_x = 0;
double D_y = 0;
double E_x = 0;
double E_y = 0;
double F_x = 0;
double F_y = 0;
double G_x = 0;
double G_y = 0;

double AB_a = 0;
double AB_b = 0;
double AB_c = 0;

double CD_a = 0;
double CD_b = 0;
double CD_c = 0;

double EF_a = 0;
double EF_b = 0;
double EF_c = 0;

double GCD_a = 0;
double GCD_b = 0;
double GCD_c = 0;

double Xaxis_a = 0;
double Xaxis_b = 0;
double Xaxis_c = 0;

double angle_AB_Xaxis = 0;
double angle_CD_Xaxis = 0;
double angle_CD2_Xaxis = 0;
double angle_EF_Xaxis = 0;

double CD_minX = 0;
double CD_maxX = 0;
double CD_minY = 0;
double CD_maxY = 0;

double xp_G_CD = 0;
double yp_G_CD = 0;

double leftLength = 0;
double rightLength = 0;

double leftMaxPoint_x = 0;
double leftMaxPoint_y = 0;

double rightMaxPoint_x = 0;
double rightMaxPoint_y = 0;

Boolean exitStatus = false;

List<Object^>^ cloudOfPoints;

//******************************************


     cloudOfPoints = gcnew List<Object^>();

					// create cloud of points from WallBunch(item_1) and WallBunch(item_2)
					for ( Int32 i=0; i < safe_cast<c100ApproxLineItem^>( WallsBunch_1[ item_1 ] )->BeamArray->Count; i++ ){

						   c100PointAtom^ item = gcnew c100PointAtom();
									item->X = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[ item_1 ] )->BeamArray[i] )->X;
									item->Y = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[ item_1 ] )->BeamArray[i] )->Y;

									cloudOfPoints->Add( item );

					}// for 
					for ( Int32 i=0; i < safe_cast<c100ApproxLineItem^>( WallsBunch_1[ item_2 ] )->BeamArray->Count; i++ ){

						   c100PointAtom^ item = gcnew c100PointAtom();
									item->X = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[ item_2 ] )->BeamArray[i] )->X;
									item->Y = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[ item_2 ] )->BeamArray[i] )->Y;

									cloudOfPoints->Add( item );

					}// for 


     // check distance between two consecutive points
					exitStatus = false;
					for ( Int32 i=0; i < cloudOfPoints->Count-1; i++ ){

						   RI1 = i + 1;
									R1 =  Math::Sqrt( Math::Pow( safe_cast<c100PointAtom^>(cloudOfPoints[i])->X - safe_cast<c100PointAtom^>(cloudOfPoints[ RI1 ])->X, 2 ) +
									                  Math::Pow( safe_cast<c100PointAtom^>(cloudOfPoints[i])->Y - safe_cast<c100PointAtom^>(cloudOfPoints[ RI1 ])->Y, 2 ) );

				     if ( R1 > g_distanceLimit_pointTopoint ){
            exitStatus = true;
							  }// if 

					}// for 

					if ( exitStatus == true ){

								for (	Int32 i=0; i < cloudOfPoints->Count; i++ ){
									   delete( safe_cast<c100PointAtom^>(cloudOfPoints[i]) );
								}// for 
								cloudOfPoints->Clear(); 
								delete( cloudOfPoints );

								return false;

					}// if 
					
			
					// compute center of mass
					R1 = 0;
					R2 = 0;
					for ( Int32 i=0; i < cloudOfPoints->Count; i++ ){

					    R1 = R1 + safe_cast<c100PointAtom^>(cloudOfPoints[i])->X;
					    R2 = R2 + safe_cast<c100PointAtom^>(cloudOfPoints[i])->Y;

					}// for 
					cmass_X = R1 / cloudOfPoints->Count;
					cmass_Y = R2 / cloudOfPoints->Count;

     A_x = safe_cast<c100PointAtom^>(cloudOfPoints[0])->X;
     A_y = safe_cast<c100PointAtom^>(cloudOfPoints[0])->Y;
     B_x = safe_cast<c100PointAtom^>(cloudOfPoints[cloudOfPoints->Count-1])->X;
     B_y = safe_cast<c100PointAtom^>(cloudOfPoints[cloudOfPoints->Count-1])->Y;
									 
     AB_a = A_y - B_y;
     AB_b = B_x - A_x;
     AB_c = A_x*B_y - B_x*A_y;

     // equation of X axis line 
				 Xaxis_a = (0-0);
				 Xaxis_b = (1-0);
				 Xaxis_c = (0*0-1*0);

				 // compute angle AB line and X axis 
				 angle_AB_Xaxis = Math::Abs( AB_a*Xaxis_a + AB_b*Xaxis_b ) / 
					                 ( Math::Sqrt( Math::Pow(AB_a,2)+Math::Pow(AB_b,2) ) * ( Math::Sqrt( Math::Pow(Xaxis_a,2)+Math::Pow(Xaxis_b,2) ) ) );
				 angle_AB_Xaxis = Math::Acos( angle_AB_Xaxis );

					// get quadrant of AB line, slope AB line - order does not matter !!!
					if ( A_x <= B_x && A_y <= B_y ){ param_sign = (-1); } else 
					if ( A_x >= B_x && A_y <= B_y ){ param_sign = (+1); } else
					if ( A_x <= B_x && A_y >= B_y ){ param_sign = (+1); } else 
					if ( A_x >= B_x && A_y >= B_y ){ param_sign = (-1); }// if else

					// compute linear regression parameters
 				sumXiYi = 0;
					sumXi = 0;
					sumYi = 0;
	 			sumXi2 = 0;
					CD_minX = double::MaxValue; 
					CD_maxX = double::MinValue; 
     for ( Int32 i=0; i < cloudOfPoints->Count; i++ ){

						   R1 = safe_cast<c100PointAtom^>(cloudOfPoints[i])->X - cmass_X;
						   R2 = safe_cast<c100PointAtom^>(cloudOfPoints[i])->Y - cmass_Y;

									xi = R1*Math::Cos( param_sign*angle_AB_Xaxis ) - R2*Math::Sin( param_sign*angle_AB_Xaxis );
									yi = R1*Math::Sin( param_sign*angle_AB_Xaxis ) + R2*Math::Cos( param_sign*angle_AB_Xaxis );

            // Console::WriteLine("xy {0} {1}",xi,yi);

									sumXiYi = sumXiYi + (xi*yi);
									sumXi = sumXi + xi;
									sumYi = sumYi + yi;
									sumXi2 = sumXi2 + Math::Pow( xi, 2 );

									if ( CD_minX > xi ){
										  CD_minX = xi;
									}// if 
									if ( CD_maxX < xi ){
										  CD_maxX = xi;
									}// if 

					}// for 

					param_n = cloudOfPoints->Count;

					param_k = ( param_n*sumXiYi - sumXi*sumYi ) / ( param_n*sumXi2 - sumXi*sumXi ); 
					param_q = ( sumXi2*sumYi - sumXi*sumXiYi ) / ( param_n*sumXi2 - sumXi*sumXi );

					// + or - angle !!!, normal angle 
					angle_CD_Xaxis = Math::Atan( param_k ); 

     C_x = CD_minX;
					C_y = (param_k*CD_minX) + param_q;

					D_x = CD_maxX;
					D_y = (param_k*CD_maxX) + param_q;

					CD_a = C_y - D_y;
					CD_b = D_x - C_x;
					CD_c = (C_x*D_y - D_x*C_y);

					leftLength  = double::MinValue; 
					rightLength = double::MinValue;

					// move and rotate to zero position and get boundary points
     for ( Int32 i=0; i < cloudOfPoints->Count; i++ ){

						   R1 = safe_cast<c100PointAtom^>(cloudOfPoints[i])->X - cmass_X;
						   R2 = safe_cast<c100PointAtom^>(cloudOfPoints[i])->Y - cmass_Y;

									G_x = R1*Math::Cos( param_sign*angle_AB_Xaxis ) - R2*Math::Sin( param_sign*angle_AB_Xaxis );
									G_y = R1*Math::Sin( param_sign*angle_AB_Xaxis ) + R2*Math::Cos( param_sign*angle_AB_Xaxis );

	        // G to CD, perpendicular line, CD:u(ab),GCD:u(-b,a),c = (-1)*(-b*Gx + a*Gy)
									GCD_a = (-1)*(D_x-C_x);
									GCD_b = (+1)*(C_y-D_y);
									GCD_c = (-1)*( ((-1)*(CD_b)*G_x) + ((+1)*(CD_a)*G_y) );

									xp_G_CD = (CD_b*GCD_c - GCD_b*CD_c)/(CD_a*GCD_b - GCD_a*CD_b);
									yp_G_CD = (CD_c*GCD_a - GCD_c*CD_a)/(CD_a*GCD_b - GCD_a*CD_b);

									R1 = Math::Sqrt( Math::Pow(C_x-xp_G_CD,2) + Math::Pow(C_y-yp_G_CD,2) );

									if ( leftLength < R1 ){
										  leftLength = R1;
												leftMaxPoint_x = xp_G_CD;
												leftMaxPoint_y = yp_G_CD;
									}// if 

									R1 = Math::Sqrt( Math::Pow(D_x-xp_G_CD,2) + Math::Pow(D_y-yp_G_CD,2) );

									if ( rightLength < R1 ){
										  rightLength = R1;
												rightMaxPoint_x = xp_G_CD;
												rightMaxPoint_y = yp_G_CD;
									}// if 
										   
					}// for 

  			R3 = (-1)*param_sign*( angle_AB_Xaxis );

					E_x = ( leftMaxPoint_x*Math::Cos( R3 ) - leftMaxPoint_y*Math::Sin( R3 ) ) + cmass_X;
					E_y = ( leftMaxPoint_x*Math::Sin( R3 ) + leftMaxPoint_y*Math::Cos( R3 ) ) + cmass_Y;

					F_x = ( rightMaxPoint_x*Math::Cos( R3 ) - rightMaxPoint_y*Math::Sin( R3 ) ) + cmass_X;
					F_y = ( rightMaxPoint_x*Math::Sin( R3 ) + rightMaxPoint_y*Math::Cos( R3 ) ) + cmass_Y;


     EF_a = E_y - F_y;
     EF_b = F_x - E_x;
     EF_c = E_x*F_y - F_x*E_y;
 
	    // compute angle EF line and X axis 
				 angle_EF_Xaxis = Math::Abs( EF_a*Xaxis_a + EF_b*Xaxis_b ) / 
				                  ( Math::Sqrt( Math::Pow(EF_a,2)+Math::Pow(EF_b,2) ) * ( Math::Sqrt( Math::Pow(Xaxis_a,2)+Math::Pow(Xaxis_b,2) ) ) );
				 angle_EF_Xaxis = Math::Acos( angle_EF_Xaxis );

					// check if distance from all points to regressed line is less than limit
					exitStatus = false;
     for ( Int32 i=0; i < cloudOfPoints->Count; i++ ){

							  R1 = Math::Abs( EF_a*safe_cast<c100PointAtom^>(cloudOfPoints[i])->X + EF_b*safe_cast<c100PointAtom^>(cloudOfPoints[i])->Y + EF_c ) /
										    Math::Sqrt( Math::Pow( EF_a,2 ) + Math::Pow( EF_b,2 ) );	 

									if ( R1 > g_distanceLimit_pointToLine ){
            exitStatus = true;
									}// if 
						   
					}// for 

					for (	Int32 i=0; i < cloudOfPoints->Count; i++ ){
						   delete( safe_cast<c100PointAtom^>(cloudOfPoints[i]) );
					}// for 
					cloudOfPoints->Clear(); 
					delete( cloudOfPoints );

					if ( exitStatus == true ){

 							return false;

					}// if 

					return true;  // clouds item_1 and item_2 can be merged 

}// public: System::Boolean canBeMerged()


public: System::Int32 lineImprovement(){

Int32 RI1 = 0;

double R1 = 0;
double R2 = 0;
double R3 = 0;

double xi = 0;
double yi = 0;

double cmass_X = 0;
double cmass_Y = 0;

double sumXiYi = 0;
double sumXi = 0;
double sumYi = 0;
double sumXi2 = 0;

double param_n = 0;
double param_k = 0;
double param_q = 0;
double param_sign = 0;

Int32 param_orderAB = 0;
Int32 param_orderEF = 0;

double A_x = 0;
double A_y = 0;
double B_x = 0;
double B_y = 0;
double C_x = 0;
double C_y = 0;
double D_x = 0;
double D_y = 0;
double E_x = 0;
double E_y = 0;
double F_x = 0;
double F_y = 0;
double G_x = 0;
double G_y = 0;

double AB_a = 0;
double AB_b = 0;
double AB_c = 0;

double CD_a = 0;
double CD_b = 0;
double CD_c = 0;

double EF_a = 0;
double EF_b = 0;
double EF_c = 0;

double GCD_a = 0;
double GCD_b = 0;
double GCD_c = 0;

double Xaxis_a = 0;
double Xaxis_b = 0;
double Xaxis_c = 0;

double angle_AB_Xaxis = 0;
double angle_CD_Xaxis = 0;
double angle_CD2_Xaxis = 0;
double angle_EF_Xaxis = 0;

double CD_minX = 0;
double CD_maxX = 0;
double CD_minY = 0;
double CD_maxY = 0;

double xp_G_CD = 0;
double yp_G_CD = 0;

double leftLength = 0;
double rightLength = 0;

double leftMaxPoint_x = 0;
double leftMaxPoint_y = 0;

double rightMaxPoint_x = 0;
double rightMaxPoint_y = 0;

//**********************



				 // line improving position - fitting
					for ( Int32 i=0; i < WallsBunch_1->Count ; i++ ){

						   R1 = 0;
									R2 = 0;
						   for ( Int32 j=0; j < safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray->Count; j++ ){

						       R1 = R1 + safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[j] )->X;
						       R2 = R2 + safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[j] )->Y;

									}// for 
									cmass_X = R1 / safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray->Count;
									cmass_Y = R2 / safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray->Count;

         A_x = safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X1; 
         A_y = safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y1;
         B_x = safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X2; 
         B_y = safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y2;
									 
         AB_a = A_y - B_y;
         AB_b = B_x - A_x;
         AB_c = A_x*B_y - B_x*A_y;

				     // equation of X axis line 
				     Xaxis_a = (0-0);
				     Xaxis_b = (1-0);
				     Xaxis_c = (0*0-1*0);

				     // compute angle AB line and X axis 
				     angle_AB_Xaxis = Math::Abs( AB_a*Xaxis_a + AB_b*Xaxis_b ) / 
					                     ( Math::Sqrt( Math::Pow(AB_a,2)+Math::Pow(AB_b,2) ) * ( Math::Sqrt( Math::Pow(Xaxis_a,2)+Math::Pow(Xaxis_b,2) ) ) );
				     angle_AB_Xaxis = Math::Acos( angle_AB_Xaxis );

									// get quadrant of AB line, slope AB line
									if ( A_x <= B_x && A_y <= B_y ){ param_sign = (-1); param_orderAB = 1; } else 
									if ( A_x >= B_x && A_y <= B_y ){ param_sign = (+1); param_orderAB = 2; } else
									if ( A_x <= B_x && A_y >= B_y ){ param_sign = (+1); param_orderAB = 3; } else 
									if ( A_x >= B_x && A_y >= B_y ){ param_sign = (-1); param_orderAB = 4; }// if else

					    // compute linear regression parameters, compute CD_minX/maxX to compute general equation of regressed line
									sumXiYi = 0;
									sumXi = 0;
									sumYi = 0;
									sumXi2 = 0;
									CD_minX = double::MaxValue; 
									CD_maxX = double::MinValue; 
         for ( Int32 j=0; j < safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray->Count; j++ ){

										   R1 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[j] )->X - cmass_X;
										   R2 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[j] )->Y - cmass_Y;

													xi = R1*Math::Cos( param_sign*angle_AB_Xaxis ) - R2*Math::Sin( param_sign*angle_AB_Xaxis );
													yi = R1*Math::Sin( param_sign*angle_AB_Xaxis ) + R2*Math::Cos( param_sign*angle_AB_Xaxis );

													sumXiYi = sumXiYi + (xi*yi);
													sumXi = sumXi + xi;
													sumYi = sumYi + yi;
													sumXi2 = sumXi2 + Math::Pow( xi, 2 );

													if ( CD_minX > xi ){
														  CD_minX = xi;
													}// if 
													if ( CD_maxX < xi ){
														  CD_maxX = xi;
													}// if 

									}// for 

									param_n = safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray->Count;

									param_k = ( param_n*sumXiYi - sumXi*sumYi ) / ( param_n*sumXi2 - sumXi*sumXi ); 
									param_q = ( sumXi2*sumYi - sumXi*sumXiYi ) / ( param_n*sumXi2 - sumXi*sumXi );

									// + or - angle !!!, normal angle
									angle_CD_Xaxis = Math::Atan( param_k ); 

         // compute and improve border points of CD line, based on CD_minX, CD_maxX
         C_x = CD_minX;
									C_y = (param_k*CD_minX) + param_q;

									D_x = CD_maxX;
									D_y = (param_k*CD_maxX) + param_q;

									CD_a = C_y - D_y;
									CD_b = D_x - C_x;
									CD_c = (C_x*D_y - D_x*C_y);


									leftLength  = double::MinValue; 
									rightLength = double::MinValue;

									// move and rotate to zero position and get boundary points
         for ( Int32 j=0; j < safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray->Count; j++ ){

										   R1 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[j] )->X - cmass_X;
										   R2 = safe_cast<c100LSRayBunchItem^>( safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->BeamArray[j] )->Y - cmass_Y;

													G_x = R1*Math::Cos( param_sign*angle_AB_Xaxis ) - R2*Math::Sin( param_sign*angle_AB_Xaxis );
													G_y = R1*Math::Sin( param_sign*angle_AB_Xaxis ) + R2*Math::Cos( param_sign*angle_AB_Xaxis );

				         // G to CD, perpendicular line, CD:u(ab),GCD:u(-b,a),c = (-1)*(-b*Gx + a*Gy)
													GCD_a = (-1)*(D_x-C_x);
													GCD_b = (+1)*(C_y-D_y);
													GCD_c = (-1)*( ((-1)*(CD_b)*G_x) + ((+1)*(CD_a)*G_y) );

													xp_G_CD = (CD_b*GCD_c - GCD_b*CD_c)/(CD_a*GCD_b - GCD_a*CD_b);
													yp_G_CD = (CD_c*GCD_a - GCD_c*CD_a)/(CD_a*GCD_b - GCD_a*CD_b);

													R1 = Math::Sqrt( Math::Pow(C_x-xp_G_CD,2) + Math::Pow(C_y-yp_G_CD,2) );

													if ( rightLength < R1 ){
														  rightLength = R1;
																rightMaxPoint_x = xp_G_CD;
																rightMaxPoint_y = yp_G_CD;
													}// if 

													R1 = Math::Sqrt( Math::Pow(D_x-xp_G_CD,2) + Math::Pow(D_y-yp_G_CD,2) );

													if ( leftLength < R1 ){
														  leftLength = R1;
																leftMaxPoint_x = xp_G_CD;
																leftMaxPoint_y = yp_G_CD;
													}// if 
										   
									}// for 


									// get back correct angle
  							R3 = (-1)*param_sign*( angle_AB_Xaxis );

									// preserve original AB point order due to angular coefficient
									if ( param_orderAB == 1 || param_orderAB == 3 ){

									   E_x = ( leftMaxPoint_x*Math::Cos( R3 ) - leftMaxPoint_y*Math::Sin( R3 ) ) + cmass_X;
									   E_y = ( leftMaxPoint_x*Math::Sin( R3 ) + leftMaxPoint_y*Math::Cos( R3 ) ) + cmass_Y;

									   F_x = ( rightMaxPoint_x*Math::Cos( R3 ) - rightMaxPoint_y*Math::Sin( R3 ) ) + cmass_X;
									   F_y = ( rightMaxPoint_x*Math::Sin( R3 ) + rightMaxPoint_y*Math::Cos( R3 ) ) + cmass_Y;

									} else
									{

									   F_x = ( leftMaxPoint_x*Math::Cos( R3 ) - leftMaxPoint_y*Math::Sin( R3 ) ) + cmass_X;
									   F_y = ( leftMaxPoint_x*Math::Sin( R3 ) + leftMaxPoint_y*Math::Cos( R3 ) ) + cmass_Y;

									   E_x = ( rightMaxPoint_x*Math::Cos( R3 ) - rightMaxPoint_y*Math::Sin( R3 ) ) + cmass_X;
									   E_y = ( rightMaxPoint_x*Math::Sin( R3 ) + rightMaxPoint_y*Math::Cos( R3 ) ) + cmass_Y;

									}// if else

									// all g_distanceLimit_pointToLine doesnot need to be satisfied with new line
									if ( Math::Abs( angle_EF_Xaxis - angle_AB_Xaxis ) <= (Math::PI*0.25) ){

									   safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X1 = E_x; 
									   safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y1 = E_y;
									   safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->X2 = F_x; 
									   safe_cast<c100ApproxLineItem^>( WallsBunch_1[i] )->Y2 = F_y;

									} else
									{

									}// if 
									

					}// for 
			
					return 0;

}// public: System::Int32 lineImprovement()

};// public ref class c100MultiLineApproximationA 

//**********************************************************
//**********************************************************

public ref class c100ParserCommands
{
public:
  Int32 cmd;

public:
		  c100ParserCommands()
				{ 
					cmd = 0;
 			}

				~c100ParserCommands(){
				}

};// public ref class c100LSItemPolar


//**********************************************************
//**********************************************************

public ref class c100InsertLocalMapToGlobalMap
{

public: 
	double	g_wTolerance;
	double	g_map_wTolerance;

 Int32 g_query_C_inside_AB;

	double g_param_split_i_dist;                 // point C or D to line AB + viceversa
	double g_param_split_i_angle_LMtoGM;         // angle AB CD / inserting
 double g_param_split_i_cut_plusLength;       // add a nonzero bit at splitting and inserting
 double g_param_split_i_cut_overHangLength;   // overhang if longer than this

 double g_param_merge_i_dist;
 double g_param_merge_i_adjacentPoint;        // point is adjacent if distance is small than 
 double g_param_merge_i_angle_GMmerging;
 double g_param_merge_i_cut_overHangLength;
 double g_param_merge_i_smallLineLength;

 double g_param_remove_i_smallLineLength;

	Boolean g_param_useMerging;
	Boolean g_param_useSmallLineRemoving;

private:
	List<Object^>^ g_GlobalMap;
	List<Object^>^ g_LocalMap;

 List<Object^>^ g_commandsList;


public:
 	
		  c100InsertLocalMapToGlobalMap( List<Object^>^ gm, List<Object^>^ lm )
				{

     g_GlobalMap = gm;
 				g_LocalMap = lm;

					g_commandsList = gcnew List<Object^>();
					CreateCommandsList();

					g_wTolerance = 0; //.5;
					g_map_wTolerance = 0.5;

					g_query_C_inside_AB = 100;

     g_param_split_i_dist = 15;
	    g_param_split_i_angle_LMtoGM = 0.45;
     g_param_split_i_cut_plusLength = 0.5;
     g_param_split_i_cut_overHangLength = 15;

     g_param_merge_i_dist = 15;
     g_param_merge_i_adjacentPoint = 15;         // max. distance for two consecutive lines
					g_param_merge_i_angle_GMmerging = 0.0872;
     g_param_merge_i_cut_overHangLength = 15;
					g_param_merge_i_smallLineLength = 15;

					g_param_remove_i_smallLineLength = 15;

					g_param_useMerging = true;
					g_param_useSmallLineRemoving = true;

				}

			 ~c100InsertLocalMapToGlobalMap()
				{

					 for ( Int32 i=0;i<g_commandsList->Count;i++){
							   delete( safe_cast<c100ParserCommands^>( g_commandsList[i] ) );
					 }// for
						g_commandsList->Clear(); 
      delete( g_commandsList );


				}// c51InsertLocalMapToGlobalMap()


public: System::Void CreateCommandsList(){

c100ParserCommands^ c = nullptr;

//*******************************

								c = gcnew c100ParserCommands();
								c->cmd = 1010;
        g_commandsList->Add( c );

					 		c = gcnew c100ParserCommands();
								c->cmd = 1011;
        g_commandsList->Add( c );

								c = gcnew c100ParserCommands();
								c->cmd = 1012;
        g_commandsList->Add( c ); 

					 		c = gcnew c100ParserCommands();
								c->cmd = 1013;
        g_commandsList->Add( c );
	

}// public: System::Void FillComandsList()

public: System::Boolean ExecuteCommandsList( Int32 i_item_GM,
									                                    Int32 i_item_LM,
									                                    double i_dist,
																													   											 	double i_angle,
																																						   		 	Boolean i_exeCut,
																																											 	double i_cut_plusLength,
																																									    double i_cut_overHangLength ){

Boolean result = false;

//*******************************


									for ( int i=0;i < g_commandsList->Count; i++ ){

												  result = LinesRelationships( i_item_GM, 
															                            i_item_LM, 
																																											safe_cast<c100ParserCommands^>( g_commandsList[i] )->cmd,
																																											i_dist,
																																											i_angle,
																																											i_exeCut,
																																											i_cut_plusLength,
																																											i_cut_overHangLength );
														if ( result == true ){
															  return true;
														}//
										  
									}// for 

									return false;


}// public: System::Void FillComandsList()

public: System::Void Run_LMtoGM(){

Boolean exitStatus = false;
Boolean resetStatus = false;

Boolean result = false;

Int32 counter_GM = 0;
Int32 counter_LM = 0;

//**********************************

									counter_LM = 0;         
									do
									{
										 counter_GM = 0;
 									 do 
											{

												  if ( ExecuteCommandsList( counter_GM,
															                         counter_LM,
																																								g_param_split_i_dist,
																																								g_param_split_i_angle_LMtoGM,
																																								true,
																																								g_param_split_i_cut_plusLength,
																																								g_param_split_i_cut_overHangLength ) == true ) {
															  resetStatus = true;
																	exitStatus = true;
														}//

														counter_GM = counter_GM + 1;

														if ( g_LocalMap->Count == 0 ){
                 exitStatus = true;
														}// if

														if ( counter_GM >= g_GlobalMap->Count ){
                 exitStatus = true;
														}// if
											
											} while ( exitStatus == false );

											counter_LM = counter_LM + 1;

											exitStatus = false;

											if ( resetStatus == true ){
												  exitStatus = false;
														resetStatus = false;
														counter_LM = 0; 
											}// if 

											if ( g_LocalMap->Count == 0 ){
              exitStatus = true;
											}// if

											if ( counter_LM >= g_LocalMap->Count ){
              exitStatus = true;
											}// if

									}	while ( exitStatus == false );

									if ( g_param_useSmallLineRemoving == true ){

									   RemoveSmallLines_GM( g_param_remove_i_smallLineLength );

									}// if 

									if ( g_param_useMerging == true ){

            GM_mergeLines( g_param_merge_i_angle_GMmerging,
			   							              g_param_merge_i_dist,
						   				              g_param_merge_i_adjacentPoint,
									   															g_param_merge_i_cut_overHangLength,
												   												g_param_merge_i_smallLineLength ); // angle_RAD dist adjacent overhangcutLength minimumLineLength

									}// if 

}// public: System::Void Run_LMtoGM(){


public: System::Void RemoveSmallLines_GM( double length ){

double R1 = 0;

double x1 = 0;
double y1 = 0;
double x2 = 0;
double y2 = 0;

Int32 RI1 = 0;

//*******************************

			RI1 = 0;
			while ( g_GlobalMap->Count != 0 && RI1 < g_GlobalMap->Count ){

					  x1 = safe_cast<c100LineItem^>(g_GlobalMap[RI1])->X1;
					  y1 = safe_cast<c100LineItem^>(g_GlobalMap[RI1])->Y1;
					  x2 = safe_cast<c100LineItem^>(g_GlobalMap[RI1])->X2;
					  y2 = safe_cast<c100LineItem^>(g_GlobalMap[RI1])->Y2;

							R1 = Math::Sqrt( Math::Pow( x1-x2,2 ) + Math::Pow( y1-y2,2 ) );

							if ( R1 <= length ){

										Object^ dummy = g_GlobalMap[ RI1 ];
										g_GlobalMap->Remove( g_GlobalMap[ RI1 ] );
										delete( dummy );

										//RI1 = 0;   // this should be enabled :-), world is not perfect :-)

							} else
							{

								 RI1 = RI1 + 1;

							}// if 

			}// while 

}// public: System::Boolean RemoveSmallLines( double lenght )

public: System::Void RecomputeLocalMapLineValues( Int32 i_item_LM ){

double x1 = 0;
double y1 = 0;

double x2 = 0;
double y2 = 0;

//**************************************


					  x1 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X1;
					  y1 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y1;
					  x2 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X2;
					  y2 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y2;

						 safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->diffX = x2 - x1;
						 safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->diffY = y1 - y2;
							safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->LengthSQR = Math::Pow( (x2 - x1),2 ) +  Math::Pow( (y2 - y1),2 );
							safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Length = Math::Sqrt( safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->LengthSQR ); 
							safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->u1 = ( x2 - x1 );
							safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->u2 = ( y2 - y1 );

       if (	x1 > x2 ){
								  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx1 = x2; 
          safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx2 = x1; 
										safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx1 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx1 - g_map_wTolerance; 
          safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx2 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx2 + g_map_wTolerance; 
							} else
						 {
			 		    safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx1 = x1; 
          safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx2 = x2; 
  								safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx1 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx1 - g_map_wTolerance; 
          safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx2 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wx2 + g_map_wTolerance; 
       }// if else
							if (	y1 > y2 ){
										safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy1 = y2; 
          safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy2 = y1;
										safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy1 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy1 - g_map_wTolerance; 
          safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy2 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy2 + g_map_wTolerance;
					  } else
							{
							  	safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy1 = y1; 
          safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy2 = y2;
 									safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy1 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy1 - g_map_wTolerance; 
          safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy2 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Wy2 + g_map_wTolerance;
							}// if else

							safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->a2 = y1 - y2; 
							safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->b2 = x2 - x1;
							safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->c2 = (x1*y2)-(x2*y1); 

							safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->a1 = y1 - y2; 
							safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->b1 = x2 - x1;
							safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->c1 = (x1*y2)-(x2*y1); 


}// public: System::Boolean RecomputeLocalMapLineValues( )

public: System::Void RecomputeGlobalMapLineValues( Int32 item ){

double x1 = 0;
double y1 = 0;

double x2 = 0;
double y2 = 0;

//**************************************

		//	if ( recomputeLM == true ){

					  x1 = safe_cast<c100LineItem^>(g_GlobalMap[item])->X1;
					  y1 = safe_cast<c100LineItem^>(g_GlobalMap[item])->Y1;
					  x2 = safe_cast<c100LineItem^>(g_GlobalMap[item])->X2;
					  y2 = safe_cast<c100LineItem^>(g_GlobalMap[item])->Y2;

						 safe_cast<c100LineItem^>(g_GlobalMap[item])->diffX = x2 - x1;
						 safe_cast<c100LineItem^>(g_GlobalMap[item])->diffY = y1 - y2;
							safe_cast<c100LineItem^>(g_GlobalMap[item])->LengthSQR = Math::Pow( (x2 - x1),2 ) +  Math::Pow( (y2 - y1),2 );
							safe_cast<c100LineItem^>(g_GlobalMap[item])->Length = Math::Sqrt( safe_cast<c100LineItem^>(g_GlobalMap[item])->LengthSQR ); 
							safe_cast<c100LineItem^>(g_GlobalMap[item])->u1 = ( x2 - x1 );
							safe_cast<c100LineItem^>(g_GlobalMap[item])->u2 = ( y2 - y1 );

       if (	x1 > x2 ){
								  safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx1 = x2; 
          safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx2 = x1; 
										safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx1 = safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx1 - g_map_wTolerance; 
          safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx2 = safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx2 + g_map_wTolerance; 
							} else
						 {
			 		    safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx1 = x1; 
          safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx2 = x2; 
  								safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx1 = safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx1 - g_map_wTolerance; 
          safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx2 = safe_cast<c100LineItem^>(g_GlobalMap[item])->Wx2 + g_map_wTolerance; 
       }// if else
							if (	y1 > y2 ){
										safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy1 = y2; 
          safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy2 = y1;
										safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy1 = safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy1 - g_map_wTolerance; 
          safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy2 = safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy2 + g_map_wTolerance;
					  } else
							{
							  	safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy1 = y1; 
          safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy2 = y2;
 									safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy1 = safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy1 - g_map_wTolerance; 
          safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy2 = safe_cast<c100LineItem^>(g_GlobalMap[item])->Wy2 + g_map_wTolerance;
							}// if else

							safe_cast<c100LineItem^>(g_GlobalMap[item])->a2 = y1 - y2; 
							safe_cast<c100LineItem^>(g_GlobalMap[item])->b2 = x2 - x1;
							safe_cast<c100LineItem^>(g_GlobalMap[item])->c2 = (x1*y2)-(x2*y1); 

							safe_cast<c100LineItem^>(g_GlobalMap[item])->a1 = y1 - y2; 
							safe_cast<c100LineItem^>(g_GlobalMap[item])->b1 = x2 - x1;
							safe_cast<c100LineItem^>(g_GlobalMap[item])->c1 = (x1*y2)-(x2*y1); 

			//	}// if 

}// public: System::Boolean RecomputeGlobalMapLineValues( )


public: System::Void GM_mergeLines( double i_angle, 
									                           double i_dist,
																																				double i_adjacentPoint,
																																				double i_cut_overHangLength,
																																				double i_minimumLength

									                          ){


Int32 j = 0;

Int32 counter = 0;

double R1 = 0;
double R2 = 0;

double RI1 = 0;
double RI2 = 0;
double RI3 = 0;
double RI4 = 0;

double Cx = 0;
double Cy = 0;
double Dx = 0;
double Dy = 0;

double x1 = 0;
double y1 = 0;

double x2 = 0;
double y2 = 0;

double A_x = 0;
double A_y = 0;
double B_x = 0;
double B_y = 0;
double C_x = 0;
double C_y = 0;
double D_x = 0;
double D_y = 0;

double AB_a = 0;
double AB_b = 0;
double AB_c = 0;

double CD_a = 0;
double CD_b = 0;
double CD_c = 0;

double CAB_a = 0;
double CAB_b = 0;
double CAB_c = 0;

double DAB_a = 0;
double DAB_b = 0;
double DAB_c = 0;

double ACD_a = 0;
double ACD_b = 0;
double ACD_c = 0;

double BCD_a = 0;
double BCD_b = 0;
double BCD_c = 0;

double CCD_a = 0;
double CCD_b = 0;
double CCD_c = 0;

double DCD_a = 0;
double DCD_b = 0;
double DCD_c = 0;

double AAB_a = 0;
double AAB_b = 0;
double AAB_c = 0;

double BAB_a = 0;
double BAB_b = 0;
double BAB_c = 0;

double A_Cp_dist = 0;
double A_Dp_dist = 0;
double B_Cp_dist = 0;
double B_Dp_dist = 0;

double A_B_dist = 0;
double B_A_dist = 0;

double xp_C_AB = 0;
double yp_C_AB = 0;

double xp_D_AB = 0;
double yp_D_AB = 0;

double xp_A_CD = 0;
double yp_A_CD = 0;

double xp_B_CD = 0;
double yp_B_CD = 0;

double xp_ABCD = 0;
double yp_ABCD = 0;

double C_AB_dist = 0;
double D_AB_dist = 0;
double A_CD_dist = 0;
double B_CD_dist = 0;

double angle_CD_AB = 0;

double ABCD_Axyp_intersect_overhangL = 0;
double ABCD_Bxyp_intersect_overhangL = 0;
double ABCD_Cxyp_intersect_overhangL = 0;
double ABCD_Dxyp_intersect_overhangL = 0;

Boolean onePoint_CorD_nearToPoint_AorB = false;

Boolean x_inside = false;
Boolean y_inside = false;

Boolean C_inside_AB = false;
Boolean C_outside_AB = false;

Boolean D_inside_AB = false;
Boolean D_outside_AB = false;

Boolean A_inside_CD = false;
Boolean A_outside_CD = false;

Boolean B_inside_CD = false;
Boolean B_outside_CD = false;

Boolean	AB_wholeLeftOrRight_CD = false;

Boolean	exitStatus = false;
Boolean	resetStatus = false;

Boolean AB_CD_intersectExistInsideABCD = false;

Boolean AB_CD_noIdenticalPoint = false;

Object^ dummy_1 = nullptr;
Object^ dummy_2 = nullptr;


//********************************************

				for ( Int32 i=0; i < g_GlobalMap->Count; i++){
					  safe_cast<c100LineItem^>(g_GlobalMap[ i ])->Tag = i;
				}// for 

											 
			 counter = 0;
			 while ( g_GlobalMap->Count != 0 && counter < g_GlobalMap->Count ){


        // 4 points, A,B,C,D, line AB, line CD, line: aX + bY + c = 0
        A_x = safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1;
        A_y = safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1;
        B_x = safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2;
        B_y = safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2;

	    			// AB line parameter, a(y1-y2)+b(x2-x1)+(x1y2-x2y1)=0
        AB_a = A_y - B_y;
        AB_b = B_x - A_x;
        AB_c = A_x*B_y - B_x*A_y;

 								exitStatus = false;
        resetStatus = false;
								j = 0;
								do
								{

          C_x = safe_cast<c100LineItem^>(g_GlobalMap[j])->X1;
          C_y = safe_cast<c100LineItem^>(g_GlobalMap[j])->Y1;
          D_x = safe_cast<c100LineItem^>(g_GlobalMap[j])->X2;
          D_y = safe_cast<c100LineItem^>(g_GlobalMap[j])->Y2;

    			  	// CD line parameter, a(y1-y2)+b(x2-x1)+(x1y2-x2y1)=0
          CD_a = C_y - D_y;
          CD_b = D_x - C_x;
          CD_c = C_x*D_y - D_x*C_y;

    				  // C to AB, perpendicular line, AB:u(ab),CAB:u(-b,a),c = (-1)*(-b*Cx + a*Cy)
          CAB_a = (-1)*(AB_b); //B_x - A_x
          CAB_b = (+1)*(AB_a); //A_y - B_y
          CAB_c = (-1)*( ((-1)*(AB_b)*C_x) + ((+1)*(AB_a)*C_y) );

    				  // D to AB, perpendicular line, AB:u(ab),DAB:u(-b,a),c = (-1)*(-b*Dx + a*Dy)
          DAB_a = (-1)*(AB_b); //B_x - A_x
          DAB_b = (+1)*(AB_a); //A_y - B_y
          DAB_c = (-1)*( ((-1)*(AB_b)*D_x) + ((+1)*(AB_a)*D_y) );

          CCD_a = (-1)*(CD_b); //B_x - A_x
          CCD_b = (+1)*(CD_a); //A_y - B_y
				      CCD_c = (-1)*( ((-1)*(CD_b)*C_x) + ((+1)*(CD_a)*C_y) ); 

				      // D to CD, perpendicular line, CD:u(ab),DCD:u(-b,a),c = (-1)*(-b*Dx + a*Dy)
          DCD_a = (-1)*(CD_b); //B_x - A_x
          DCD_b = (+1)*(CD_a); //A_y - B_y
				      DCD_c = (-1)*( ((-1)*(CD_b)*D_x) + ((+1)*(CD_a)*D_y) ); 

				      // A to AB, perpendicular line, AB:u(ab),AAB:u(-b,a),c = (-1)*(-b*Dx + a*Dy)
          AAB_a = (-1)*(AB_b); //B_x - A_x
          AAB_b = (+1)*(AB_a); //A_y - B_y
				      AAB_c = (-1)*( ((-1)*(AB_b)*A_x) + ((+1)*(AB_a)*A_y) ); 

				      // B to AB, perpendicular line, AB:u(ab),BAB:u(-b,a),c = (-1)*(-b*Cx + a*Cy)
          BAB_a = (-1)*(AB_b); //B_x - A_x
          BAB_b = (+1)*(AB_a); //A_y - B_y
				      BAB_c = (-1)*( ((-1)*(AB_b)*B_x) + ((+1)*(AB_a)*B_y) ); 


		      		// intersect of AB and line perpendicular to AB from C, xp=(b1*c2-b2*c1)/(a1*b2-a2*b1),yp=(c1*a2-c2*a1)/(a1*b2-a2*b1)
          xp_C_AB = ( AB_b*CAB_c - CAB_b*AB_c ) / ( AB_a*CAB_b - CAB_a*AB_b );
          yp_C_AB = ( AB_c*CAB_a - CAB_c*AB_a ) / ( AB_a*CAB_b - CAB_a*AB_b );

				      // distance from C to intersect point yp,yp of perpendicular line to AB, d=SQRT( (cx-xp)^2 + (cy-yp)^2 )
          C_AB_dist = Math::Sqrt( Math::Pow(C_x-xp_C_AB,2)+Math::Pow(C_y-yp_C_AB,2) );  

      				// determine if xp,yp is inside AB, between AB, on AB
				      if ( A_x <= B_x ){
					        if ( (Math::Round(xp_C_AB,4) >= Math::Round(A_x,4)) && (Math::Round(xp_C_AB,4) <= Math::Round(B_x,4)) ){
								        x_inside = true;
					        } else
							      {
								        x_inside = false;
							      }// if else
										} else
				      {
					        if ( Math::Round(xp_C_AB,4) >= Math::Round(B_x,4) && Math::Round(xp_C_AB,4) <= Math::Round(A_x,4) ) {
								        x_inside = true;
					        } else
							      {
								        x_inside = false;
							      }// if else
				      }// if else
				      if ( A_y <= B_y ){
					        if ( Math::Round(yp_C_AB,4) >= Math::Round(A_y,4) && Math::Round(yp_C_AB,4) <= Math::Round(B_y,4) ){
							         y_inside = true;
					        } else
					        {
								        y_inside = false;
					        }// if else
				      } else
				      {
					        if ( Math::Round(yp_C_AB,4) >= Math::Round(B_y,4) && Math::Round(yp_C_AB,4) <= Math::Round(A_y,4) ){
								        y_inside = true;
					        } else
					        {
								        y_inside = false;
					        }// if else
				      }// if else

      				// final resolution C (sagital) is INSIDE AB or NOT
				      if ( x_inside == true && y_inside == true ){
					        C_inside_AB = true;
							      C_outside_AB = false;
				      } else
				      {
					        C_inside_AB = false;
							      C_outside_AB = true;
				      }// if else

				      // D-AB subsidiary parameters computing

      	 		// intersect of AB and line perpendicular to AB from D, xp=(b1*c2-b2*c1)/(a1*b2-a2*b1),yp=(c1*a2-c2*a1)/(a1*b2-a2*b1)
          xp_D_AB = ( AB_b*DAB_c - DAB_b*AB_c ) / ( AB_a*DAB_b - DAB_a*AB_b );
          yp_D_AB = ( AB_c*DAB_a - DAB_c*AB_a ) / ( AB_a*DAB_b - DAB_a*AB_b );

				      // distance from D to intersect point yp,yp of perpendicular line to AB, d=SQRT( (cx-xp)^2 + (cy-yp)^2 )
          D_AB_dist = Math::Sqrt( Math::Pow(D_x-xp_D_AB,2)+Math::Pow(D_y-yp_D_AB,2) ); 

				      // determine if xp,yp is inside AB, between AB, on AB
				      if ( A_x <= B_x ){
					        if ( Math::Round(xp_D_AB,4) >= Math::Round(A_x,4) && Math::Round(xp_D_AB,4) <= Math::Round(B_x,4) ){
								        x_inside = true;
					        } else
							      {
								        x_inside = false;
							      }// if else
				      } else
				      {
					        if ( Math::Round(xp_D_AB,4) >= Math::Round(B_x,4) && Math::Round(xp_D_AB,4) <= Math::Round(A_x,4) ){
								        x_inside = true;
					        } else
							      {
								        x_inside = false;
							      }// if else
				      }// if else
				      if ( A_y <= B_y ){
					        if ( Math::Round(yp_D_AB,4) >= Math::Round(A_y,4) && Math::Round(yp_D_AB,4) <= Math::Round(B_y,4) ){
								        y_inside = true;
					        } else
					        {
								        y_inside = false;
					        }// if else
				      } else
				      {
					        if ( Math::Round(yp_D_AB,4) >= Math::Round(B_y,4) && Math::Round(yp_D_AB,4) <= Math::Round(A_y,4) ){
								        y_inside = true;
					        } else
					        {
								        y_inside = false;
					        }// if else
				      }// if else

				      // final resolution C (sagital) is INSIDE AB or NOT
				      if ( x_inside == true && y_inside == true ){
					        D_inside_AB = true;
							      D_outside_AB = false;
				      } else
				      {
					        D_inside_AB = false;
							      D_outside_AB = true;
				      }// if else

				      // compute angle CD line and AB line
				      angle_CD_AB = Math::Abs( CD_a*AB_a + CD_b*AB_b ) / 
					                   ( Math::Sqrt( Math::Pow(CD_a,2)+Math::Pow(CD_b,2) ) * ( Math::Sqrt( Math::Pow(AB_a,2)+Math::Pow(AB_b,2) ) ) );
     				 angle_CD_AB = Math::Acos( angle_CD_AB );

				      RI1 = Math::Sign( DCD_a*B_x + DCD_b*B_y + DCD_c );
				      RI2 = Math::Sign( DCD_a*A_x + DCD_b*A_y + DCD_c );
				      RI3 = Math::Sign( CCD_a*B_x + CCD_b*B_y + CCD_c );
				      RI4 = Math::Sign( CCD_a*A_x + CCD_b*A_y + CCD_c );

				      if ( RI1 == RI2 && RI2 == RI3 && RI3 == RI4 ){
					        AB_wholeLeftOrRight_CD = true;
										} else
				      {
             AB_wholeLeftOrRight_CD = false;
				      }// if

										A_B_dist = Math::Sqrt( Math::Pow(A_x-B_x,2)+Math::Pow(A_y-B_y,2) ); 
										B_A_dist = Math::Sqrt( Math::Pow(B_x-A_x,2)+Math::Pow(B_y-A_y,2) ); 

										A_Cp_dist = Math::Sqrt( Math::Pow(A_x-xp_C_AB,2)+Math::Pow(A_y-yp_C_AB,2) ); 
										A_Dp_dist = Math::Sqrt( Math::Pow(A_x-xp_D_AB,2)+Math::Pow(A_y-yp_D_AB,2) ); 
										B_Cp_dist = Math::Sqrt( Math::Pow(B_x-xp_C_AB,2)+Math::Pow(B_y-yp_C_AB,2) ); 
										B_Dp_dist = Math::Sqrt( Math::Pow(B_x-xp_D_AB,2)+Math::Pow(B_y-yp_D_AB,2) ); 

										if ( ( A_Cp_dist < i_adjacentPoint ) || 
											    ( A_Dp_dist < i_adjacentPoint ) || 
															( B_Cp_dist < i_adjacentPoint ) ||
															( B_Dp_dist < i_adjacentPoint ) ){ 

													onePoint_CorD_nearToPoint_AorB	= true;

										} else
										{
													onePoint_CorD_nearToPoint_AorB	= false; 
										}// if

										// find for any ident points
										if ( Math::Round( C_x, 5 ) != Math::Round( A_x, 5 ) && 
											    Math::Round( C_x, 5 ) != Math::Round( B_x, 5 ) && 
															Math::Round( D_x, 5 ) != Math::Round( A_x, 5 ) && 
															Math::Round( D_x, 5 ) != Math::Round( B_x, 5 ) &&
											    Math::Round( C_y, 5 ) != Math::Round( A_y, 5 ) && 
															Math::Round( C_y, 5 ) != Math::Round( B_y, 5 ) && 
															Math::Round( D_y, 5 ) != Math::Round( A_y, 5 ) &&
															Math::Round( D_y, 5 ) != Math::Round( B_y, 5 ) ){

											  AB_CD_noIdenticalPoint = true;

										} else
										{
										   AB_CD_noIdenticalPoint = false;
										}// if 

										// if intersect AB CD exist 
										if ( (AB_a*CD_b - AB_b*CD_a) != 0 && AB_CD_noIdenticalPoint == true ){

										   xp_ABCD = ( AB_b*CD_c - CD_b*AB_c ) / ( AB_a*CD_b - CD_a*AB_b );
										   yp_ABCD = ( AB_c*CD_a - CD_c*AB_a ) / ( AB_a*CD_b - CD_a*AB_b );

													RI1 = 0;
													if ( A_x <= B_x ){
														  if ( xp_ABCD >= A_x && xp_ABCD <= B_x ){
																	  RI1 = RI1 + 1;
														  }// if 
													} else
													{
														  if ( xp_ABCD >= B_x && xp_ABCD <= A_x ){
																	  RI1 = RI1 + 1;
														  }// 
													}// if  
													if ( A_y <= B_y ){
														  if ( yp_ABCD >= A_y && yp_ABCD <= B_y ){
																	  RI1 = RI1 + 1;
														  }// if 
													} else
													{
														  if ( yp_ABCD >= B_y && yp_ABCD <= A_y ){
																	  RI1 = RI1 + 1;
														  }// 
													}// if  

													if ( C_x <= D_x ){
														  if ( xp_ABCD >= C_x && xp_ABCD <= D_x ){
																	  RI1 = RI1 + 1;
														  }// if 
													} else
													{
														  if ( xp_ABCD >= D_x && xp_ABCD <= C_x ){
																	  RI1 = RI1 + 1;
														  }// 
													}// if  
													if ( C_y <= D_y ){
														  if ( yp_ABCD >= C_y && yp_ABCD <= D_y ){
																	  RI1 = RI1 + 1;
														  }// if 
													} else
													{
														  if ( yp_ABCD >= D_y && yp_ABCD <= C_y ){
																	  RI1 = RI1 + 1;
														  }// 
													}// if  

													if ( RI1 == 4 ){
                AB_CD_intersectExistInsideABCD = true;
													} else
													{
										      AB_CD_intersectExistInsideABCD = false;
													}// if 

														ABCD_Axyp_intersect_overhangL = Math::Sqrt( Math::Pow(xp_ABCD-A_x, 2) + Math::Pow(yp_ABCD-A_y, 2) );
														ABCD_Bxyp_intersect_overhangL = Math::Sqrt( Math::Pow(xp_ABCD-B_x, 2) + Math::Pow(yp_ABCD-B_y, 2) );
														ABCD_Cxyp_intersect_overhangL = Math::Sqrt( Math::Pow(xp_ABCD-C_x, 2) + Math::Pow(yp_ABCD-C_y, 2) );
														ABCD_Dxyp_intersect_overhangL = Math::Sqrt( Math::Pow(xp_ABCD-D_x, 2) + Math::Pow(yp_ABCD-D_y, 2) );

										}// if 

										//************************************************
										if ( j != counter ){

											  // two successive lines, can be merged 
											  if ( ( angle_CD_AB < i_angle ) &&
														    ( C_AB_dist < i_dist ) &&
														    ( D_AB_dist < i_dist ) &&
																		//( C_outside_AB == true ) &&
																		//( D_outside_AB == true ) &&
																		( AB_wholeLeftOrRight_CD == true ) && 
																		( onePoint_CorD_nearToPoint_AorB == true ) ){

                if ( ( A_B_dist  < A_Cp_dist ) && //AB CD
																	    ( A_B_dist  < A_Dp_dist ) &&
																					( A_Cp_dist < A_Dp_dist ) &&
																					( B_Cp_dist < A_Cp_dist ) ) {

										         safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2 = safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X2; 
										         safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2 = safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y2;

										         Object^ dummy = g_GlobalMap[ j ];
										         g_GlobalMap->Remove( g_GlobalMap[ j ] );
										         delete( dummy );

																   resetStatus = true; // RESET i

																} else if ( ( A_B_dist  < A_Cp_dist ) &&  // AB DC
																	           ( A_B_dist  < A_Dp_dist ) &&
																					       ( A_Dp_dist < A_Cp_dist ) &&
																												( B_Dp_dist < A_Dp_dist ) ) {

										         safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2 = safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X1; 
										         safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2 = safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y1;

										         Object^ dummy = g_GlobalMap[ j ];
										         g_GlobalMap->Remove( g_GlobalMap[ j ] );
										         delete( dummy );

																   resetStatus = true; // RESET i

																} else if ( ( B_A_dist  < B_Cp_dist ) && // BA CD
																	           ( B_A_dist  < B_Dp_dist ) &&
																					       ( B_Cp_dist < B_Dp_dist ) &&
																												( A_Cp_dist < B_Cp_dist ) ) {

										         safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 = safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X2; 
										         safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 = safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y2;

										         Object^ dummy = g_GlobalMap[ j ];
										         g_GlobalMap->Remove( g_GlobalMap[ j ] );
										         delete( dummy );

																   resetStatus = true; // RESET i

																} else if ( ( B_A_dist  < B_Cp_dist ) &&  // BA DC 
																	           ( B_A_dist  < B_Dp_dist ) &&
																					       ( B_Dp_dist < B_Cp_dist ) &&
																												( A_Dp_dist < B_Dp_dist ) ) { 

										         safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 = safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X1; 
										         safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 = safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y1;

										         Object^ dummy = g_GlobalMap[ j ];
										         g_GlobalMap->Remove( g_GlobalMap[ j ] );
										         delete( dummy );

																   resetStatus = true; // RESET i

																}// if else

													} else if ( AB_CD_intersectExistInsideABCD == true && 
														           ABCD_Axyp_intersect_overhangL <= i_cut_overHangLength &&
														           ABCD_Bxyp_intersect_overhangL <= i_cut_overHangLength &&
														           ABCD_Cxyp_intersect_overhangL <= i_cut_overHangLength &&
														           ABCD_Dxyp_intersect_overhangL <= i_cut_overHangLength ){ 

										         Object^ dummy = g_GlobalMap[ j ];
										         g_GlobalMap->Remove( g_GlobalMap[ j ] );
										         delete( dummy );

																   resetStatus = true; // RESET i
													
													} else if ( AB_CD_intersectExistInsideABCD == true &&
																								 safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Tag == 0 &&
																									safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Tag == 0 ){ 


																			if ( ABCD_Cxyp_intersect_overhangL >= 0.5 && ABCD_Cxyp_intersect_overhangL <= i_cut_overHangLength ){
																			  	safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X1 = xp_ABCD;
																			  	safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y1 = yp_ABCD;
																					//	Console::WriteLine("c over");
																      resetStatus = true; // RESET i
																			}// if 
																			if ( ABCD_Dxyp_intersect_overhangL >= 0.5 && ABCD_Dxyp_intersect_overhangL <= i_cut_overHangLength ){
																			  	safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X2 = xp_ABCD;
																			  	safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y2 = yp_ABCD;
																						//Console::WriteLine("d over");
																      resetStatus = true; // RESET i
																			}// if 
																			if ( ABCD_Axyp_intersect_overhangL >= 0.5 && ABCD_Axyp_intersect_overhangL <= i_cut_overHangLength ){
																			  	safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 = xp_ABCD;
																			  	safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 = yp_ABCD;
																						//Console::WriteLine("a over");
																      resetStatus = true; // RESET i
																			}// if 
																			if ( ABCD_Bxyp_intersect_overhangL >= 0.5 && ABCD_Bxyp_intersect_overhangL <= i_cut_overHangLength ){
																			  	safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2 = xp_ABCD;
																			  	safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2 = yp_ABCD;
																					//	Console::WriteLine("b over");
																      resetStatus = true; // RESET i
																			}// if 


																			if ( resetStatus == true ){

																			   R1 = Math::Sqrt( Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X1 - safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X2, 2 ) +
																				                   Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y1 - safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y2, 2 ) );

   																			dummy_1 = nullptr;
			   																if ( R1 < i_minimumLength ){

						   				            Object^ dummy_1 = g_GlobalMap[ j ];
   
			   																}// if 

						   													R1 = Math::Sqrt( Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2, 2 ) +
									   											                Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2, 2 ) );

												   							dummy_2 = nullptr;
															   				if ( R1 < i_minimumLength ){

										               Object^ dummy_2 = g_GlobalMap[ counter ];

																			   }// if 

																	   		if ( dummy_1 != nullptr ){
										               g_GlobalMap->Remove( dummy_1 );
										               delete( dummy_1 );
																		   	}// if

																		   	if ( dummy_2 != nullptr ){
																			      g_GlobalMap->Remove( dummy_2 );
										               delete( dummy_2 );
																		   	}// if 

																			}// if 

																	 
													} else if ( AB_CD_intersectExistInsideABCD == false &&
														           C_inside_AB == true &&
														           // D_inside_AB == false &&
																									C_AB_dist <= i_cut_overHangLength &&
																									C_AB_dist >= 0.5 ){ //&&
																									//AB_CD_noIdenticalPoint == true ){ 

																							
																			safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X1 = xp_C_AB; // C
																			safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y1 = yp_C_AB;

																			R1 = Math::Sqrt( Math::Pow( xp_C_AB - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1, 2)+ 
																				                Math::Pow( yp_C_AB - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1, 2) ); 
																			R2 = Math::Sqrt( Math::Pow( xp_C_AB - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2, 2)+ 
																				                Math::Pow( yp_C_AB - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2, 2) ); 

																			if ( R1 <= i_cut_overHangLength ){
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 = xp_C_AB; // A
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 = yp_C_AB;
																			}// if 
																			if ( R2 <= i_cut_overHangLength ){
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2 = xp_C_AB; // A
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2 = yp_C_AB;
																			}// if 

																		 safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Tag = 1; 
																		 safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Tag = 1; 

																			R1 = Math::Sqrt( Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2, 2 ) +
																				                Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2, 2 ) );

																	
																			if ( R1 < i_minimumLength ){

										            Object^ dummy = g_GlobalMap[ counter ];
										            g_GlobalMap->Remove( g_GlobalMap[ counter ] );
										            delete( dummy );

																			}// if 

																			resetStatus = true; // RESET i

													} else if ( AB_CD_intersectExistInsideABCD == false &&
														           D_inside_AB == true &&
														           // C_inside_AB == false &&
																									D_AB_dist <= i_cut_overHangLength &&
																									D_AB_dist >= 0.5 ){ //&&
																									//AB_CD_noIdenticalPoint == true ){ 

																			safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X2 = xp_D_AB; // 
																			safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y2 = yp_D_AB;

																			R1 = Math::Sqrt( Math::Pow( xp_D_AB - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1, 2)+ 
																				                Math::Pow( yp_D_AB - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1, 2) ); 
																			R2 = Math::Sqrt( Math::Pow( xp_D_AB - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2, 2)+ 
																				                Math::Pow( yp_D_AB - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2, 2) ); 

																			if ( R1 <= i_cut_overHangLength ){
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 = xp_D_AB; // A
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 = yp_D_AB;
																			}// if 
																			if ( R2 <= i_cut_overHangLength ){
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2 = xp_D_AB; // A
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2 = yp_D_AB;
																			}// if 

																		 safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Tag = 1; 
																		 safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Tag = 1; 

																			R1 = Math::Sqrt( Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2, 2 ) +
																				                Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2, 2 ) );

																		

																			if ( R1 < i_minimumLength ){

										            Object^ dummy = g_GlobalMap[ counter ];
										            g_GlobalMap->Remove( g_GlobalMap[ counter ] );
										            delete( dummy );

																			}// if

														     resetStatus = true; // RESET i
																		

												//	}// if 

													} else if ( AB_CD_intersectExistInsideABCD == false &&
														           A_inside_CD == true &&
														           // B_inside_CD == false &&
																									A_CD_dist <= i_cut_overHangLength &&
																									A_CD_dist >= 0.5 ){ //&&
																									//AB_CD_noIdenticalPoint == true ){ 

																			safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X1 = xp_A_CD; // C
																			safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y1 = yp_A_CD;

																			R1 = Math::Sqrt( Math::Pow( xp_A_CD - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1, 2)+ 
																				                Math::Pow( yp_A_CD - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1, 2) ); 
																			R2 = Math::Sqrt( Math::Pow( xp_A_CD - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2, 2)+ 
																				                Math::Pow( yp_A_CD - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2, 2) ); 

																			if ( R1 <= i_cut_overHangLength ){
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 = xp_A_CD; // A
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 = yp_A_CD;
																			}// if 
																			if ( R2 <= i_cut_overHangLength ){
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2 = xp_A_CD; // A
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2 = yp_A_CD;
																			}// if 

																		 safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Tag = 1; 
																		 safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Tag = 1; 

																			R1 = Math::Sqrt( Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2, 2 ) +
																				                Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2, 2 ) );

																			
																			if ( R1 < i_minimumLength ){

										            Object^ dummy = g_GlobalMap[ counter ];
										            g_GlobalMap->Remove( g_GlobalMap[ counter ] );
										            delete( dummy );

																			}// if 

																			resetStatus = true; // RESET i


													} else if ( AB_CD_intersectExistInsideABCD == false &&
														           B_inside_CD == true &&
														           // A_inside_CD == false &&
																									B_CD_dist <= i_cut_overHangLength &&
																									B_CD_dist >= 0.5 ){ //&&
																									//AB_CD_noIdenticalPoint == true ){ 

                    
																			safe_cast<c100LineItem^>(g_GlobalMap[ j ])->X2 = xp_B_CD; // D
																			safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Y2 = yp_B_CD;

																			R1 = Math::Sqrt( Math::Pow( xp_B_CD - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1, 2)+ 
																				                Math::Pow( yp_B_CD - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1, 2) ); 
																			R2 = Math::Sqrt( Math::Pow( xp_B_CD - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2, 2)+ 
																				                Math::Pow( yp_B_CD - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2, 2) ); 

																			if ( R1 <= i_cut_overHangLength ){
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 = xp_B_CD; // A
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 = yp_B_CD;
																			}// if 
																			if ( R2 <= i_cut_overHangLength ){
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2 = xp_B_CD; // A
																				  safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2 = yp_B_CD;
																			}// if 

																		 safe_cast<c100LineItem^>(g_GlobalMap[ j ])->Tag = 1; 
																		 safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Tag = 1; 

																			R1 = Math::Sqrt( Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X1 - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->X2, 2 ) +
																				                Math::Pow( safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y1 - safe_cast<c100LineItem^>(g_GlobalMap[ counter ])->Y2, 2 ) );

																
																			if ( R1 < i_minimumLength ){

										            Object^ dummy = g_GlobalMap[ counter ];
										            g_GlobalMap->Remove( g_GlobalMap[ counter ] );
										            delete( dummy );

																      resetStatus = true; // RESET i

																			}// if

														     resetStatus = true; // RESET i
																		

													}// if 

										}// if ( counter != j )

          j = j + 1;

								  if ( resetStatus == true ){
											  exitStatus = true;
										}// if 

										if ( j >= g_GlobalMap->Count ){
											  exitStatus = true;
										}// if

								} while ( exitStatus == false );
						
								if ( resetStatus == true ){

											for ( Int32 j=0;j < g_GlobalMap->Count; j++){

               RecomputeGlobalMapLineValues( j );

											}// for 

											counter = 0; // RESET i

								} else
								{

									  counter = counter + 1;

								}// if 

				}// while


}// public: System::Void GM_mergeLines()

public: System::Boolean LinesRelationships( Int32 i_item_GM,
									                                   Int32 i_item_LM,
									                                   Int32 i_query,
									                                   double i_dist,
																													   												double i_angle,
																																						   			Boolean i_exeCut,
																																												double i_cut_plusLength,
																																									   double i_cut_overHangLength ){

double R1 = 0;
double R2 = 0;

double RI1 = 0;
double RI2 = 0;
double RI3 = 0;
double RI4 = 0;

double Cx = 0;
double Cy = 0;
double Dx = 0;
double Dy = 0;

double x1 = 0;
double y1 = 0;

double x2 = 0;
double y2 = 0;

double A_x = 0;
double A_y = 0;
double B_x = 0;
double B_y = 0;
double C_x = 0;
double C_y = 0;
double D_x = 0;
double D_y = 0;

double AB_a = 0;
double AB_b = 0;
double AB_c = 0;

double CD_a = 0;
double CD_b = 0;
double CD_c = 0;

double CAB_a = 0;
double CAB_b = 0;
double CAB_c = 0;

double DAB_a = 0;
double DAB_b = 0;
double DAB_c = 0;

double ACD_a = 0;
double ACD_b = 0;
double ACD_c = 0;

double BCD_a = 0;
double BCD_b = 0;
double BCD_c = 0;

double CCD_a = 0;
double CCD_b = 0;
double CCD_c = 0;

double DCD_a = 0;
double DCD_b = 0;
double DCD_c = 0;

double AAB_a = 0;
double AAB_b = 0;
double AAB_c = 0;

double BAB_a = 0;
double BAB_b = 0;
double BAB_c = 0;

double Xaxis_a = 0;
double Xaxis_b = 0;
double Xaxis_c = 0;

double Yaxis_a = 0;
double Yaxis_b = 0;
double Yaxis_c = 0;

double xp_C_AB = 0;
double yp_C_AB = 0;

double xp_D_AB = 0;
double yp_D_AB = 0;

double xp_A_CD = 0;
double yp_A_CD = 0;

double xp_B_CD = 0;
double yp_B_CD = 0;

double C_overhangL = 0;
double D_overhangL = 0;
double A_overhangL = 0;
double B_overhangL = 0;


double CD_length = 0;
double AB_length = 0;

double angle_CD_Xaxis = 0;

double slope_CD_x = 0;
double slope_CD_y = 0;

double angle_AB_Xaxis = 0;
double angle_CD_AB = 0;

double slope_AB_x = 0;
double slope_AB_y = 0;

double C_AB_dist = 0;
double D_AB_dist = 0;
double A_CD_dist = 0;
double B_CD_dist = 0;


Boolean recomputeLM = false;

Boolean x_inside = false;
Boolean y_inside = false;

Boolean C_inside_AB = false;
Boolean C_outside_AB = false;

Boolean D_inside_AB = false;
Boolean D_outside_AB = false;

Boolean A_inside_CD = false;
Boolean A_outside_CD = false;

Boolean B_inside_CD = false;
Boolean B_outside_CD = false;

Boolean	C_closeTo_Ap = false;
Boolean	C_closeTo_Bp = false;

Boolean	D_closeTo_Ap = false;
Boolean	D_closeTo_Bp = false;

Boolean	A_closeTo_Cp = false;
Boolean	A_closeTo_Dp = false;

Boolean	B_closeTo_Cp = false;
Boolean	B_closeTo_Dp = false;

Boolean	CD_inside_AB = false;
Boolean	AB_inside_CD = false;

Boolean	AB_wholeLeftOrRight_CD = false;
Boolean	CD_wholeLeftOrRight_AB = false;

Boolean AB_onIdenticalSide = false;
Boolean CD_onIdenticalSide = false;

Boolean CD_inside_AB_andContrary = false;

Boolean CorD_inside_AB = false;
Boolean AorB_inside_CD = false;

Boolean C_outside_AB_overhangIsShort = false;
Boolean D_outside_AB_overhangIsShort = false;
Boolean A_outside_CD_overhangIsShort = false;
Boolean B_outside_CD_overhangIsShort = false;

Boolean CorD_outside_AB_overhangIsShort = false;
Boolean AorB_outside_CD_overhangIsShort = false;

Boolean C_outside_AB_overhangIsLong = false;
Boolean D_outside_AB_overhangIsLong = false;
Boolean CD_outside_AB_overhangIsLong = false;

Boolean C_outside_D_inside_AB_overhangIsLong = false;
Boolean D_outside_C_inside_AB_overhangIsLong = false;



//*******************************************

    // 4 points, A,B,C,D, line AB, line CD, line: aX + bY + c = 0
    A_x = safe_cast<c100LineItem^>(g_GlobalMap[i_item_GM])->X1;
    A_y = safe_cast<c100LineItem^>(g_GlobalMap[i_item_GM])->Y1;
    B_x = safe_cast<c100LineItem^>(g_GlobalMap[i_item_GM])->X2;
    B_y = safe_cast<c100LineItem^>(g_GlobalMap[i_item_GM])->Y2;

    C_x = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X1;
    C_y = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y1;
    D_x = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X2;
    D_y = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y2;


				// AB line parameter, a(y1-y2)+b(x2-x1)+(x1y2-x2y1)=0
    AB_a = A_y - B_y;
    AB_b = B_x - A_x;
    AB_c = A_x*B_y - B_x*A_y;

				// CD line parameter, a(y1-y2)+b(x2-x1)+(x1y2-x2y1)=0
    CD_a = C_y - D_y;
    CD_b = D_x - C_x;
    CD_c = C_x*D_y - D_x*C_y;

				// C to AB, perpendicular line, AB:u(ab),CAB:u(-b,a),c = (-1)*(-b*Cx + a*Cy)
    CAB_a = (-1)*(AB_b); //B_x - A_x
    CAB_b = (+1)*(AB_a); //A_y - B_y
    CAB_c = (-1)*( ((-1)*(AB_b)*C_x) + ((+1)*(AB_a)*C_y) );

				// D to AB, perpendicular line, AB:u(ab),DAB:u(-b,a),c = (-1)*(-b*Dx + a*Dy)
    DAB_a = (-1)*(AB_b); //B_x - A_x
    DAB_b = (+1)*(AB_a); //A_y - B_y
    DAB_c = (-1)*( ((-1)*(AB_b)*D_x) + ((+1)*(AB_a)*D_y) );

				// A to CD, perpendicular line, CD:u(ab),ACD:u(-b,a),c = (-1)*(-b*Ax + a*Ay)
    ACD_a = (-1)*(CD_b); //B_x - A_x
    ACD_b = (+1)*(CD_a); //A_y - B_y
    ACD_c = (-1)*( ((-1)*(CD_b)*A_x) + ((+1)*(CD_a)*A_y) );

				// B to CD, perpendicular line, CD:u(ab),BCD:u(-b,a),c = (-1)*(-b*Bx + a*By)
    BCD_a = (-1)*(CD_b); //B_x - A_x
    BCD_b = (+1)*(CD_a); //A_y - B_y
    BCD_c = (-1)*( ((-1)*(CD_b)*B_x) + ((+1)*(CD_a)*B_y) );

				// C to CD, perpendicular line, CD:u(ab),DCD:u(-b,a),c = (-1)*(-b*Cx + a*Cy)
    CCD_a = (-1)*(CD_b); //B_x - A_x
    CCD_b = (+1)*(CD_a); //A_y - B_y
				CCD_c = (-1)*( ((-1)*(CD_b)*C_x) + ((+1)*(CD_a)*C_y) ); 

				// D to CD, perpendicular line, CD:u(ab),DCD:u(-b,a),c = (-1)*(-b*Dx + a*Dy)
    DCD_a = (-1)*(CD_b); //B_x - A_x
    DCD_b = (+1)*(CD_a); //A_y - B_y
				DCD_c = (-1)*( ((-1)*(CD_b)*D_x) + ((+1)*(CD_a)*D_y) ); 

				// A to AB, perpendicular line, AB:u(ab),AAB:u(-b,a),c = (-1)*(-b*Dx + a*Dy)
    AAB_a = (-1)*(AB_b); //B_x - A_x
    AAB_b = (+1)*(AB_a); //A_y - B_y
				AAB_c = (-1)*( ((-1)*(AB_b)*A_x) + ((+1)*(AB_a)*A_y) ); 

				// B to AB, perpendicular line, AB:u(ab),BAB:u(-b,a),c = (-1)*(-b*Cx + a*Cy)
    BAB_a = (-1)*(AB_b); //B_x - A_x
    BAB_b = (+1)*(AB_a); //A_y - B_y
				BAB_c = (-1)*( ((-1)*(AB_b)*B_x) + ((+1)*(AB_a)*B_y) ); 


				// equation of X axis line 
				Xaxis_a = (0-0);
				Xaxis_b = (1-0);
				Xaxis_c = (0*0-1*0);

				// equation of Y axis line
				Yaxis_a = (0-1);
				Yaxis_b = (0-0);
				Yaxis_c = (0*1-0*0);

				// C-AB subsidiary parameters computing

				// intersect of AB and line perpendicular to AB from C, xp=(b1*c2-b2*c1)/(a1*b2-a2*b1),yp=(c1*a2-c2*a1)/(a1*b2-a2*b1)
    xp_C_AB = ( AB_b*CAB_c - CAB_b*AB_c ) / ( AB_a*CAB_b - CAB_a*AB_b );
    yp_C_AB = ( AB_c*CAB_a - CAB_c*AB_a ) / ( AB_a*CAB_b - CAB_a*AB_b );

				// distance from C to intersect point yp,yp of perpendicular line to AB, d=SQRT( (cx-xp)^2 + (cy-yp)^2 )
    C_AB_dist = Math::Sqrt( Math::Pow(C_x-xp_C_AB,2)+Math::Pow(C_y-yp_C_AB,2) ); 

				// determine if xp,yp is inside AB, between AB, on AB
				if ( A_x <= B_x ){
					if ( (Math::Round(xp_C_AB,4) >= Math::Round(A_x,4)) && (Math::Round(xp_C_AB,4) <= Math::Round(B_x,4)) ){
								  x_inside = true;
					  } else
							{
								  x_inside = false;
							}// if else
				} else
				{
					  if ( Math::Round(xp_C_AB,4) >= Math::Round(B_x,4) && Math::Round(xp_C_AB,4) <= Math::Round(A_x,4) ) {
								  x_inside = true;
					  } else
							{
								  x_inside = false;
							}// if else
				}// if else
				if ( A_y <= B_y ){
					  if ( Math::Round(yp_C_AB,4) >= Math::Round(A_y,4) && Math::Round(yp_C_AB,4) <= Math::Round(B_y,4) ){
								   y_inside = true;
					  } else
					  {
								   y_inside = false;
					  }// if else
				} else
				{
					  if ( Math::Round(yp_C_AB,4) >= Math::Round(B_y,4) && Math::Round(yp_C_AB,4) <= Math::Round(A_y,4) ){
								   y_inside = true;
					  } else
					  {
								   y_inside = false;
					  }// if else
				}// if else

				// final resolution C (sagital) is INSIDE AB or NOT
				if ( x_inside == true && y_inside == true ){
					  C_inside_AB = true;
							C_outside_AB = false;
				} else
				{
					  C_inside_AB = false;
							C_outside_AB = true;
				}// if else

				// D-AB subsidiary parameters computing

	 		// intersect of AB and line perpendicular to AB from D, xp=(b1*c2-b2*c1)/(a1*b2-a2*b1),yp=(c1*a2-c2*a1)/(a1*b2-a2*b1)
    xp_D_AB = ( AB_b*DAB_c - DAB_b*AB_c ) / ( AB_a*DAB_b - DAB_a*AB_b );
    yp_D_AB = ( AB_c*DAB_a - DAB_c*AB_a ) / ( AB_a*DAB_b - DAB_a*AB_b );

				// distance from D to intersect point yp,yp of perpendicular line to AB, d=SQRT( (cx-xp)^2 + (cy-yp)^2 )
    D_AB_dist = Math::Sqrt( Math::Pow(D_x-xp_D_AB,2)+Math::Pow(D_y-yp_D_AB,2) ); 

				// determine if xp,yp is inside AB, between AB, on AB
				if ( A_x <= B_x ){
					  if ( Math::Round(xp_D_AB,4) >= Math::Round(A_x,4) && Math::Round(xp_D_AB,4) <= Math::Round(B_x,4) ){
								  x_inside = true;
					  } else
							{
								  x_inside = false;
							}// if else
				} else
				{
					  if ( Math::Round(xp_D_AB,4) >= Math::Round(B_x,4) && Math::Round(xp_D_AB,4) <= Math::Round(A_x,4) ){
								  x_inside = true;
					  } else
							{
								  x_inside = false;
							}// if else
				}// if else
				if ( A_y <= B_y ){
					  if ( Math::Round(yp_D_AB,4) >= Math::Round(A_y,4) && Math::Round(yp_D_AB,4) <= Math::Round(B_y,4) ){
								   y_inside = true;
					  } else
					  {
								   y_inside = false;
					  }// if else
				} else
				{
					  if ( Math::Round(yp_D_AB,4) >= Math::Round(B_y,4) && Math::Round(yp_D_AB,4) <= Math::Round(A_y,4) ){
								   y_inside = true;
					  } else
					  {
								   y_inside = false;
					  }// if else
				}// if else

				// final resolution C (sagital) is INSIDE AB or NOT
				if ( x_inside == true && y_inside == true ){
					  D_inside_AB = true;
							D_outside_AB = false;
				} else
				{
					  D_inside_AB = false;
							D_outside_AB = true;
				}// if else

				// A-CD subsidiary parameters computing

	 		// intersect of CD and line perpendicular to CD from A, xp=(b1*c2-b2*c1)/(a1*b2-a2*b1),yp=(c1*a2-c2*a1)/(a1*b2-a2*b1)
    xp_A_CD = ( CD_b*ACD_c - ACD_b*CD_c ) / ( CD_a*ACD_b - ACD_a*CD_b );
    yp_A_CD = ( CD_c*ACD_a - ACD_c*CD_a ) / ( CD_a*ACD_b - ACD_a*CD_b );

				// distance from C to intersect point yp,yp of perpendicular line to AB, d=SQRT( (cx-xp)^2 + (cy-yp)^2 )
    A_CD_dist = Math::Sqrt( Math::Pow(A_x-xp_A_CD,2)+Math::Pow(A_y-yp_A_CD,2) ); 

				// determine if xp,yp is inside CD, between CD, on CD
				if ( C_x <= D_x ){
					  if ( Math::Round(xp_A_CD,4) >= Math::Round(C_x,4) && Math::Round(xp_A_CD,4) <= Math::Round(D_x,4) ){
								  x_inside = true;
					  } else
							{
								  x_inside = false;
							}// if else
				} else
				{
					  if ( Math::Round(xp_A_CD,4) >= Math::Round(D_x,4) && Math::Round(xp_A_CD,4) <= Math::Round(C_x,4) ){
								  x_inside = true;
					  } else
							{
								  x_inside = false;
							}// if else
				}// if else
				if ( C_y <= D_y ){
					  if ( Math::Round(yp_A_CD,4) >= Math::Round(C_y,4) && Math::Round(yp_A_CD,4) <= Math::Round(D_y,4) ){
								   y_inside = true;
					  } else
					  {
								   y_inside = false;
					  }// if else
				} else
				{
					  if ( Math::Round(yp_A_CD,4) >= Math::Round(D_y,4) && Math::Round(yp_A_CD,4) <= Math::Round(C_y,4) ){
								   y_inside = true;
					  } else
					  {
								   y_inside = false;
					  }// if else
				}// if else

				// final resolution A (sagital) is INSIDE CD or NOT
				if ( x_inside == true && y_inside == true ){
					  A_inside_CD = true;
							A_outside_CD = false;
				} else
				{
					  A_inside_CD = false;
							A_outside_CD = true;
				}// if else

			 // B-CD subsidiary parameters computing

	 		// intersect of CD and line perpendicular to CD from B, xp=(b1*c2-b2*c1)/(a1*b2-a2*b1),yp=(c1*a2-c2*a1)/(a1*b2-a2*b1)
    xp_B_CD = ( CD_b*BCD_c - BCD_b*CD_c ) / ( CD_a*BCD_b - BCD_a*CD_b );
    yp_B_CD = ( CD_c*BCD_a - BCD_c*CD_a ) / ( CD_a*BCD_b - BCD_a*CD_b );

				// distance from B to intersect point yp,yp of perpendicular line to CD, d=SQRT( (cx-xp)^2 + (cy-yp)^2 )
    B_CD_dist = Math::Sqrt( Math::Pow(B_x-xp_B_CD,2)+Math::Pow(B_y-yp_B_CD,2) ); 

				// determine if xp,yp is inside CD, between CD, on CD
				if ( C_x <= D_x ){
					  if ( Math::Round(xp_B_CD,4) >= Math::Round(C_x,4) && Math::Round(xp_B_CD,4) <= Math::Round(D_x,4) ){
								  x_inside = true;
					  } else
							{
								  x_inside = false;
							}// if else
				} else
				{
					  if ( Math::Round(xp_B_CD,4) >= Math::Round(D_x,4) && Math::Round(xp_B_CD,4) <= Math::Round(C_x,4) ){
								  x_inside = true;
					  } else
							{
								  x_inside = false;
							}// if else
				}// if else
				if ( C_y <= D_y ){
					  if ( Math::Round(yp_B_CD,4) >= Math::Round(C_y,4) && Math::Round(yp_B_CD,4) <= Math::Round(D_y,4) ){
								   y_inside = true;
					  } else
					  {
								   y_inside = false;
					  }// if else
				} else
				{
					  if ( Math::Round(yp_B_CD,4) >= Math::Round(D_y,4) && Math::Round(yp_B_CD,4) <= Math::Round(C_y,4) ){
								   y_inside = true;
					  } else
					  {
								   y_inside = false;
					  }// if else
				}// if else


				// final resolution B (sagital) is INSIDE CD or NOT
				if ( x_inside == true && y_inside == true ){
					  B_inside_CD = true;
							B_outside_CD = false;
				} else
				{
					  B_inside_CD = false;
							B_outside_CD = true;
				}// if else


				// final resolution B (sagital) is INSIDE CD or NOT
				if ( x_inside == true && y_inside == true ){
					  B_inside_CD = true;
							B_outside_CD = false;
				} else
				{
					  B_inside_CD = false;
							B_outside_CD = true;
				}// if else


				RI1 = Math::Sign( DCD_a*B_x + DCD_b*B_y + DCD_c );
				RI2 = Math::Sign( DCD_a*A_x + DCD_b*A_y + DCD_c );
				RI3 = Math::Sign( CCD_a*B_x + CCD_b*B_y + CCD_c );
				RI4 = Math::Sign( CCD_a*A_x + CCD_b*A_y + CCD_c );

				if ( RI1 == RI2 && RI2 == RI3 && RI3 == RI4 ){
					  AB_wholeLeftOrRight_CD = true;
				} else
				{
       AB_wholeLeftOrRight_CD = false;
				}// if

				RI1 = Math::Sign( AAB_a*C_x + AAB_b*C_y + AAB_c );
				RI2 = Math::Sign( AAB_a*D_x + AAB_b*D_y + AAB_c );
				RI3 = Math::Sign( BAB_a*C_x + BAB_b*C_y + BAB_c );
				RI4 = Math::Sign( BAB_a*D_x + BAB_b*D_y + BAB_c );

				if ( RI1 == RI2 && RI2 == RI3 && RI3 == RI4 ){
					  CD_wholeLeftOrRight_AB = true;
				} else
				{
       CD_wholeLeftOrRight_AB = false;
				}// if

				// case if AB outside and D or C inside and second point of CD line is outside
				if ( A_outside_CD == true && B_outside_CD == true ){

					  if ( C_outside_AB == true ){
								  RI1 = Math::Sign( DCD_a*B_x + DCD_b*B_y + DCD_c );
								  RI2 = Math::Sign( DCD_a*A_x + DCD_b*A_y + DCD_c );
										if ( RI1 == RI2 ){
										   AB_onIdenticalSide = true;
										} else
										{
										   AB_onIdenticalSide = false;
										}// if
							} else  if ( D_outside_AB == true )
							{
								  RI1 = Math::Sign( CCD_a*B_x + CCD_b*B_y + CCD_c );
								  RI2 = Math::Sign( CCD_a*A_x + CCD_b*A_y + CCD_c );
										if ( RI1 == RI2 ){
										   AB_onIdenticalSide = true;
										} else
										{
										   AB_onIdenticalSide = false;
										}// if
					  }// if 

				}// if 

				// limit case if CD outside and A or B inside and second point of AB line is outside
				if ( C_outside_AB == true && D_outside_AB == true ){

					  if ( A_outside_CD == true ){
								  RI1 = Math::Sign( BAB_a*C_x + BAB_b*C_y + BAB_c );
								  RI2 = Math::Sign( BAB_a*D_x + BAB_b*D_y + BAB_c );
										if ( RI1 == RI2 ){
										   AB_onIdenticalSide = true;
										} else
										{
										   AB_onIdenticalSide = false;
										}// if
							} else if ( B_outside_CD == true )
							{
								  RI1 = Math::Sign( AAB_a*C_x + AAB_b*C_y + AAB_c );
								  RI2 = Math::Sign( AAB_a*D_x + AAB_b*D_y + AAB_c );
										if ( RI1 == RI2 ){
										   AB_onIdenticalSide = true;
										} else
										{
										   AB_onIdenticalSide = false;
										}// if
					  }// if 

				}// if 

				CD_length = Math::Sqrt( Math::Pow( C_x-D_x,2 ) + Math::Pow( C_y-D_y,2 ) );
				AB_length = Math::Sqrt( Math::Pow( C_x-D_x,2 ) + Math::Pow( C_y-D_y,2 ) );


				// determine how long is overhang of C point against to xypA xypB
				R1 = Math::Sqrt( Math::Pow(xp_A_CD-C_x,2) + Math::Pow(yp_A_CD-C_y,2) );   
				R2 = Math::Sqrt( Math::Pow(xp_B_CD-C_x,2) + Math::Pow(yp_B_CD-C_y,2) );
				if ( R1 <= R2 ){
					  C_overhangL = R1;
							C_closeTo_Ap = true;
							C_closeTo_Bp = false;
							if ( C_inside_AB == true ){
								  C_overhangL = (-1)*C_overhangL;
							}// if 
				} else
				{
					  C_overhangL = R2;
							C_closeTo_Ap = false;
							C_closeTo_Bp = true;
							if ( C_inside_AB == true ){
								  C_overhangL = (-1)*C_overhangL;
							}// if 
				}// if else

				// determine how long is overhang of D point against to to xypA xypB
				R1 = Math::Sqrt( Math::Pow(xp_A_CD-D_x,2) + Math::Pow(yp_A_CD-D_y,2) );   
				R2 = Math::Sqrt( Math::Pow(xp_B_CD-D_x,2) + Math::Pow(yp_B_CD-D_y,2) );
				if ( R1 <= R2 ){
					  D_overhangL = R1;
							D_closeTo_Ap = true;
							D_closeTo_Bp = false;
							if ( D_inside_AB == true ){
								  D_overhangL = (-1)*D_overhangL;
							}// if 
				} else
				{
					  D_overhangL = R2;
							D_closeTo_Ap = false;
							D_closeTo_Bp = true;
							if ( D_inside_AB == true ){
								  D_overhangL = (-1)*D_overhangL;
							}// if 
				}// if else

				// determine how long is overhang of A point against to to xypC xypD
				R1 = Math::Sqrt( Math::Pow(xp_C_AB-A_x,2) + Math::Pow(yp_C_AB-A_y,2) );   
				R2 = Math::Sqrt( Math::Pow(xp_D_AB-A_x,2) + Math::Pow(yp_D_AB-A_y,2) );
				if ( R1 <= R2 ){
					  A_overhangL = R1;
							A_closeTo_Cp = true;
							A_closeTo_Dp = false;
							if ( A_inside_CD == true ){
								  A_overhangL = (-1)*A_overhangL;
							}// if 
				} else
				{
					  A_overhangL = R2;
							A_closeTo_Cp = false;
							A_closeTo_Dp = true;
							if ( A_inside_CD == true ){
								  A_overhangL = (-1)*A_overhangL;
							}// if 
				}// if else

				// determine how long is overhang of B pointa gainst to to xypA xypB
				R1 = Math::Sqrt( Math::Pow(xp_C_AB-B_x,2) + Math::Pow(yp_C_AB-B_y,2) );   
				R2 = Math::Sqrt( Math::Pow(xp_D_AB-B_x,2) + Math::Pow(yp_D_AB-B_y,2) );
				if ( R1 <= R2 ){
					  B_overhangL = R1;
							B_closeTo_Cp = true;
							B_closeTo_Dp = false;
							if ( B_inside_CD == true ){
								  B_overhangL = (-1)*B_overhangL;
							}// if 
				} else
				{
					  B_overhangL = R2;
							B_closeTo_Cp = false;
							B_closeTo_Dp = true;
							if ( B_inside_CD == true ){
								  B_overhangL = (-1)*B_overhangL;
							}// if 
				}// if else

				if ( (C_inside_AB == true) && (D_inside_AB == true) ){
					  CD_inside_AB = true;
				}// if 
				if ( (A_inside_CD == true) && (B_inside_CD == true) ){
					  AB_inside_CD = true;
				}// if 
				if ( (CD_inside_AB == true) && (AB_inside_CD == true) ){
					  CD_inside_AB_andContrary = true;
				}// if 

				if ( (C_inside_AB == true) || (D_inside_AB == true) ){
       CorD_inside_AB = true;
				}// if
				if ( (A_inside_CD == true) || (B_inside_CD == true) ){
       AorB_inside_CD = true;
				}// if


				if ( (C_overhangL > i_cut_overHangLength) && (C_outside_AB == true) ){
					  C_outside_AB_overhangIsLong = true;
				}// if 
				if ( (D_overhangL > i_cut_overHangLength) && D_outside_AB == true ){
					  D_outside_AB_overhangIsLong = true;
				}// if 
				if ( (C_outside_AB_overhangIsLong == true) && (D_outside_AB_overhangIsLong = true) ){
					  CD_outside_AB_overhangIsLong = true;
				}// if 

				if ( (C_overhangL > i_cut_overHangLength) && (C_outside_AB == true) && (D_inside_AB == true) ){
					  C_outside_D_inside_AB_overhangIsLong = true;
				}// if 
				if ( (D_overhangL > i_cut_overHangLength) && (D_outside_AB == true) && (C_inside_AB == true) ){
					  D_outside_C_inside_AB_overhangIsLong = true;
				}// if 

				if ( (C_overhangL <= i_cut_overHangLength) && C_outside_AB == true ){
					  C_outside_AB_overhangIsShort = true;
				}// if 
				if ( (D_overhangL <= i_cut_overHangLength) && D_outside_AB == true ){
					  D_outside_AB_overhangIsShort = true;
				}// if

				if ( (A_overhangL <= i_cut_overHangLength) && A_outside_CD == true ){
					  A_outside_CD_overhangIsShort = true;
				}// if 
				if ( (B_overhangL <= i_cut_overHangLength) && B_outside_CD == true ){
					  B_outside_CD_overhangIsShort = true;
				}// if

				if ( ( (C_inside_AB == true) && (D_outside_AB_overhangIsShort == true) ) ||
					    ( (D_inside_AB == true) && (C_outside_AB_overhangIsShort == true) ) ||
									( (C_outside_AB_overhangIsShort == true) && (D_outside_AB_overhangIsShort == true) && (A_inside_CD == true) && (B_inside_CD == true) ) ){

					  CorD_outside_AB_overhangIsShort = true;
				}// if
				if ( ( (A_inside_CD == true) && (B_outside_CD_overhangIsShort == true) ) ||
					    ( (B_inside_CD == true) && (A_outside_CD_overhangIsShort == true) ) ||
									( (A_outside_CD_overhangIsShort == true) && (B_outside_CD_overhangIsShort == true) && (A_inside_CD == true) && (B_inside_CD == true) ) ){

					  AorB_outside_CD_overhangIsShort = true;
				}// if


				// compute angle CD line and X axis 
				angle_CD_AB = Math::Abs( CD_a*AB_a + CD_b*AB_b ) / 
					            ( Math::Sqrt( Math::Pow(CD_a,2)+Math::Pow(CD_b,2) ) * ( Math::Sqrt( Math::Pow(AB_a,2)+Math::Pow(AB_b,2) ) ) );
				angle_CD_AB = Math::Acos( angle_CD_AB );
				
				// compute angle CD line and X axis 
				angle_CD_Xaxis = Math::Abs( CD_a*Xaxis_a + CD_b*Xaxis_b ) / 
					                ( Math::Sqrt( Math::Pow(CD_a,2)+Math::Pow(CD_b,2) ) * ( Math::Sqrt( Math::Pow(Xaxis_a,2)+Math::Pow(Xaxis_b,2) ) ) );
				angle_CD_Xaxis = Math::Acos( angle_CD_Xaxis );

				slope_CD_x = i_cut_plusLength*Math::Cos( angle_CD_Xaxis ); 
				slope_CD_y = i_cut_plusLength*Math::Sin( angle_CD_Xaxis );

				// compute angle AB line and X axis 
				angle_AB_Xaxis = Math::Abs( AB_a*Xaxis_a + AB_b*Xaxis_b ) / 
					                ( Math::Sqrt( Math::Pow(AB_a,2)+Math::Pow(AB_b,2) ) * ( Math::Sqrt( Math::Pow(Xaxis_a,2)+Math::Pow(Xaxis_b,2) ) ) );
				angle_AB_Xaxis = Math::Acos( angle_AB_Xaxis );

				slope_AB_x = i_cut_plusLength*Math::Cos( angle_AB_Xaxis ); 
				slope_AB_y = i_cut_plusLength*Math::Sin( angle_AB_Xaxis );

  
				// EXECUTE COMMAND i_QUERY + i_exe
		 	switch ( i_query ){
		   case 1010: // exe g_query_
			   {
							if ( ( AB_wholeLeftOrRight_CD == false ) &&
            ( C_AB_dist <= i_dist ) && 
												( D_AB_dist <= i_dist ) &&
										 	//	( angle_CD_AB <= i_angle ) && 
            ( C_overhangL <= i_cut_overHangLength ) && 
												( D_overhangL <= i_cut_overHangLength ) ) { 

										Object^ dummy = g_LocalMap[ i_item_LM ];
										g_LocalMap->Remove( g_LocalMap[ i_item_LM ] );
										delete( dummy );

										return true;

							}// if 

							break;

			   }
 	   case 1011: // exe g_query_
			   {
				   if ( ( AB_wholeLeftOrRight_CD == false ) &&
								    ( C_overhangL > i_cut_overHangLength ) && 
            ( D_overhangL > i_cut_overHangLength ) && 
												( C_outside_AB == true ) &&
												( D_outside_AB == true ) &&
												//( C_AB_dist <= i_dist ) && 
												//( D_AB_dist <= i_dist ) &&
												( A_CD_dist <= i_dist ) && 
												( B_CD_dist <= i_dist ) &&
												( angle_CD_AB <= i_angle ) ){

										Cx = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X1; 
										Cy = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y1;
										Dx = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X2; 
										Dy = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y2;

										Object^ dummy = g_LocalMap[ i_item_LM ];
										g_LocalMap->Remove( g_LocalMap[ i_item_LM ] );
										delete( dummy );

										{
           c100LineItem^ line = gcnew c100LineItem();

           line->X1 = Cx;
           line->Y1 = Cy;

										 if ( C_closeTo_Ap == true ){

											 		line->X2 = xp_A_CD;
												 	line->Y2 = yp_A_CD;

										 } else
										 {

											 		line->X2 = xp_B_CD;
												 	line->Y2 = yp_B_CD;

										 }// if else

           line->Tag = 1;
										 g_LocalMap->Add( line ); 

													
 										RecomputeLocalMapLineValues( g_LocalMap->Count-1  );

										}
										{

           c100LineItem^ line = gcnew c100LineItem();

           line->X1 = Dx;
           line->Y1 = Dy;

										 if ( D_closeTo_Ap == true ){

											 		line->X2 = xp_A_CD;
												 	line->Y2 = yp_A_CD;

										 } else
										 {

											 		line->X2 = xp_B_CD;
												 	line->Y2 = yp_B_CD;

										 }// if else

           line->Tag = 2;
										 g_LocalMap->Add( line ); 

 										RecomputeLocalMapLineValues( g_LocalMap->Count-1 );

										}

  						  return true;

							} else
							{
								 
		 				}// if 
				   break;
			   }
		   case 1012: // exe g_query_
			   {
							if ( ( AB_wholeLeftOrRight_CD == false ) &&
								    ( CD_wholeLeftOrRight_AB == false ) &&
            ( C_overhangL > i_cut_overHangLength ) && 
								    ( C_outside_AB == true) && 
								    //( D_inside_AB == true) &&  // for very small angle only
            //( C_AB_dist <= i_dist ) && 
												( D_AB_dist <= i_dist ) &&
												( angle_CD_AB <= i_angle ) ) { 


										
										if ( C_closeTo_Ap == true ){
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X2 = xp_A_CD;
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y2 = yp_A_CD;
										} else
										{
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X2 = xp_B_CD;
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y2 = yp_B_CD;
										}// if else

          D_x = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X2;
          D_y = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y2;

										if ( C_x <= D_x ){
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X2 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X2 - slope_CD_x; // znamenka !!!
										} else
										{
												 safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X2 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X2 + slope_CD_x;
										}// if 
										if ( C_y <= D_y ){
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y2 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y2 - slope_CD_y;
										} else
										{
												 safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y2 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y2 + slope_CD_y;
										}// if 

			
										safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Tag = 3;

  						  return true;

							} else
							{
	
		 				}// if 
				   break;
						}
 	   case 1013: // exe g_query_
			   {

							if ( ( AB_wholeLeftOrRight_CD == false ) &&
								    ( CD_wholeLeftOrRight_AB == false ) &&
												( D_overhangL > i_cut_overHangLength ) && 
								    ( D_outside_AB == true) && 
								    //( C_inside_AB == true) && 
            ( C_AB_dist <= i_dist ) && 
								 			//	( D_AB_dist <= i_dist ) &&
												( angle_CD_AB <= i_angle ) ) { 


										if ( D_closeTo_Bp == true ){
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X1 = xp_B_CD;
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y1 = yp_B_CD;
										} else
										{
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X1 = xp_A_CD;
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y1 = yp_A_CD;
										}// if else

          C_x = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X1;
          C_y = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y1;

										if ( C_x <= D_x ){
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X1 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X1 + slope_CD_x; // znamenka !!!
										} else
										{
												 safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X1 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->X1 - slope_CD_x;
										}// if 
										if ( C_y <= D_y ){
											  safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y1 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y1 + slope_CD_y;
										} else
										{
												 safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y1 = safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Y1 - slope_CD_y;
										}// if 


										safe_cast<c100LineItem^>(g_LocalMap[i_item_LM])->Tag = 4;

										RecomputeLocalMapLineValues( i_item_LM );

								  return true; //false;

							} else
							{//

		 				}// if 
				   break;
			   }

					default:
						{

							return false;
							break;
						}
		  }// switch

				return false;

}// public: System::Void Run_LMtoGM(){


};// public ref class c100InsertLocalMapToGlobalMap

}// namespace ROBOMAP




