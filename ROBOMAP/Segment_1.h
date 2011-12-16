#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Diagnostics;
using namespace System::Threading;
using namespace System::Runtime::InteropServices;

namespace ROBOMAP {

//**********************************************************
//**********************************************************

public ref class cLSTechInfo 
{
private:
 	
   static UInt16 beams;
		 static Double angleRAD;
			static Double angleDEG;
			static Double lsrange;
	 
public:
	   static cLSTechInfo(){ // MUST be STATIC !!!

				   	beams = 0; 
				   	angleRAD = 0; 
								angleDEG = 0;
								lsrange = 0;
								
								GetCFGData();

				}
		  cLSTechInfo()
				{ 

				}

private: static System::Void GetCFGData(){

								beams = 361; 
								angleDEG = 180;
								angleRAD = ((Math::PI*2)/360) * Convert::ToDouble( 180 ); 
								lsrange = 6000;

}// private: System::Void GetCFGData(){

public: property UInt16 NumberOfBeams 
    {
        UInt16 get() { return beams; }
								void set(UInt16 value){ beams = value;  }

    }// 

public: property Double DetectionAngleRAD 
    {
        Double get() { return angleRAD; }
								void set(Double value){ angleRAD = value;  }

    }// 

public: property Double DetectionAngleDEG 
    {
        Double get() { return angleDEG; }
								void set(Double value){ angleDEG = value;  }

    }// 

public: property Double LSRange 
    {
        Double get() { return lsrange; }
								void set(Double value){ lsrange = value;  }

    }// 


};// public ref class cLSTechInfo

};// namespace ROBOMAP3 


