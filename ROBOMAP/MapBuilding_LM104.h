// What is ‘source code purity’ ? hell yeah .... 

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



namespace ROBOMAP {

	/// <summary>
	/// Summary for MapBuilding_LM104
	/// </summary>
	public ref class MapBuilding_LM104 : public System::Windows::Forms::UserControl
	{
 private:
  System::Object^ g_ParentObject;

		List<Object^>^ g_LinesArray;
		List<Object^>^ g_DmLSArray;
		List<Object^>^ g_DsLSArray;
		List<Object^>^ g_FoundedPositions;

		List<Object^>^ g_GlobalMap;
  List<Object^>^ g_GlobalPointsMap;
		List<Object^>^ g_LocalMap;
		List<Object^>^ g_TemporaryMap;

		List<Object^>^ g_StartPoses;

		List<Object^>^ g_Population;
		List<Object^>^ g_GAResults;
		List<Object^>^ g_paramLastBestDecVec;
	 List<Object^>^ g_trialSolutionInd;

		String^ g_CFG_RobomapDirectory; 

		array<Boolean>^ g_RBeams;

  array<c104TriangleItem^>^ g_Triangle;

		Process^ g_Process; 
		ProcessPriorityClass g_RequestedProcessPriority;



		double g_Optimum_Continual;
		double g_Optimum_Comparative;
		double g_Optimum_multiplier;
		double g_Optimum_BeamNumber;

		value struct t_gs_RPose {
    double posX;
				double posY;
				double Angle_RAD;
		};
  t_gs_RPose gs_RPose;

		value struct t_gs_PLBFile {
    String^ FileName;
				Boolean Opened;
		};
		t_gs_PLBFile gs_PLBFile;

		value struct t_gs_LSBFile {
    String^ FileName;
				Boolean Opened;
		};
		t_gs_LSBFile gs_LSBFile;

	 value struct t_gs_PTHFile {
    String^ FileName;
				Boolean Opened;
		};
		t_gs_PTHFile gs_PTHFile;

	 value struct t_gs_TXTFile {
    String^ FileName;
				Boolean Opened;
		};
		t_gs_TXTFile gs_TXTFile;

	 value struct t_gs_AutoSave {
    String^ DirectoryOrFileName;
				Boolean Opened;
		};
		t_gs_AutoSave gs_AutoSave;

		Boolean g_DebugMode;

		double g_globalPLBMinX_XY;
	 double g_globalPLBMaxX_XY;
	 double g_globalPLBMinY_XY;
	 double g_globalPLBMaxY_XY;

		double g_globalGAMinX_XY;
	 double g_globalGAMaxX_XY;
	 double g_globalGAMinY_XY;
	 double g_globalGAMaxY_XY;

		double g_DsMinX_XY;
	 double g_DsMaxX_XY;
	 double g_DsMinY_XY;
	 double g_DsMaxY_XY;

		double g_DsMinX_Polar;
	 double g_DsMaxX_Polar;
	 double g_DsMinY_Polar;
	 double g_DsMaxY_Polar;

		double g_DmMinX_XY;
	 double g_DmMaxX_XY;
	 double g_DmMinY_XY;
	 double g_DmMaxY_XY;

		double g_DmMinX_Polar;
	 double g_DmMaxX_Polar;
	 double g_DmMinY_Polar;
	 double g_DmMaxY_Polar;

		double g_Ds_NumberOfScans;
  double g_Ds_NumberOfBeams;
		double g_Ds_DetectionAngle;

		double g_Dm_NumberOfScans;
		double g_Dm_NumberOfBeams;
		double g_Dm_DetectionAngle;

		Int32 g_paramStepDs;
		Int32 g_paramStepDe;

		double g_PLBMagnifierX;
		double g_PLBMagnifierY;
		double g_PLBMagnifierZoom;

		double g_GAMagnifierX;
		double g_GAMagnifierY;
		double g_GAMagnifierZoom;

		double g_DsMagnifier;
		double g_DmMagnifier;

  UInt32 g_PLBNumberOfLines;
		Int32 g_ScanAngleNumber;

		double g_EpsT;
		double g_EpsTdummy;
		Int32 g_EpsTSel;
  double g_EpsT_SumOfLength;
  double g_EpsT_ComputedNoise;

  Int32 g_errStatus;
		String^ g_StartStopTime;

  Int32 g_SearchingAlgorithm;
		Int32 g_WayOfCreation;
		Int32 g_ActualLSScan;

		double g_ContinualOptimum;

	 double g_WindowTolerance;

		double g_vRobotMagnifier;

  Bitmap^ g_PLBBitmap; 
		Bitmap^ g_PLBBitmapDummy; 
		Graphics^ g_G_PLB;

		Bitmap^ g_DsBitmap; 
		Bitmap^ g_DsBitmapDummy;
		Graphics^ g_G_Ds;

		Bitmap^ g_GABitmap; 
		Bitmap^	g_GABitmapDummy;
		Graphics^ g_G_GA;

		double g_GA_AreaWidth;
		double g_GA_AreaHeight;
		double g_GA_minX;
		double g_GA_minY;
		double g_GA_maxX;
		double g_GA_maxY;

	 double g_BestFitness;
	 UInt32 g_BestIndividuum;
		UInt32 g_Generation;
		UInt32 g_BestIndividuumAtGen;
		double g_paramContinualOptimum;

	 Int32 g_GA_NumberOfIndividuals;

		double g_paramF;
		double g_paramFitnessLimit;
  double g_paramCrossProbability;
		double g_paramLastBestFitness;


		Int32 g_GA_SelectedAlgorithm;


		value struct t_gs_Pen {
		  Pen^ GreenPen1;
		  Pen^ BluePen1;
		  Pen^ RedPen1;
		  Pen^ BlackPen1;
		  Pen^ GrayPen1;
		  Pen^ DarkOrangePen1;
		  Pen^ FuchsiaPen1;

		  Pen^ GreenPen2;
		  Pen^ BluePen2;
		  Pen^ RedPen2;
		  Pen^ BlackPen2;
		  Pen^ GrayPen2;
		  Pen^ DarkOrangePen2;
		  Pen^ LimePen2;
		  Pen^ FuchsiaPen2;

		  Pen^ GreenPen3;
		  Pen^ BluePen3;
		  Pen^ RedPen3;
		  Pen^ BlackPen3;
		  Pen^ LimePen3;
		  Pen^ FuchsiaPen3;
		};
  t_gs_Pen gs_Pen;

		Boolean g_TerminateThread;












	public:
		MapBuilding_LM104( Object^ obj )
		{

			StreamReader^ sr;

			//******************************************

			InitializeComponent();

			g_ParentObject = obj;

			g_LinesArray = gcnew List<Object^>();
 		g_DmLSArray = gcnew List<Object^>();
			g_DsLSArray = gcnew List<Object^>();
   g_FoundedPositions = gcnew List<Object^>();

			g_GlobalMap = gcnew List<Object^>();
			g_GlobalPointsMap = gcnew List<Object^>();
		 g_LocalMap = gcnew List<Object^>();
			g_TemporaryMap = gcnew List<Object^>();

			g_StartPoses = gcnew List<Object^>();

			g_Population = gcnew List<Object^>();
			g_GAResults = gcnew List<Object^>();
			g_paramLastBestDecVec = gcnew List<Object^>();
	  g_trialSolutionInd = gcnew List<Object^>();

			cLSTechInfo^ lsti = gcnew cLSTechInfo(); // call for STATIC !!! constructor, CFG data can NOT be changed at running time !!!

			gs_PLBFile.FileName = "";
			gs_PLBFile.Opened = false;

			gs_LSBFile.FileName = "";
			gs_LSBFile.Opened = false;

			gs_PTHFile.FileName = "";
			gs_PTHFile.Opened = false;

			g_DebugMode = false;

		 g_PLBNumberOfLines = 0;

			g_PLBMagnifierX = 0;
			g_PLBMagnifierY = 0;
			g_PLBMagnifierZoom = 0.9;

			g_GAMagnifierX = 0;
			g_GAMagnifierY = 0;
			g_GAMagnifierZoom = 0.95;

			g_DsMagnifier = 0.95;
			g_DmMagnifier = 0.95;

			gs_RPose.posX = 0;
   gs_RPose.posY = 0;
			gs_RPose.Angle_RAD = 0;

   g_PLBBitmap = nullptr; 
		 g_PLBBitmapDummy = nullptr; 

		 g_DsBitmap = nullptr; 
			g_DsBitmapDummy = nullptr; 

	  g_GABitmap = nullptr; 
		 g_GABitmapDummy = nullptr;
		
			g_Ds_NumberOfScans = 0;
		 g_Ds_DetectionAngle = 0;

			g_Dm_NumberOfScans = 0;
		 g_Dm_DetectionAngle = 0;

			g_TerminateThread = false;
	
 		g_WindowTolerance = 0.5;

			g_Process = Process::GetCurrentProcess();

			gs_Pen.GreenPen1 = gcnew Pen( Brushes::Green, 1 );
			gs_Pen.BluePen1 = gcnew Pen( Brushes::Blue, 1 );
			gs_Pen.RedPen1 = gcnew Pen( Brushes::Red, 1 );
			gs_Pen.BlackPen1 = gcnew Pen( Brushes::Black, 1 );
			gs_Pen.GrayPen1 = gcnew Pen( Brushes::Gray, 1 );
			gs_Pen.DarkOrangePen1 = gcnew Pen( Brushes::DarkOrange, 1 );
			gs_Pen.FuchsiaPen1 = gcnew Pen( Brushes::Fuchsia, 1 );

			gs_Pen.GreenPen2 = gcnew Pen( Brushes::Green, 2 );
			gs_Pen.BluePen2 = gcnew Pen( Brushes::Blue, 2 );
			gs_Pen.RedPen2 = gcnew Pen( Brushes::Red, 2 );
		 gs_Pen.BlackPen2 = gcnew Pen( Brushes::Black, 2 );
			gs_Pen.GrayPen2 = gcnew Pen( Brushes::Gray, 2 );
			gs_Pen.DarkOrangePen2 = gcnew Pen( Brushes::DarkOrange, 2 );
			gs_Pen.LimePen2 = gcnew Pen( Brushes::Lime, 2 );
			gs_Pen.FuchsiaPen2 = gcnew Pen( Brushes::Fuchsia, 2 );

			gs_Pen.GreenPen3 = gcnew Pen( Brushes::Green, 3 );
			gs_Pen.BluePen3 = gcnew Pen( Brushes::Blue, 3 );
			gs_Pen.RedPen3 = gcnew Pen( Brushes::Red, 3 );
		 gs_Pen.BlackPen3 = gcnew Pen( Brushes::Black, 3 );
			gs_Pen.LimePen3 = gcnew Pen( Brushes::Lime, 3 );
			gs_Pen.FuchsiaPen3 = gcnew Pen( Brushes::Fuchsia, 3 );

			g_Triangle = gcnew array<c104TriangleItem^>(4);
			g_Triangle[0]= gcnew c104TriangleItem();
			g_Triangle[1]= gcnew c104TriangleItem();
			g_Triangle[2]= gcnew c104TriangleItem();
			g_Triangle[3]= gcnew c104TriangleItem();

			g_vRobotMagnifier = 70;

			g_RBeams = gcnew array<Boolean>(361); 
			
			g_CFG_RobomapDirectory = "C:\\ROBOMAP"; 

			// TabPage RUN
			this->checkBox31->Checked = true;      // show robot pose and heading
		
			// SCANNER
			this->comboBox8->SelectedIndex = 3;   // DSMAE 1 
			this->radioButton5->Checked = true;   // use Ds+De
			this->numericUpDown21->Value = 1;     // stepDs
			this->numericUpDown20->Value = 1;     // stepDe
			this->numericUpDown19->Value = 60;    // scanning angle +/-
			this->numericUpDown33->Value = 15;     // minX
			this->numericUpDown34->Value = 15;     // minY
			this->numericUpDown31->Value = 15;     // maxX
			this->numericUpDown29->Value = 15;     // maxY
			this->numericUpDown30->Value = 1;     // stepX
			this->numericUpDown32->Value = 1;     // stepY
			this->maskedTextBox8->Text = "0,00983";  // EpsT scanner

			this->numericUpDown28->Value = 15;     // 15 INDs 
			this->comboBox6->SelectedIndex = 0;    // c++ rnd gen
			this->numericUpDown24->Value = 60;    // DE minX
			this->numericUpDown25->Value = 60;    // DE minY
			this->numericUpDown27->Value = 60;    // DE maxX
			this->numericUpDown26->Value = 60;    // DE maxY
			this->maskedTextBox10->Text = "0,6";    // DE F param
			this->maskedTextBox9->Text = "1";      // DE Pcrx param
   this->comboBox5->SelectedIndex = 0;   // termination cond max gen
			this->numericUpDown23->Value = 15;    // DE number of GEN
			this->numericUpDown22->Value = 100;    // DE f(x) limit to terminate
	

			this->checkBox29->Checked = true;        // debug mode on 
   this->trackBar5->Value = 5;              // Master priority Normal
			this->button1->Enabled = true;           // PLB
			this->button2->Enabled = false;          // LSB

			// TabPage LSBFile
			this->radioButton8->Checked = true;  // LSB view style polar

			// TabPage Founded positions
			this->radioButton36->Checked = true;  // save TXT TAB sep
			this->checkBox45->Checked = true;      // use DOT in TXT file 

			// TabPage Split/Merge
			this->numericUpDown79->Value = 15;         // min dist between points 
			this->maskedTextBox44->Text = "0,45";      // angle at spliting 
   this->maskedTextBox46->Text = "0,5";       // +length at spliting
			this->numericUpDown80->Value = 15;         // overhang

			this->maskedTextBox45->Text = "0,0872";    // angle at merging
			this->numericUpDown75->Value = 15;         // perpendic dist.
			this->numericUpDown73->Value = 15;         // min dist between points, adjacent point
			this->numericUpDown74->Value = 15;         // overhang
			this->numericUpDown76->Value = 15;         // line length

			this->numericUpDown81->Value = 10;         // removing minimum line length

			this->numericUpDown77->Value = 10;         // point to point regression
			this->numericUpDown78->Value = 10;         // point to line regression

			this->maskedTextBox47->Text = "0,45";    // angle at merging
			this->numericUpDown83->Value = 15;         // perpendic dist.
			this->numericUpDown85->Value = 25;         // min dist between points, adjacent point
			this->numericUpDown84->Value = 15;         // overhang
			this->numericUpDown82->Value = 15;         // line length

			this->comboBox23->SelectedIndex = (1);     // temporary map creating style 

   this->tabPage2->Enabled = false; 
   this->tabPage5->Enabled = false; 
   this->tabPage6->Enabled = false; 

			// ComboBOX StartPoses 
			if ( File::Exists( g_CFG_RobomapDirectory + "\\settings\\start_poses.set" ) ){

				  try // file format  NAME # X # Y # angleDEG # Info
						{
				    sr = gcnew StreamReader( g_CFG_RobomapDirectory + "\\settings\\start_poses.set" ); 

						  while ( sr->EndOfStream == false ) {		

							    String^ line = sr->ReadLine();
  
		  					  c104StartPoses^ Item =  gcnew c104StartPoses();
 
	  								Item->Name = line->Substring(0, line->IndexOf("#") );
			  						line = line->Substring( line->IndexOf("#")+1 );  

					  				Item->X = Convert::ToDouble( line->Substring(0, line->IndexOf("#") ) ); 
							  		line = line->Substring( line->IndexOf("#")+1 );

									  Item->Y = Convert::ToDouble( line->Substring(0, line->IndexOf("#") ) ); 
									  line = line->Substring( line->IndexOf("#")+1 );

									  Item->Angle = Convert::ToDouble( line->Substring(0, line->IndexOf("#") ) ); 
									  line = line->Substring( line->IndexOf("#")+1 );

									  Item->Info = line; 

										  g_StartPoses->Add( Item );

						  }// while

 					}
						catch(...)
						{
							MessageBox::Show( "Error at reading .set at start file: "+g_CFG_RobomapDirectory + "\\settings\\start_poses.set","SET file reading ...", MessageBoxButtons::OK ); 
						}
						finally
						{
						  sr->Close(); 
						  delete( sr );
						}

						this->comboBox13->Items->Clear();   
						for ( Int32 i=0;i<g_StartPoses->Count;i++ ){
							   this->comboBox13->Items->Add( safe_cast<c104StartPoses^>(g_StartPoses[i])->Name + 
											                             "  X:" +    
																																								Convert::ToString( safe_cast<c104StartPoses^>(g_StartPoses[i])->X ) + 
											                             "  Y:" +    
																																								Convert::ToString( safe_cast<c104StartPoses^>(g_StartPoses[i])->Y ) + 
											                             "  Ang:" +    
																																								Convert::ToString( safe_cast<c104StartPoses^>(g_StartPoses[i])->Angle ) + 
											                             "  Info:" +    
											                             safe_cast<c104StartPoses^>(g_StartPoses[i])->Info ); 
						}// for

						if ( this->comboBox13->Items->Count != 0 ){
							  this->comboBox13->SelectedIndex = (0);
						}// if 

			}// if 


   this->tabPage2->Enabled = false; 
   this->tabPage5->Enabled = false; 
   this->tabPage6->Enabled = false; 


   // AUTORELOAD settings - do not criticize this, I know what is serialization/deserialization :-}
   if ( File::Exists( g_CFG_RobomapDirectory + "\\settings\\" + "gslam.set" ) == true ){

 		   try
      {
        sr = gcnew StreamReader( g_CFG_RobomapDirectory + "\\settings\\" + "gslam.set" );

        // AutoReload at start ?
					   String^ line = sr->ReadLine();
								sr->Close();

        if ( Convert::ToBoolean( line ) == true ){
           button50_Click( this, nullptr );
        }// if 
      }
			   catch( Exception^ err )
			   {
          MessageBox::Show( "Error in SET data file reading: "+err->Message,"SET data reading.", MessageBoxButtons::OK );
			   }
      finally
      {
         if ( sr )
            delete (IDisposable^)sr;
			   }

   }// if 


			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MapBuilding_LM104()
		{
			if (components)
			{
				delete components;
			}

			// everyone hope, GarbageCollector remove all unneccessary data

		}

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabControl^  tabControl2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TabControl^  tabControl3;
	private: System::Windows::Forms::TabPage^  tabPage9;
	private: System::Windows::Forms::Label^  label269;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown69;
	private: System::Windows::Forms::Label^  label223;
	private: System::Windows::Forms::ComboBox^  comboBox13;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TabPage^  tabPage16;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TabControl^  tabControl4;
	private: System::Windows::Forms::TabPage^  tabPage8;
	private: System::Windows::Forms::TabControl^  tabControl5;
	private: System::Windows::Forms::TabPage^  tabPage15;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown59;
	private: System::Windows::Forms::Label^  label169;
	private: System::Windows::Forms::CheckBox^  checkBox36;
	private: System::Windows::Forms::CheckBox^  checkBox30;
	private: System::Windows::Forms::CheckBox^  checkBox35;
	private: System::Windows::Forms::CheckBox^  checkBox31;
	private: System::Windows::Forms::CheckBox^  checkBox34;
	private: System::Windows::Forms::CheckBox^  checkBox32;
	private: System::Windows::Forms::TabPage^  tabPage17;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label214;
	private: System::Windows::Forms::CheckBox^  checkBox48;
	private: System::Windows::Forms::GroupBox^  groupBox42;
	private: System::Windows::Forms::Label^  label168;
	private: System::Windows::Forms::TrackBar^  trackBar5;
	private: System::Windows::Forms::CheckBox^  checkBox29;
	private: System::Windows::Forms::TabPage^  tabPage18;
	private: System::Windows::Forms::CheckBox^  checkBox52;
	private: System::Windows::Forms::CheckBox^  checkBox40;
	private: System::Windows::Forms::TabPage^  tabPage19;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::CheckBox^  checkBox57;
	private: System::Windows::Forms::Button^  button48;
	private: System::Windows::Forms::Button^  button49;
	private: System::Windows::Forms::Button^  button50;
	private: System::Windows::Forms::TabPage^  tabPage20;
private: System::Windows::Forms::TabControl^  tabControl6;
private: System::Windows::Forms::TabPage^  tabPage21;
private: System::Windows::Forms::Label^  label176;
private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::Panel^  panel4;
private: System::Windows::Forms::GroupBox^  groupBox17;
private: System::Windows::Forms::RadioButton^  radioButton5;
private: System::Windows::Forms::RadioButton^  radioButton4;
private: System::Windows::Forms::GroupBox^  groupBox18;
private: System::Windows::Forms::NumericUpDown^  numericUpDown19;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::NumericUpDown^  numericUpDown20;
private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::NumericUpDown^  numericUpDown21;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox8;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::GroupBox^  groupBox19;
private: System::Windows::Forms::GroupBox^  groupBox20;
private: System::Windows::Forms::GroupBox^  groupBox21;
private: System::Windows::Forms::NumericUpDown^  numericUpDown22;
private: System::Windows::Forms::NumericUpDown^  numericUpDown23;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::ComboBox^  comboBox5;
private: System::Windows::Forms::GroupBox^  groupBox22;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox9;
private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox10;
private: System::Windows::Forms::GroupBox^  groupBox23;
private: System::Windows::Forms::NumericUpDown^  numericUpDown24;
private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::NumericUpDown^  numericUpDown25;
private: System::Windows::Forms::NumericUpDown^  numericUpDown26;
private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::Label^  label54;
private: System::Windows::Forms::Label^  label55;
private: System::Windows::Forms::Label^  label60;
private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::NumericUpDown^  numericUpDown27;
private: System::Windows::Forms::Label^  label62;
private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::ComboBox^  comboBox6;
private: System::Windows::Forms::Label^  label64;
private: System::Windows::Forms::NumericUpDown^  numericUpDown28;
private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::GroupBox^  groupBox24;
private: System::Windows::Forms::Label^  label67;
private: System::Windows::Forms::Label^  label68;
private: System::Windows::Forms::Label^  label69;
private: System::Windows::Forms::NumericUpDown^  numericUpDown29;
private: System::Windows::Forms::Label^  label70;
private: System::Windows::Forms::Label^  label71;
private: System::Windows::Forms::Label^  label72;
private: System::Windows::Forms::Label^  label73;
private: System::Windows::Forms::NumericUpDown^  numericUpDown30;
private: System::Windows::Forms::NumericUpDown^  numericUpDown31;
private: System::Windows::Forms::Label^  label74;
private: System::Windows::Forms::NumericUpDown^  numericUpDown32;
private: System::Windows::Forms::Label^  label75;
private: System::Windows::Forms::NumericUpDown^  numericUpDown33;
private: System::Windows::Forms::Label^  label76;
private: System::Windows::Forms::NumericUpDown^  numericUpDown34;
private: System::Windows::Forms::ComboBox^  comboBox8;




private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::GroupBox^  groupBox31;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::Label^  label177;
	private: System::Windows::Forms::Label^  label178;
	private: System::Windows::Forms::Label^  label179;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::Label^  label180;
	private: System::Windows::Forms::GroupBox^  groupBox32;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	private: System::Windows::Forms::Label^  label181;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label182;
	private: System::Windows::Forms::Label^  label183;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::GroupBox^  groupBox33;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::Label^  label184;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::Label^  label185;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::Label^  label186;
	private: System::Windows::Forms::Label^  label187;
	private: System::Windows::Forms::Label^  label188;
	private: System::Windows::Forms::Label^  label81;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown35;
	private: System::Windows::Forms::Label^  label82;
private: System::Windows::Forms::Label^  label83;
private: System::Windows::Forms::Label^  label88;
private: System::Windows::Forms::Label^  label87;
private: System::Windows::Forms::Label^  label86;
private: System::Windows::Forms::Label^  label85;
private: System::Windows::Forms::GroupBox^  groupBox58;
private: System::Windows::Forms::GroupBox^  groupBox59;
private: System::Windows::Forms::NumericUpDown^  numericUpDown72;
private: System::Windows::Forms::RadioButton^  radioButton34;
private: System::Windows::Forms::RadioButton^  radioButton35;
private: System::Windows::Forms::RadioButton^  radioButton36;
private: System::Windows::Forms::RadioButton^  radioButton37;
private: System::Windows::Forms::CheckBox^  checkBox46;
private: System::Windows::Forms::CheckBox^  checkBox45;
private: System::Windows::Forms::Button^  button24;
private: System::Windows::Forms::GroupBox^  groupBox60;
private: System::Windows::Forms::GroupBox^  groupBox61;
private: System::Windows::Forms::CheckBox^  checkBox37;
private: System::Windows::Forms::CheckBox^  checkBox38;
private: System::Windows::Forms::CheckBox^  checkBox50;
private: System::Windows::Forms::Button^  button25;
private: System::Windows::Forms::ListBox^  listBox2;
private: System::Windows::Forms::GroupBox^  groupBox62;
private: System::Windows::Forms::Label^  label207;
private: System::Windows::Forms::Label^  label208;
private: System::Windows::Forms::Label^  label209;
private: System::Windows::Forms::Label^  label210;
private: System::Windows::Forms::Label^  label211;
private: System::Windows::Forms::Panel^  panel10;
private: System::Windows::Forms::RichTextBox^  richTextBox1;
private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
private: System::Windows::Forms::GroupBox^  groupBox63;
private: System::Windows::Forms::TabPage^  tabPage25;
private: System::Windows::Forms::Panel^  panel11;
private: System::Windows::Forms::GroupBox^  groupBox66;
private: System::Windows::Forms::RichTextBox^  richTextBox2;
private: System::Windows::Forms::Panel^  panel12;
private: System::Windows::Forms::GroupBox^  groupBox67;
private: System::Windows::Forms::NumericUpDown^  numericUpDown75;
private: System::Windows::Forms::Label^  label213;
private: System::Windows::Forms::NumericUpDown^  numericUpDown74;
private: System::Windows::Forms::Label^  label212;
private: System::Windows::Forms::NumericUpDown^  numericUpDown73;
private: System::Windows::Forms::Label^  label206;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox46;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox45;
private: System::Windows::Forms::Label^  label221;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox44;
private: System::Windows::Forms::Label^  label220;
private: System::Windows::Forms::NumericUpDown^  numericUpDown76;
private: System::Windows::Forms::Label^  label219;
private: System::Windows::Forms::Label^  label222;
private: System::Windows::Forms::GroupBox^  groupBox68;
private: System::Windows::Forms::Label^  label224;
private: System::Windows::Forms::NumericUpDown^  numericUpDown77;
private: System::Windows::Forms::Label^  label225;
private: System::Windows::Forms::NumericUpDown^  numericUpDown78;
private: System::Windows::Forms::Label^  label227;
private: System::Windows::Forms::Label^  label226;
private: System::Windows::Forms::Panel^  panel13;
private: System::Windows::Forms::GroupBox^  groupBox70;
private: System::Windows::Forms::GroupBox^  groupBox69;
private: System::Windows::Forms::Label^  label228;
private: System::Windows::Forms::Label^  label235;
private: System::Windows::Forms::Label^  label234;
private: System::Windows::Forms::Label^  label233;
private: System::Windows::Forms::Label^  label232;
private: System::Windows::Forms::Label^  label231;
private: System::Windows::Forms::Label^  label230;
private: System::Windows::Forms::Label^  label229;
private: System::Windows::Forms::Label^  label236;
private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
private: System::Windows::Forms::ToolStripProgressBar^  toolStripProgressBar1;
private: System::Windows::Forms::GroupBox^  groupBox71;
private: System::Windows::Forms::Label^  label200;
private: System::Windows::Forms::NumericUpDown^  numericUpDown79;
private: System::Windows::Forms::NumericUpDown^  numericUpDown80;
private: System::Windows::Forms::Label^  label237;
private: System::Windows::Forms::GroupBox^  groupBox72;
private: System::Windows::Forms::NumericUpDown^  numericUpDown81;
private: System::Windows::Forms::Label^  label238;
private: System::Windows::Forms::GroupBox^  groupBox73;
private: System::Windows::Forms::CheckBox^  checkBox20;
private: System::Windows::Forms::CheckBox^  checkBox19;
private: System::Windows::Forms::CheckBox^  checkBox21;
private: System::Windows::Forms::GroupBox^  groupBox74;
private: System::Windows::Forms::Label^  label239;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox47;
private: System::Windows::Forms::Label^  label240;
private: System::Windows::Forms::NumericUpDown^  numericUpDown82;
private: System::Windows::Forms::NumericUpDown^  numericUpDown83;
private: System::Windows::Forms::Label^  label241;
private: System::Windows::Forms::Label^  label242;
private: System::Windows::Forms::NumericUpDown^  numericUpDown84;
private: System::Windows::Forms::Label^  label243;
private: System::Windows::Forms::NumericUpDown^  numericUpDown85;
private: System::Windows::Forms::Label^  label244;
private: System::Windows::Forms::CheckBox^  checkBox22;
private: System::Windows::Forms::CheckBox^  checkBox23;
private: System::Windows::Forms::CheckBox^  checkBox24;
private: System::Windows::Forms::CheckBox^  checkBox25;
private: System::Windows::Forms::CheckBox^  checkBox26;
private: System::Windows::Forms::CheckBox^  checkBox27;
private: System::Windows::Forms::CheckBox^  checkBox33;
private: System::Windows::Forms::TabControl^  tabControl7;
private: System::Windows::Forms::TabPage^  tabPage26;
private: System::Windows::Forms::TabPage^  tabPage27;
private: System::Windows::Forms::Panel^  panel14;
private: System::Windows::Forms::Button^  button11;
private: System::Windows::Forms::CheckBox^  checkBox39;
private: System::Windows::Forms::NumericUpDown^  numericUpDown88;
private: System::Windows::Forms::Label^  label250;
private: System::Windows::Forms::Label^  label251;
private: System::Windows::Forms::Panel^  panel15;
private: System::Windows::Forms::GroupBox^  groupBox78;
private: System::Windows::Forms::GroupBox^  groupBox76;
private: System::Windows::Forms::Label^  label252;
private: System::Windows::Forms::NumericUpDown^  numericUpDown86;
private: System::Windows::Forms::Label^  label253;
private: System::Windows::Forms::NumericUpDown^  numericUpDown87;
private: System::Windows::Forms::ComboBox^  comboBox23;
private: System::Windows::Forms::Label^  label254;
private: System::Windows::Forms::CheckBox^  checkBox44;
private: System::Windows::Forms::Label^  label84;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
						System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MapBuilding_LM104::typeid));
						this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
						this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
						this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
						this->panel1 = (gcnew System::Windows::Forms::Panel());
						this->label2 = (gcnew System::Windows::Forms::Label());
						this->label1 = (gcnew System::Windows::Forms::Label());
						this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
						this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
						this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
						this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
						this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
						this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
						this->button10 = (gcnew System::Windows::Forms::Button());
						this->button6 = (gcnew System::Windows::Forms::Button());
						this->label7 = (gcnew System::Windows::Forms::Label());
						this->button5 = (gcnew System::Windows::Forms::Button());
						this->label6 = (gcnew System::Windows::Forms::Label());
						this->textBox5 = (gcnew System::Windows::Forms::TextBox());
						this->button4 = (gcnew System::Windows::Forms::Button());
						this->textBox4 = (gcnew System::Windows::Forms::TextBox());
						this->label5 = (gcnew System::Windows::Forms::Label());
						this->textBox3 = (gcnew System::Windows::Forms::TextBox());
						this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
						this->checkBox44 = (gcnew System::Windows::Forms::CheckBox());
						this->button3 = (gcnew System::Windows::Forms::Button());
						this->button2 = (gcnew System::Windows::Forms::Button());
						this->textBox2 = (gcnew System::Windows::Forms::TextBox());
						this->button1 = (gcnew System::Windows::Forms::Button());
						this->label4 = (gcnew System::Windows::Forms::Label());
						this->textBox1 = (gcnew System::Windows::Forms::TextBox());
						this->label3 = (gcnew System::Windows::Forms::Label());
						this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
						this->tabControl6 = (gcnew System::Windows::Forms::TabControl());
						this->tabPage21 = (gcnew System::Windows::Forms::TabPage());
						this->label88 = (gcnew System::Windows::Forms::Label());
						this->label87 = (gcnew System::Windows::Forms::Label());
						this->button7 = (gcnew System::Windows::Forms::Button());
						this->label86 = (gcnew System::Windows::Forms::Label());
						this->button8 = (gcnew System::Windows::Forms::Button());
						this->label85 = (gcnew System::Windows::Forms::Label());
						this->button9 = (gcnew System::Windows::Forms::Button());
						this->label84 = (gcnew System::Windows::Forms::Label());
						this->label83 = (gcnew System::Windows::Forms::Label());
						this->label81 = (gcnew System::Windows::Forms::Label());
						this->label176 = (gcnew System::Windows::Forms::Label());
						this->tabControl5 = (gcnew System::Windows::Forms::TabControl());
						this->tabPage15 = (gcnew System::Windows::Forms::TabPage());
						this->panel15 = (gcnew System::Windows::Forms::Panel());
						this->numericUpDown59 = (gcnew System::Windows::Forms::NumericUpDown());
						this->checkBox27 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox26 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox23 = (gcnew System::Windows::Forms::CheckBox());
						this->label169 = (gcnew System::Windows::Forms::Label());
						this->checkBox22 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox32 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox24 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox33 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox30 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox34 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox25 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox35 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox31 = (gcnew System::Windows::Forms::CheckBox());
						this->tabPage17 = (gcnew System::Windows::Forms::TabPage());
						this->panel3 = (gcnew System::Windows::Forms::Panel());
						this->label214 = (gcnew System::Windows::Forms::Label());
						this->checkBox48 = (gcnew System::Windows::Forms::CheckBox());
						this->groupBox42 = (gcnew System::Windows::Forms::GroupBox());
						this->label168 = (gcnew System::Windows::Forms::Label());
						this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
						this->checkBox29 = (gcnew System::Windows::Forms::CheckBox());
						this->tabPage18 = (gcnew System::Windows::Forms::TabPage());
						this->checkBox36 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox52 = (gcnew System::Windows::Forms::CheckBox());
						this->tabPage19 = (gcnew System::Windows::Forms::TabPage());
						this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
						this->checkBox57 = (gcnew System::Windows::Forms::CheckBox());
						this->button48 = (gcnew System::Windows::Forms::Button());
						this->button49 = (gcnew System::Windows::Forms::Button());
						this->button50 = (gcnew System::Windows::Forms::Button());
						this->tabPage20 = (gcnew System::Windows::Forms::TabPage());
						this->checkBox40 = (gcnew System::Windows::Forms::CheckBox());
						this->tabControl4 = (gcnew System::Windows::Forms::TabControl());
						this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
						this->panel4 = (gcnew System::Windows::Forms::Panel());
						this->groupBox19 = (gcnew System::Windows::Forms::GroupBox());
						this->groupBox20 = (gcnew System::Windows::Forms::GroupBox());
						this->groupBox21 = (gcnew System::Windows::Forms::GroupBox());
						this->numericUpDown22 = (gcnew System::Windows::Forms::NumericUpDown());
						this->numericUpDown23 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label47 = (gcnew System::Windows::Forms::Label());
						this->label48 = (gcnew System::Windows::Forms::Label());
						this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
						this->groupBox22 = (gcnew System::Windows::Forms::GroupBox());
						this->maskedTextBox9 = (gcnew System::Windows::Forms::MaskedTextBox());
						this->label49 = (gcnew System::Windows::Forms::Label());
						this->label50 = (gcnew System::Windows::Forms::Label());
						this->maskedTextBox10 = (gcnew System::Windows::Forms::MaskedTextBox());
						this->groupBox23 = (gcnew System::Windows::Forms::GroupBox());
						this->numericUpDown24 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label51 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown25 = (gcnew System::Windows::Forms::NumericUpDown());
						this->numericUpDown26 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label53 = (gcnew System::Windows::Forms::Label());
						this->label54 = (gcnew System::Windows::Forms::Label());
						this->label55 = (gcnew System::Windows::Forms::Label());
						this->label60 = (gcnew System::Windows::Forms::Label());
						this->label61 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown27 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label62 = (gcnew System::Windows::Forms::Label());
						this->label63 = (gcnew System::Windows::Forms::Label());
						this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
						this->label64 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown28 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label65 = (gcnew System::Windows::Forms::Label());
						this->label66 = (gcnew System::Windows::Forms::Label());
						this->groupBox24 = (gcnew System::Windows::Forms::GroupBox());
						this->label67 = (gcnew System::Windows::Forms::Label());
						this->label68 = (gcnew System::Windows::Forms::Label());
						this->label69 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown29 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label70 = (gcnew System::Windows::Forms::Label());
						this->label71 = (gcnew System::Windows::Forms::Label());
						this->label72 = (gcnew System::Windows::Forms::Label());
						this->label73 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown30 = (gcnew System::Windows::Forms::NumericUpDown());
						this->numericUpDown31 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label74 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown32 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label75 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown33 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label76 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown34 = (gcnew System::Windows::Forms::NumericUpDown());
						this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
						this->groupBox18 = (gcnew System::Windows::Forms::GroupBox());
						this->numericUpDown19 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label43 = (gcnew System::Windows::Forms::Label());
						this->label44 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown20 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label45 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown21 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label46 = (gcnew System::Windows::Forms::Label());
						this->groupBox17 = (gcnew System::Windows::Forms::GroupBox());
						this->maskedTextBox8 = (gcnew System::Windows::Forms::MaskedTextBox());
						this->label42 = (gcnew System::Windows::Forms::Label());
						this->label41 = (gcnew System::Windows::Forms::Label());
						this->label40 = (gcnew System::Windows::Forms::Label());
						this->label39 = (gcnew System::Windows::Forms::Label());
						this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
						this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
						this->tabPage25 = (gcnew System::Windows::Forms::TabPage());
						this->panel12 = (gcnew System::Windows::Forms::Panel());
						this->groupBox74 = (gcnew System::Windows::Forms::GroupBox());
						this->label239 = (gcnew System::Windows::Forms::Label());
						this->maskedTextBox47 = (gcnew System::Windows::Forms::MaskedTextBox());
						this->label240 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown82 = (gcnew System::Windows::Forms::NumericUpDown());
						this->numericUpDown83 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label241 = (gcnew System::Windows::Forms::Label());
						this->label242 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown84 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label243 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown85 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label244 = (gcnew System::Windows::Forms::Label());
						this->groupBox78 = (gcnew System::Windows::Forms::GroupBox());
						this->groupBox76 = (gcnew System::Windows::Forms::GroupBox());
						this->comboBox23 = (gcnew System::Windows::Forms::ComboBox());
						this->label254 = (gcnew System::Windows::Forms::Label());
						this->label252 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown86 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label253 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown87 = (gcnew System::Windows::Forms::NumericUpDown());
						this->groupBox72 = (gcnew System::Windows::Forms::GroupBox());
						this->numericUpDown81 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label238 = (gcnew System::Windows::Forms::Label());
						this->groupBox73 = (gcnew System::Windows::Forms::GroupBox());
						this->checkBox21 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox20 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox19 = (gcnew System::Windows::Forms::CheckBox());
						this->groupBox71 = (gcnew System::Windows::Forms::GroupBox());
						this->label200 = (gcnew System::Windows::Forms::Label());
						this->maskedTextBox46 = (gcnew System::Windows::Forms::MaskedTextBox());
						this->label226 = (gcnew System::Windows::Forms::Label());
						this->label221 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown79 = (gcnew System::Windows::Forms::NumericUpDown());
						this->maskedTextBox44 = (gcnew System::Windows::Forms::MaskedTextBox());
						this->label219 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown80 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label237 = (gcnew System::Windows::Forms::Label());
						this->groupBox68 = (gcnew System::Windows::Forms::GroupBox());
						this->label224 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown77 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label225 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown78 = (gcnew System::Windows::Forms::NumericUpDown());
						this->groupBox67 = (gcnew System::Windows::Forms::GroupBox());
						this->label227 = (gcnew System::Windows::Forms::Label());
						this->maskedTextBox45 = (gcnew System::Windows::Forms::MaskedTextBox());
						this->label220 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown76 = (gcnew System::Windows::Forms::NumericUpDown());
						this->numericUpDown75 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label222 = (gcnew System::Windows::Forms::Label());
						this->label213 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown74 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label212 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown73 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label206 = (gcnew System::Windows::Forms::Label());
						this->tabControl3 = (gcnew System::Windows::Forms::TabControl());
						this->tabPage9 = (gcnew System::Windows::Forms::TabPage());
						this->label269 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown69 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label223 = (gcnew System::Windows::Forms::Label());
						this->comboBox13 = (gcnew System::Windows::Forms::ComboBox());
						this->label22 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown35 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label82 = (gcnew System::Windows::Forms::Label());
						this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
						this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label20 = (gcnew System::Windows::Forms::Label());
						this->tabPage16 = (gcnew System::Windows::Forms::TabPage());
						this->textBox14 = (gcnew System::Windows::Forms::TextBox());
						this->textBox11 = (gcnew System::Windows::Forms::TextBox());
						this->label17 = (gcnew System::Windows::Forms::Label());
						this->textBox13 = (gcnew System::Windows::Forms::TextBox());
						this->label16 = (gcnew System::Windows::Forms::Label());
						this->textBox12 = (gcnew System::Windows::Forms::TextBox());
						this->label19 = (gcnew System::Windows::Forms::Label());
						this->label18 = (gcnew System::Windows::Forms::Label());
						this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
						this->tabControl7 = (gcnew System::Windows::Forms::TabControl());
						this->tabPage26 = (gcnew System::Windows::Forms::TabPage());
						this->groupBox32 = (gcnew System::Windows::Forms::GroupBox());
						this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
						this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
						this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
						this->groupBox31 = (gcnew System::Windows::Forms::GroupBox());
						this->textBox15 = (gcnew System::Windows::Forms::TextBox());
						this->textBox16 = (gcnew System::Windows::Forms::TextBox());
						this->textBox17 = (gcnew System::Windows::Forms::TextBox());
						this->label177 = (gcnew System::Windows::Forms::Label());
						this->label178 = (gcnew System::Windows::Forms::Label());
						this->label179 = (gcnew System::Windows::Forms::Label());
						this->textBox18 = (gcnew System::Windows::Forms::TextBox());
						this->label180 = (gcnew System::Windows::Forms::Label());
						this->groupBox33 = (gcnew System::Windows::Forms::GroupBox());
						this->textBox19 = (gcnew System::Windows::Forms::TextBox());
						this->textBox20 = (gcnew System::Windows::Forms::TextBox());
						this->label184 = (gcnew System::Windows::Forms::Label());
						this->textBox21 = (gcnew System::Windows::Forms::TextBox());
						this->label185 = (gcnew System::Windows::Forms::Label());
						this->textBox22 = (gcnew System::Windows::Forms::TextBox());
						this->label186 = (gcnew System::Windows::Forms::Label());
						this->label187 = (gcnew System::Windows::Forms::Label());
						this->tabPage27 = (gcnew System::Windows::Forms::TabPage());
						this->panel14 = (gcnew System::Windows::Forms::Panel());
						this->button11 = (gcnew System::Windows::Forms::Button());
						this->checkBox39 = (gcnew System::Windows::Forms::CheckBox());
						this->numericUpDown88 = (gcnew System::Windows::Forms::NumericUpDown());
						this->label250 = (gcnew System::Windows::Forms::Label());
						this->label251 = (gcnew System::Windows::Forms::Label());
						this->label181 = (gcnew System::Windows::Forms::Label());
						this->listBox1 = (gcnew System::Windows::Forms::ListBox());
						this->label182 = (gcnew System::Windows::Forms::Label());
						this->label183 = (gcnew System::Windows::Forms::Label());
						this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
						this->label188 = (gcnew System::Windows::Forms::Label());
						this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
						this->groupBox58 = (gcnew System::Windows::Forms::GroupBox());
						this->groupBox59 = (gcnew System::Windows::Forms::GroupBox());
						this->numericUpDown72 = (gcnew System::Windows::Forms::NumericUpDown());
						this->radioButton34 = (gcnew System::Windows::Forms::RadioButton());
						this->radioButton35 = (gcnew System::Windows::Forms::RadioButton());
						this->radioButton36 = (gcnew System::Windows::Forms::RadioButton());
						this->radioButton37 = (gcnew System::Windows::Forms::RadioButton());
						this->checkBox46 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox45 = (gcnew System::Windows::Forms::CheckBox());
						this->button24 = (gcnew System::Windows::Forms::Button());
						this->groupBox60 = (gcnew System::Windows::Forms::GroupBox());
						this->groupBox61 = (gcnew System::Windows::Forms::GroupBox());
						this->checkBox37 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox38 = (gcnew System::Windows::Forms::CheckBox());
						this->checkBox50 = (gcnew System::Windows::Forms::CheckBox());
						this->button25 = (gcnew System::Windows::Forms::Button());
						this->listBox2 = (gcnew System::Windows::Forms::ListBox());
						this->groupBox62 = (gcnew System::Windows::Forms::GroupBox());
						this->label207 = (gcnew System::Windows::Forms::Label());
						this->label208 = (gcnew System::Windows::Forms::Label());
						this->label209 = (gcnew System::Windows::Forms::Label());
						this->label210 = (gcnew System::Windows::Forms::Label());
						this->label211 = (gcnew System::Windows::Forms::Label());
						this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
						this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
						this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
						this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
						this->panel13 = (gcnew System::Windows::Forms::Panel());
						this->groupBox70 = (gcnew System::Windows::Forms::GroupBox());
						this->label236 = (gcnew System::Windows::Forms::Label());
						this->label235 = (gcnew System::Windows::Forms::Label());
						this->label234 = (gcnew System::Windows::Forms::Label());
						this->label233 = (gcnew System::Windows::Forms::Label());
						this->label232 = (gcnew System::Windows::Forms::Label());
						this->label231 = (gcnew System::Windows::Forms::Label());
						this->label230 = (gcnew System::Windows::Forms::Label());
						this->label229 = (gcnew System::Windows::Forms::Label());
						this->label228 = (gcnew System::Windows::Forms::Label());
						this->panel10 = (gcnew System::Windows::Forms::Panel());
						this->groupBox63 = (gcnew System::Windows::Forms::GroupBox());
						this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
						this->groupBox69 = (gcnew System::Windows::Forms::GroupBox());
						this->panel11 = (gcnew System::Windows::Forms::Panel());
						this->groupBox66 = (gcnew System::Windows::Forms::GroupBox());
						this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
						this->tableLayoutPanel1->SuspendLayout();
						this->toolStrip1->SuspendLayout();
						this->panel1->SuspendLayout();
						this->statusStrip1->SuspendLayout();
						this->tabControl1->SuspendLayout();
						this->tabPage1->SuspendLayout();
						this->groupBox2->SuspendLayout();
						this->groupBox1->SuspendLayout();
						this->tabPage2->SuspendLayout();
						this->tabControl6->SuspendLayout();
						this->tabPage21->SuspendLayout();
						this->tabControl5->SuspendLayout();
						this->tabPage15->SuspendLayout();
						this->panel15->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown59))->BeginInit();
						this->tabPage17->SuspendLayout();
						this->panel3->SuspendLayout();
						this->groupBox42->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar5))->BeginInit();
						this->tabPage18->SuspendLayout();
						this->tabPage19->SuspendLayout();
						this->groupBox3->SuspendLayout();
						this->tabPage20->SuspendLayout();
						this->tabControl4->SuspendLayout();
						this->tabPage8->SuspendLayout();
						this->panel4->SuspendLayout();
						this->groupBox19->SuspendLayout();
						this->groupBox20->SuspendLayout();
						this->groupBox21->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown22))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown23))->BeginInit();
						this->groupBox22->SuspendLayout();
						this->groupBox23->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown24))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown25))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown26))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown27))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown28))->BeginInit();
						this->groupBox24->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown29))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown30))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown31))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown32))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown33))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown34))->BeginInit();
						this->groupBox18->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown19))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown20))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown21))->BeginInit();
						this->groupBox17->SuspendLayout();
						this->tabPage25->SuspendLayout();
						this->panel12->SuspendLayout();
						this->groupBox74->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown82))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown83))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown84))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown85))->BeginInit();
						this->groupBox76->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown86))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown87))->BeginInit();
						this->groupBox72->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown81))->BeginInit();
						this->groupBox73->SuspendLayout();
						this->groupBox71->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown79))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown80))->BeginInit();
						this->groupBox68->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown77))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown78))->BeginInit();
						this->groupBox67->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown76))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown75))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown74))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown73))->BeginInit();
						this->tabControl3->SuspendLayout();
						this->tabPage9->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown69))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown35))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
						this->tabPage16->SuspendLayout();
						this->tabPage5->SuspendLayout();
						this->tabControl7->SuspendLayout();
						this->tabPage26->SuspendLayout();
						this->groupBox32->SuspendLayout();
						this->groupBox31->SuspendLayout();
						this->groupBox33->SuspendLayout();
						this->tabPage27->SuspendLayout();
						this->panel14->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown88))->BeginInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
						this->tabPage6->SuspendLayout();
						this->groupBox58->SuspendLayout();
						this->groupBox59->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown72))->BeginInit();
						this->groupBox60->SuspendLayout();
						this->groupBox61->SuspendLayout();
						this->groupBox62->SuspendLayout();
						this->tabControl2->SuspendLayout();
						this->tabPage3->SuspendLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
						this->tabPage4->SuspendLayout();
						this->panel13->SuspendLayout();
						this->groupBox70->SuspendLayout();
						this->panel10->SuspendLayout();
						this->groupBox69->SuspendLayout();
						this->panel11->SuspendLayout();
						this->SuspendLayout();
						// 
						// tableLayoutPanel1
						// 
						this->tableLayoutPanel1->ColumnCount = 2;
						this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
										69.19856F)));
						this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
										30.80144F)));
						this->tableLayoutPanel1->Controls->Add(this->toolStrip1, 0, 0);
						this->tableLayoutPanel1->Controls->Add(this->panel1, 1, 0);
						this->tableLayoutPanel1->Controls->Add(this->statusStrip1, 0, 2);
						this->tableLayoutPanel1->Controls->Add(this->tabControl1, 1, 1);
						this->tableLayoutPanel1->Controls->Add(this->tabControl2, 0, 1);
						this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
						this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
						this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
						this->tableLayoutPanel1->RowCount = 3;
						this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 2.970297F)));
						this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 97.0297F)));
						this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 29)));
						this->tableLayoutPanel1->Size = System::Drawing::Size(1672, 930);
						this->tableLayoutPanel1->TabIndex = 0;
						// 
						// toolStrip1
						// 
						this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripButton1});
						this->toolStrip1->Location = System::Drawing::Point(0, 0);
						this->toolStrip1->Name = L"toolStrip1";
						this->toolStrip1->Size = System::Drawing::Size(1156, 25);
						this->toolStrip1->TabIndex = 0;
						this->toolStrip1->Text = L"toolStrip1";
						// 
						// toolStripButton1
						// 
						this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
						this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
						this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
						this->toolStripButton1->Name = L"toolStripButton1";
						this->toolStripButton1->Size = System::Drawing::Size(23, 22);
						this->toolStripButton1->Text = L"toolStripButton1";
						this->toolStripButton1->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::toolStripButton1_Click);
						// 
						// panel1
						// 
						this->panel1->BackColor = System::Drawing::Color::Blue;
						this->panel1->Controls->Add(this->label2);
						this->panel1->Controls->Add(this->label1);
						this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
						this->panel1->Location = System::Drawing::Point(1159, 3);
						this->panel1->Name = L"panel1";
						this->panel1->Size = System::Drawing::Size(510, 20);
						this->panel1->TabIndex = 1;
						// 
						// label2
						// 
						this->label2->AutoSize = true;
						this->label2->ForeColor = System::Drawing::Color::White;
						this->label2->Location = System::Drawing::Point(217, 5);
						this->label2->Name = L"label2";
						this->label2->Size = System::Drawing::Size(10, 13);
						this->label2->TabIndex = 1;
						this->label2->Text = L"-";
						// 
						// label1
						// 
						this->label1->AutoSize = true;
						this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label1->ForeColor = System::Drawing::Color::White;
						this->label1->Location = System::Drawing::Point(1, 3);
						this->label1->Name = L"label1";
						this->label1->Size = System::Drawing::Size(205, 16);
						this->label1->TabIndex = 0;
						this->label1->Text = L"gSLAM (vector+EA+submap)";
						// 
						// statusStrip1
						// 
						this->statusStrip1->Dock = System::Windows::Forms::DockStyle::Fill;
						this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripStatusLabel1, 
										this->toolStripProgressBar1});
						this->statusStrip1->Location = System::Drawing::Point(0, 900);
						this->statusStrip1->Name = L"statusStrip1";
						this->statusStrip1->Size = System::Drawing::Size(1156, 30);
						this->statusStrip1->TabIndex = 2;
						this->statusStrip1->Text = L"statusStrip1";
						// 
						// toolStripStatusLabel1
						// 
						this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
						this->toolStripStatusLabel1->Size = System::Drawing::Size(31, 25);
						this->toolStripStatusLabel1->Text = L"Info:";
						// 
						// toolStripProgressBar1
						// 
						this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
						this->toolStripProgressBar1->Size = System::Drawing::Size(300, 24);
						// 
						// tabControl1
						// 
						this->tabControl1->Controls->Add(this->tabPage1);
						this->tabControl1->Controls->Add(this->tabPage2);
						this->tabControl1->Controls->Add(this->tabPage5);
						this->tabControl1->Controls->Add(this->tabPage6);
						this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
						this->tabControl1->Location = System::Drawing::Point(1159, 29);
						this->tabControl1->Name = L"tabControl1";
						this->tabControl1->SelectedIndex = 0;
						this->tabControl1->Size = System::Drawing::Size(510, 868);
						this->tabControl1->TabIndex = 3;
						// 
						// tabPage1
						// 
						this->tabPage1->Controls->Add(this->groupBox2);
						this->tabPage1->Controls->Add(this->groupBox1);
						this->tabPage1->Location = System::Drawing::Point(4, 22);
						this->tabPage1->Name = L"tabPage1";
						this->tabPage1->Padding = System::Windows::Forms::Padding(3);
						this->tabPage1->Size = System::Drawing::Size(502, 842);
						this->tabPage1->TabIndex = 0;
						this->tabPage1->Text = L"Files";
						this->tabPage1->UseVisualStyleBackColor = true;
						// 
						// groupBox2
						// 
						this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->groupBox2->Controls->Add(this->button10);
						this->groupBox2->Controls->Add(this->button6);
						this->groupBox2->Controls->Add(this->label7);
						this->groupBox2->Controls->Add(this->button5);
						this->groupBox2->Controls->Add(this->label6);
						this->groupBox2->Controls->Add(this->textBox5);
						this->groupBox2->Controls->Add(this->button4);
						this->groupBox2->Controls->Add(this->textBox4);
						this->groupBox2->Controls->Add(this->label5);
						this->groupBox2->Controls->Add(this->textBox3);
						this->groupBox2->Location = System::Drawing::Point(3, 188);
						this->groupBox2->Name = L"groupBox2";
						this->groupBox2->Size = System::Drawing::Size(496, 257);
						this->groupBox2->TabIndex = 1;
						this->groupBox2->TabStop = false;
						this->groupBox2->Text = L"Output Files";
						// 
						// button10
						// 
						this->button10->Location = System::Drawing::Point(392, 58);
						this->button10->Name = L"button10";
						this->button10->Size = System::Drawing::Size(95, 30);
						this->button10->TabIndex = 3;
						this->button10->Text = L"AutoFillUpAll";
						this->button10->UseVisualStyleBackColor = true;
						this->button10->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button10_Click);
						// 
						// button6
						// 
						this->button6->Location = System::Drawing::Point(6, 217);
						this->button6->Name = L"button6";
						this->button6->Size = System::Drawing::Size(211, 30);
						this->button6->TabIndex = 2;
						this->button6->Text = L"Define directory";
						this->button6->UseVisualStyleBackColor = true;
						this->button6->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button6_Click);
						// 
						// label7
						// 
						this->label7->AutoSize = true;
						this->label7->Location = System::Drawing::Point(6, 175);
						this->label7->Name = L"label7";
						this->label7->Size = System::Drawing::Size(282, 13);
						this->label7->TabIndex = 0;
						this->label7->Text = L"Define directory for screenshots + others data auto-saving.";
						// 
						// button5
						// 
						this->button5->Location = System::Drawing::Point(6, 137);
						this->button5->Name = L"button5";
						this->button5->Size = System::Drawing::Size(211, 30);
						this->button5->TabIndex = 2;
						this->button5->Text = L"Define TXT file";
						this->button5->UseVisualStyleBackColor = true;
						this->button5->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button5_Click);
						// 
						// label6
						// 
						this->label6->AutoSize = true;
						this->label6->Location = System::Drawing::Point(6, 95);
						this->label6->Name = L"label6";
						this->label6->Size = System::Drawing::Size(262, 13);
						this->label6->TabIndex = 0;
						this->label6->Text = L"Define TXT file name for export of data of robot\'s pose";
						// 
						// textBox5
						// 
						this->textBox5->Location = System::Drawing::Point(6, 191);
						this->textBox5->Name = L"textBox5";
						this->textBox5->Size = System::Drawing::Size(481, 20);
						this->textBox5->TabIndex = 1;
						// 
						// button4
						// 
						this->button4->Location = System::Drawing::Point(6, 58);
						this->button4->Name = L"button4";
						this->button4->Size = System::Drawing::Size(211, 30);
						this->button4->TabIndex = 2;
						this->button4->Text = L"Define PTH file";
						this->button4->UseVisualStyleBackColor = true;
						this->button4->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button4_Click);
						// 
						// textBox4
						// 
						this->textBox4->Location = System::Drawing::Point(6, 111);
						this->textBox4->Name = L"textBox4";
						this->textBox4->Size = System::Drawing::Size(481, 20);
						this->textBox4->TabIndex = 1;
						// 
						// label5
						// 
						this->label5->AutoSize = true;
						this->label5->Location = System::Drawing::Point(6, 16);
						this->label5->Name = L"label5";
						this->label5->Size = System::Drawing::Size(276, 13);
						this->label5->TabIndex = 0;
						this->label5->Text = L"Define PTH file name, output data file for found positions:";
						// 
						// textBox3
						// 
						this->textBox3->Location = System::Drawing::Point(6, 32);
						this->textBox3->Name = L"textBox3";
						this->textBox3->Size = System::Drawing::Size(481, 20);
						this->textBox3->TabIndex = 1;
						// 
						// groupBox1
						// 
						this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->groupBox1->Controls->Add(this->checkBox44);
						this->groupBox1->Controls->Add(this->button3);
						this->groupBox1->Controls->Add(this->button2);
						this->groupBox1->Controls->Add(this->textBox2);
						this->groupBox1->Controls->Add(this->button1);
						this->groupBox1->Controls->Add(this->label4);
						this->groupBox1->Controls->Add(this->textBox1);
						this->groupBox1->Controls->Add(this->label3);
						this->groupBox1->Location = System::Drawing::Point(3, 6);
						this->groupBox1->Name = L"groupBox1";
						this->groupBox1->Size = System::Drawing::Size(496, 176);
						this->groupBox1->TabIndex = 0;
						this->groupBox1->TabStop = false;
						this->groupBox1->Text = L"Input Files";
						// 
						// checkBox44
						// 
						this->checkBox44->AutoSize = true;
						this->checkBox44->Checked = true;
						this->checkBox44->CheckState = System::Windows::Forms::CheckState::Checked;
						this->checkBox44->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
						this->checkBox44->Location = System::Drawing::Point(378, 58);
						this->checkBox44->Name = L"checkBox44";
						this->checkBox44->Size = System::Drawing::Size(107, 17);
						this->checkBox44->TabIndex = 4;
						this->checkBox44->Text = L"Draw MapPattern";
						this->checkBox44->UseVisualStyleBackColor = true;
						// 
						// button3
						// 
						this->button3->Location = System::Drawing::Point(416, 137);
						this->button3->Name = L"button3";
						this->button3->Size = System::Drawing::Size(71, 30);
						this->button3->TabIndex = 3;
						this->button3->Text = L"RESET";
						this->button3->UseVisualStyleBackColor = true;
						this->button3->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button3_Click);
						// 
						// button2
						// 
						this->button2->Location = System::Drawing::Point(6, 137);
						this->button2->Name = L"button2";
						this->button2->Size = System::Drawing::Size(211, 30);
						this->button2->TabIndex = 2;
						this->button2->Text = L"Open LSB file";
						this->button2->UseVisualStyleBackColor = true;
						this->button2->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button2_Click);
						// 
						// textBox2
						// 
						this->textBox2->Location = System::Drawing::Point(6, 111);
						this->textBox2->Name = L"textBox2";
						this->textBox2->Size = System::Drawing::Size(481, 20);
						this->textBox2->TabIndex = 1;
						// 
						// button1
						// 
						this->button1->Location = System::Drawing::Point(6, 58);
						this->button1->Name = L"button1";
						this->button1->Size = System::Drawing::Size(211, 30);
						this->button1->TabIndex = 2;
						this->button1->Text = L"Open PLB file";
						this->button1->UseVisualStyleBackColor = true;
						this->button1->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button1_Click);
						// 
						// label4
						// 
						this->label4->AutoSize = true;
						this->label4->Location = System::Drawing::Point(6, 95);
						this->label4->Name = L"label4";
						this->label4->Size = System::Drawing::Size(191, 13);
						this->label4->TabIndex = 0;
						this->label4->Text = L"Open LSB file, data from LaserScanner";
						// 
						// textBox1
						// 
						this->textBox1->Location = System::Drawing::Point(6, 32);
						this->textBox1->Name = L"textBox1";
						this->textBox1->Size = System::Drawing::Size(481, 20);
						this->textBox1->TabIndex = 1;
						// 
						// label3
						// 
						this->label3->AutoSize = true;
						this->label3->Location = System::Drawing::Point(6, 16);
						this->label3->Name = L"label3";
						this->label3->Size = System::Drawing::Size(214, 13);
						this->label3->TabIndex = 0;
						this->label3->Text = L"Open PLB file, frame of min/max dimensions";
						// 
						// tabPage2
						// 
						this->tabPage2->Controls->Add(this->tabControl6);
						this->tabPage2->Controls->Add(this->label176);
						this->tabPage2->Controls->Add(this->tabControl5);
						this->tabPage2->Controls->Add(this->tabControl4);
						this->tabPage2->Controls->Add(this->tabControl3);
						this->tabPage2->Location = System::Drawing::Point(4, 22);
						this->tabPage2->Name = L"tabPage2";
						this->tabPage2->Padding = System::Windows::Forms::Padding(3);
						this->tabPage2->Size = System::Drawing::Size(502, 842);
						this->tabPage2->TabIndex = 1;
						this->tabPage2->Text = L"RUN / Parameters";
						this->tabPage2->UseVisualStyleBackColor = true;
						// 
						// tabControl6
						// 
						this->tabControl6->Controls->Add(this->tabPage21);
						this->tabControl6->Location = System::Drawing::Point(0, 627);
						this->tabControl6->Name = L"tabControl6";
						this->tabControl6->SelectedIndex = 0;
						this->tabControl6->Size = System::Drawing::Size(502, 215);
						this->tabControl6->TabIndex = 54;
						// 
						// tabPage21
						// 
						this->tabPage21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(255)));
						this->tabPage21->Controls->Add(this->label88);
						this->tabPage21->Controls->Add(this->label87);
						this->tabPage21->Controls->Add(this->button7);
						this->tabPage21->Controls->Add(this->label86);
						this->tabPage21->Controls->Add(this->button8);
						this->tabPage21->Controls->Add(this->label85);
						this->tabPage21->Controls->Add(this->button9);
						this->tabPage21->Controls->Add(this->label84);
						this->tabPage21->Controls->Add(this->label83);
						this->tabPage21->Controls->Add(this->label81);
						this->tabPage21->Location = System::Drawing::Point(4, 22);
						this->tabPage21->Name = L"tabPage21";
						this->tabPage21->Padding = System::Windows::Forms::Padding(3);
						this->tabPage21->Size = System::Drawing::Size(494, 189);
						this->tabPage21->TabIndex = 0;
						this->tabPage21->Text = L"ActualState";
						// 
						// label88
						// 
						this->label88->AutoSize = true;
						this->label88->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label88->Location = System::Drawing::Point(5, 116);
						this->label88->Name = L"label88";
						this->label88->Size = System::Drawing::Size(97, 15);
						this->label88->TabIndex = 1;
						this->label88->Text = L"Start / StopTime:";
						// 
						// label87
						// 
						this->label87->AutoSize = true;
						this->label87->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label87->Location = System::Drawing::Point(3, 57);
						this->label87->Name = L"label87";
						this->label87->Size = System::Drawing::Size(82, 15);
						this->label87->TabIndex = 1;
						this->label87->Text = L"Generation:";
						// 
						// button7
						// 
						this->button7->ForeColor = System::Drawing::SystemColors::ControlText;
						this->button7->Location = System::Drawing::Point(407, 140);
						this->button7->Name = L"button7";
						this->button7->Size = System::Drawing::Size(85, 20);
						this->button7->TabIndex = 50;
						this->button7->Text = L"Pause/Stop";
						this->button7->UseVisualStyleBackColor = true;
						this->button7->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button7_Click);
						// 
						// label86
						// 
						this->label86->AutoSize = true;
						this->label86->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label86->Location = System::Drawing::Point(6, 76);
						this->label86->Name = L"label86";
						this->label86->Size = System::Drawing::Size(62, 15);
						this->label86->TabIndex = 1;
						this->label86->Text = L"Algorithm:";
						// 
						// button8
						// 
						this->button8->Location = System::Drawing::Point(407, 163);
						this->button8->Name = L"button8";
						this->button8->Size = System::Drawing::Size(85, 20);
						this->button8->TabIndex = 51;
						this->button8->Text = L"Reset";
						this->button8->UseVisualStyleBackColor = true;
						this->button8->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button8_Click);
						// 
						// label85
						// 
						this->label85->AutoSize = true;
						this->label85->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label85->Location = System::Drawing::Point(3, 36);
						this->label85->Name = L"label85";
						this->label85->Size = System::Drawing::Size(69, 15);
						this->label85->TabIndex = 1;
						this->label85->Text = L"Optimum:";
						// 
						// button9
						// 
						this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->button9->Location = System::Drawing::Point(4, 140);
						this->button9->Name = L"button9";
						this->button9->Size = System::Drawing::Size(397, 43);
						this->button9->TabIndex = 52;
						this->button9->Text = L"START SEARCHING";
						this->button9->UseVisualStyleBackColor = true;
						this->button9->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button9_Click);
						// 
						// label84
						// 
						this->label84->AutoSize = true;
						this->label84->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label84->Location = System::Drawing::Point(3, 21);
						this->label84->Name = L"label84";
						this->label84->Size = System::Drawing::Size(63, 15);
						this->label84->TabIndex = 1;
						this->label84->Text = L"Position:";
						// 
						// label83
						// 
						this->label83->AutoSize = true;
						this->label83->Location = System::Drawing::Point(3, 3);
						this->label83->Name = L"label83";
						this->label83->Size = System::Drawing::Size(79, 13);
						this->label83->TabIndex = 0;
						this->label83->Text = L"Actual sample: ";
						// 
						// label81
						// 
						this->label81->AutoSize = true;
						this->label81->Location = System::Drawing::Point(288, 3);
						this->label81->Name = L"label81";
						this->label81->Size = System::Drawing::Size(74, 13);
						this->label81->TabIndex = 0;
						this->label81->Text = L"Start sample:  ";
						// 
						// label176
						// 
						this->label176->AutoSize = true;
						this->label176->BackColor = System::Drawing::Color::Yellow;
						this->label176->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label176->Location = System::Drawing::Point(1, 608);
						this->label176->Name = L"label176";
						this->label176->Size = System::Drawing::Size(117, 16);
						this->label176->TabIndex = 53;
						this->label176->Text = L"Mouse position:";
						// 
						// tabControl5
						// 
						this->tabControl5->Controls->Add(this->tabPage15);
						this->tabControl5->Controls->Add(this->tabPage17);
						this->tabControl5->Controls->Add(this->tabPage18);
						this->tabControl5->Controls->Add(this->tabPage19);
						this->tabControl5->Controls->Add(this->tabPage20);
						this->tabControl5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->tabControl5->Location = System::Drawing::Point(2, 447);
						this->tabControl5->Name = L"tabControl5";
						this->tabControl5->SelectedIndex = 0;
						this->tabControl5->Size = System::Drawing::Size(496, 158);
						this->tabControl5->TabIndex = 49;
						// 
						// tabPage15
						// 
						this->tabPage15->BackColor = System::Drawing::Color::White;
						this->tabPage15->Controls->Add(this->panel15);
						this->tabPage15->Location = System::Drawing::Point(4, 21);
						this->tabPage15->Name = L"tabPage15";
						this->tabPage15->Padding = System::Windows::Forms::Padding(3);
						this->tabPage15->Size = System::Drawing::Size(488, 133);
						this->tabPage15->TabIndex = 0;
						this->tabPage15->Text = L"Draw / Runtime ";
						// 
						// panel15
						// 
						this->panel15->AutoScroll = true;
						this->panel15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->panel15->Controls->Add(this->numericUpDown59);
						this->panel15->Controls->Add(this->checkBox27);
						this->panel15->Controls->Add(this->checkBox26);
						this->panel15->Controls->Add(this->checkBox23);
						this->panel15->Controls->Add(this->label169);
						this->panel15->Controls->Add(this->checkBox22);
						this->panel15->Controls->Add(this->checkBox32);
						this->panel15->Controls->Add(this->checkBox24);
						this->panel15->Controls->Add(this->checkBox33);
						this->panel15->Controls->Add(this->checkBox30);
						this->panel15->Controls->Add(this->checkBox34);
						this->panel15->Controls->Add(this->checkBox25);
						this->panel15->Controls->Add(this->checkBox35);
						this->panel15->Controls->Add(this->checkBox31);
						this->panel15->Location = System::Drawing::Point(0, 0);
						this->panel15->Name = L"panel15";
						this->panel15->Size = System::Drawing::Size(488, 133);
						this->panel15->TabIndex = 0;
						// 
						// numericUpDown59
						// 
						this->numericUpDown59->Location = System::Drawing::Point(416, 109);
						this->numericUpDown59->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown59->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown59->Name = L"numericUpDown59";
						this->numericUpDown59->Size = System::Drawing::Size(51, 18);
						this->numericUpDown59->TabIndex = 36;
						this->numericUpDown59->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {70, 0, 0, 0});
						// 
						// checkBox27
						// 
						this->checkBox27->AutoSize = true;
						this->checkBox27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox27->Location = System::Drawing::Point(91, 4);
						this->checkBox27->Name = L"checkBox27";
						this->checkBox27->Size = System::Drawing::Size(99, 16);
						this->checkBox27->TabIndex = 28;
						this->checkBox27->Text = L"Draw Actual Pose";
						this->checkBox27->UseVisualStyleBackColor = true;
						// 
						// checkBox26
						// 
						this->checkBox26->AutoSize = true;
						this->checkBox26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox26->Location = System::Drawing::Point(15, 21);
						this->checkBox26->Name = L"checkBox26";
						this->checkBox26->Size = System::Drawing::Size(138, 16);
						this->checkBox26->TabIndex = 28;
						this->checkBox26->Text = L"Draw Local Scan Over Map";
						this->checkBox26->UseVisualStyleBackColor = true;
						// 
						// checkBox23
						// 
						this->checkBox23->AutoSize = true;
						this->checkBox23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox23->Location = System::Drawing::Point(3, 93);
						this->checkBox23->Name = L"checkBox23";
						this->checkBox23->Size = System::Drawing::Size(96, 16);
						this->checkBox23->TabIndex = 28;
						this->checkBox23->Text = L"Draw Global Map";
						this->checkBox23->UseVisualStyleBackColor = true;
						// 
						// label169
						// 
						this->label169->AutoSize = true;
						this->label169->Location = System::Drawing::Point(392, 91);
						this->label169->Name = L"label169";
						this->label169->Size = System::Drawing::Size(73, 12);
						this->label169->TabIndex = 38;
						this->label169->Text = L"Robot magnifier:";
						// 
						// checkBox22
						// 
						this->checkBox22->AutoSize = true;
						this->checkBox22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox22->Location = System::Drawing::Point(3, 108);
						this->checkBox22->Name = L"checkBox22";
						this->checkBox22->Size = System::Drawing::Size(114, 16);
						this->checkBox22->TabIndex = 28;
						this->checkBox22->Text = L"Draw Temporary Map";
						this->checkBox22->UseVisualStyleBackColor = true;
						// 
						// checkBox32
						// 
						this->checkBox32->AutoSize = true;
						this->checkBox32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox32->Location = System::Drawing::Point(313, 22);
						this->checkBox32->Name = L"checkBox32";
						this->checkBox32->Size = System::Drawing::Size(111, 16);
						this->checkBox32->TabIndex = 30;
						this->checkBox32->Text = L"Obelize Robot\'s pose";
						this->checkBox32->UseVisualStyleBackColor = true;
						// 
						// checkBox24
						// 
						this->checkBox24->AutoSize = true;
						this->checkBox24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox24->Location = System::Drawing::Point(3, 77);
						this->checkBox24->Name = L"checkBox24";
						this->checkBox24->Size = System::Drawing::Size(107, 16);
						this->checkBox24->TabIndex = 28;
						this->checkBox24->Text = L"Draw AddedEntities";
						this->checkBox24->UseVisualStyleBackColor = true;
						// 
						// checkBox33
						// 
						this->checkBox33->AutoSize = true;
						this->checkBox33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox33->Location = System::Drawing::Point(117, 93);
						this->checkBox33->Name = L"checkBox33";
						this->checkBox33->Size = System::Drawing::Size(139, 16);
						this->checkBox33->TabIndex = 33;
						this->checkBox33->Text = L"Show begin/end of GM lines";
						this->checkBox33->UseVisualStyleBackColor = true;
						// 
						// checkBox30
						// 
						this->checkBox30->AutoSize = true;
						this->checkBox30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox30->Location = System::Drawing::Point(29, 40);
						this->checkBox30->Name = L"checkBox30";
						this->checkBox30->Size = System::Drawing::Size(104, 16);
						this->checkBox30->TabIndex = 28;
						this->checkBox30->Text = L"Draw static objects";
						this->checkBox30->UseVisualStyleBackColor = true;
						// 
						// checkBox34
						// 
						this->checkBox34->AutoSize = true;
						this->checkBox34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox34->Location = System::Drawing::Point(29, 55);
						this->checkBox34->Name = L"checkBox34";
						this->checkBox34->Size = System::Drawing::Size(112, 16);
						this->checkBox34->TabIndex = 31;
						this->checkBox34->Text = L"Draw moving objects";
						this->checkBox34->UseVisualStyleBackColor = true;
						// 
						// checkBox25
						// 
						this->checkBox25->AutoSize = true;
						this->checkBox25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox25->Location = System::Drawing::Point(3, 4);
						this->checkBox25->Name = L"checkBox25";
						this->checkBox25->Size = System::Drawing::Size(88, 16);
						this->checkBox25->TabIndex = 28;
						this->checkBox25->Text = L"Draw All Poses";
						this->checkBox25->UseVisualStyleBackColor = true;
						// 
						// checkBox35
						// 
						this->checkBox35->AutoSize = true;
						this->checkBox35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox35->Location = System::Drawing::Point(117, 77);
						this->checkBox35->Name = L"checkBox35";
						this->checkBox35->Size = System::Drawing::Size(119, 16);
						this->checkBox35->TabIndex = 32;
						this->checkBox35->Text = L"Show Every population";
						this->checkBox35->UseVisualStyleBackColor = true;
						// 
						// checkBox31
						// 
						this->checkBox31->AutoSize = true;
						this->checkBox31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox31->Location = System::Drawing::Point(157, 21);
						this->checkBox31->Name = L"checkBox31";
						this->checkBox31->Size = System::Drawing::Size(151, 16);
						this->checkBox31->TabIndex = 29;
						this->checkBox31->Text = L"Show robot\'s pose and heading";
						this->checkBox31->UseVisualStyleBackColor = true;
						// 
						// tabPage17
						// 
						this->tabPage17->BackColor = System::Drawing::Color::White;
						this->tabPage17->Controls->Add(this->panel3);
						this->tabPage17->Location = System::Drawing::Point(4, 21);
						this->tabPage17->Name = L"tabPage17";
						this->tabPage17->Padding = System::Windows::Forms::Padding(3);
						this->tabPage17->Size = System::Drawing::Size(488, 133);
						this->tabPage17->TabIndex = 1;
						this->tabPage17->Text = L"Process";
						// 
						// panel3
						// 
						this->panel3->AutoScroll = true;
						this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->panel3->Controls->Add(this->label214);
						this->panel3->Controls->Add(this->checkBox48);
						this->panel3->Controls->Add(this->groupBox42);
						this->panel3->Controls->Add(this->checkBox29);
						this->panel3->Location = System::Drawing::Point(0, -8);
						this->panel3->Name = L"panel3";
						this->panel3->Size = System::Drawing::Size(488, 141);
						this->panel3->TabIndex = 0;
						// 
						// label214
						// 
						this->label214->AutoSize = true;
						this->label214->BackColor = System::Drawing::Color::Red;
						this->label214->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label214->ForeColor = System::Drawing::Color::White;
						this->label214->Location = System::Drawing::Point(2, 11);
						this->label214->Name = L"label214";
						this->label214->Size = System::Drawing::Size(106, 15);
						this->label214->TabIndex = 62;
						this->label214->Text = L"Process Status:";
						// 
						// checkBox48
						// 
						this->checkBox48->AutoSize = true;
						this->checkBox48->Location = System::Drawing::Point(4, 48);
						this->checkBox48->Name = L"checkBox48";
						this->checkBox48->Size = System::Drawing::Size(77, 16);
						this->checkBox48->TabIndex = 60;
						this->checkBox48->Text = L"AutoAppExit";
						this->checkBox48->UseVisualStyleBackColor = true;
						// 
						// groupBox42
						// 
						this->groupBox42->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(128)));
						this->groupBox42->Controls->Add(this->label168);
						this->groupBox42->Controls->Add(this->trackBar5);
						this->groupBox42->Location = System::Drawing::Point(338, 25);
						this->groupBox42->Name = L"groupBox42";
						this->groupBox42->Size = System::Drawing::Size(131, 53);
						this->groupBox42->TabIndex = 0;
						this->groupBox42->TabStop = false;
						this->groupBox42->Text = L"MasterPriority";
						// 
						// label168
						// 
						this->label168->AutoSize = true;
						this->label168->Location = System::Drawing::Point(4, 14);
						this->label168->Name = L"label168";
						this->label168->Size = System::Drawing::Size(66, 12);
						this->label168->TabIndex = 36;
						this->label168->Text = L"Priority Normal";
						// 
						// trackBar5
						// 
						this->trackBar5->AutoSize = false;
						this->trackBar5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
										static_cast<System::Int32>(static_cast<System::Byte>(224)));
						this->trackBar5->Location = System::Drawing::Point(5, 27);
						this->trackBar5->Maximum = 6;
						this->trackBar5->Minimum = 1;
						this->trackBar5->Name = L"trackBar5";
						this->trackBar5->Size = System::Drawing::Size(120, 21);
						this->trackBar5->TabIndex = 35;
						this->trackBar5->Value = 3;
						this->trackBar5->ValueChanged += gcnew System::EventHandler(this, &MapBuilding_LM104::trackBar5_ValueChanged);
						// 
						// checkBox29
						// 
						this->checkBox29->AutoSize = true;
						this->checkBox29->Location = System::Drawing::Point(4, 31);
						this->checkBox29->Name = L"checkBox29";
						this->checkBox29->Size = System::Drawing::Size(76, 16);
						this->checkBox29->TabIndex = 34;
						this->checkBox29->Text = L"Debug mode";
						this->checkBox29->UseVisualStyleBackColor = true;
						// 
						// tabPage18
						// 
						this->tabPage18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->tabPage18->Controls->Add(this->checkBox36);
						this->tabPage18->Controls->Add(this->checkBox52);
						this->tabPage18->Location = System::Drawing::Point(4, 21);
						this->tabPage18->Name = L"tabPage18";
						this->tabPage18->Padding = System::Windows::Forms::Padding(3);
						this->tabPage18->Size = System::Drawing::Size(488, 133);
						this->tabPage18->TabIndex = 2;
						this->tabPage18->Text = L"AutoSave";
						// 
						// checkBox36
						// 
						this->checkBox36->AutoSize = true;
						this->checkBox36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox36->Location = System::Drawing::Point(3, 21);
						this->checkBox36->Name = L"checkBox36";
						this->checkBox36->Size = System::Drawing::Size(110, 16);
						this->checkBox36->TabIndex = 33;
						this->checkBox36->Text = L"Write data to PTH file";
						this->checkBox36->UseVisualStyleBackColor = true;
						// 
						// checkBox52
						// 
						this->checkBox52->AutoSize = true;
						this->checkBox52->Location = System::Drawing::Point(3, 3);
						this->checkBox52->Name = L"checkBox52";
						this->checkBox52->Size = System::Drawing::Size(81, 16);
						this->checkBox52->TabIndex = 9;
						this->checkBox52->Text = L"Write Info File";
						this->checkBox52->UseVisualStyleBackColor = true;
						// 
						// tabPage19
						// 
						this->tabPage19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->tabPage19->Controls->Add(this->groupBox3);
						this->tabPage19->Location = System::Drawing::Point(4, 21);
						this->tabPage19->Name = L"tabPage19";
						this->tabPage19->Padding = System::Windows::Forms::Padding(3);
						this->tabPage19->Size = System::Drawing::Size(488, 133);
						this->tabPage19->TabIndex = 3;
						this->tabPage19->Text = L"AutoProperties";
						// 
						// groupBox3
						// 
						this->groupBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->groupBox3->Controls->Add(this->checkBox57);
						this->groupBox3->Controls->Add(this->button48);
						this->groupBox3->Controls->Add(this->button49);
						this->groupBox3->Controls->Add(this->button50);
						this->groupBox3->Location = System::Drawing::Point(5, 7);
						this->groupBox3->Name = L"groupBox3";
						this->groupBox3->Size = System::Drawing::Size(305, 71);
						this->groupBox3->TabIndex = 1;
						this->groupBox3->TabStop = false;
						this->groupBox3->Text = L"Properties settings";
						// 
						// checkBox57
						// 
						this->checkBox57->AutoSize = true;
						this->checkBox57->Location = System::Drawing::Point(6, 49);
						this->checkBox57->Name = L"checkBox57";
						this->checkBox57->Size = System::Drawing::Size(137, 16);
						this->checkBox57->TabIndex = 1;
						this->checkBox57->Text = L"Auto reload settings at start";
						this->checkBox57->UseVisualStyleBackColor = true;
						// 
						// button48
						// 
						this->button48->Location = System::Drawing::Point(206, 19);
						this->button48->Name = L"button48";
						this->button48->Size = System::Drawing::Size(94, 24);
						this->button48->TabIndex = 0;
						this->button48->Text = L"FactorySettings";
						this->button48->UseVisualStyleBackColor = true;
						this->button48->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button48_Click);
						// 
						// button49
						// 
						this->button49->Location = System::Drawing::Point(106, 19);
						this->button49->Name = L"button49";
						this->button49->Size = System::Drawing::Size(94, 24);
						this->button49->TabIndex = 0;
						this->button49->Text = L"SaveSettings";
						this->button49->UseVisualStyleBackColor = true;
						this->button49->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button49_Click);
						// 
						// button50
						// 
						this->button50->Location = System::Drawing::Point(6, 19);
						this->button50->Name = L"button50";
						this->button50->Size = System::Drawing::Size(94, 24);
						this->button50->TabIndex = 0;
						this->button50->Text = L"ReloadSettings";
						this->button50->UseVisualStyleBackColor = true;
						this->button50->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button50_Click);
						// 
						// tabPage20
						// 
						this->tabPage20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->tabPage20->Controls->Add(this->checkBox40);
						this->tabPage20->Location = System::Drawing::Point(4, 21);
						this->tabPage20->Name = L"tabPage20";
						this->tabPage20->Padding = System::Windows::Forms::Padding(3);
						this->tabPage20->Size = System::Drawing::Size(488, 133);
						this->tabPage20->TabIndex = 4;
						this->tabPage20->Text = L"Misc";
						// 
						// checkBox40
						// 
						this->checkBox40->AutoSize = true;
						this->checkBox40->Location = System::Drawing::Point(6, 6);
						this->checkBox40->Name = L"checkBox40";
						this->checkBox40->Size = System::Drawing::Size(113, 16);
						this->checkBox40->TabIndex = 8;
						this->checkBox40->Text = L"Play signal at the end.";
						this->checkBox40->UseVisualStyleBackColor = true;
						// 
						// tabControl4
						// 
						this->tabControl4->Controls->Add(this->tabPage8);
						this->tabControl4->Controls->Add(this->tabPage25);
						this->tabControl4->Location = System::Drawing::Point(0, 95);
						this->tabControl4->Name = L"tabControl4";
						this->tabControl4->SelectedIndex = 0;
						this->tabControl4->Size = System::Drawing::Size(502, 346);
						this->tabControl4->TabIndex = 5;
						// 
						// tabPage8
						// 
						this->tabPage8->Controls->Add(this->panel4);
						this->tabPage8->Location = System::Drawing::Point(4, 22);
						this->tabPage8->Name = L"tabPage8";
						this->tabPage8->Padding = System::Windows::Forms::Padding(3);
						this->tabPage8->Size = System::Drawing::Size(494, 320);
						this->tabPage8->TabIndex = 1;
						this->tabPage8->Text = L"Scanner";
						this->tabPage8->UseVisualStyleBackColor = true;
						// 
						// panel4
						// 
						this->panel4->AutoScroll = true;
						this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->panel4->Controls->Add(this->groupBox19);
						this->panel4->Controls->Add(this->groupBox18);
						this->panel4->Controls->Add(this->groupBox17);
						this->panel4->Location = System::Drawing::Point(0, 0);
						this->panel4->Name = L"panel4";
						this->panel4->Size = System::Drawing::Size(494, 320);
						this->panel4->TabIndex = 1;
						// 
						// groupBox19
						// 
						this->groupBox19->Controls->Add(this->groupBox20);
						this->groupBox19->Controls->Add(this->groupBox24);
						this->groupBox19->Controls->Add(this->comboBox8);
						this->groupBox19->Location = System::Drawing::Point(2, 132);
						this->groupBox19->Name = L"groupBox19";
						this->groupBox19->Size = System::Drawing::Size(471, 450);
						this->groupBox19->TabIndex = 4;
						this->groupBox19->TabStop = false;
						this->groupBox19->Text = L"Searching method";
						// 
						// groupBox20
						// 
						this->groupBox20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->groupBox20->Controls->Add(this->groupBox21);
						this->groupBox20->Controls->Add(this->groupBox22);
						this->groupBox20->Controls->Add(this->groupBox23);
						this->groupBox20->Controls->Add(this->comboBox6);
						this->groupBox20->Controls->Add(this->label64);
						this->groupBox20->Controls->Add(this->numericUpDown28);
						this->groupBox20->Controls->Add(this->label65);
						this->groupBox20->Controls->Add(this->label66);
						this->groupBox20->Location = System::Drawing::Point(4, 121);
						this->groupBox20->Name = L"groupBox20";
						this->groupBox20->Size = System::Drawing::Size(463, 291);
						this->groupBox20->TabIndex = 69;
						this->groupBox20->TabStop = false;
						this->groupBox20->Text = L"DE Algorithm";
						// 
						// groupBox21
						// 
						this->groupBox21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->groupBox21->Controls->Add(this->numericUpDown22);
						this->groupBox21->Controls->Add(this->numericUpDown23);
						this->groupBox21->Controls->Add(this->label47);
						this->groupBox21->Controls->Add(this->label48);
						this->groupBox21->Controls->Add(this->comboBox5);
						this->groupBox21->Location = System::Drawing::Point(4, 201);
						this->groupBox21->Name = L"groupBox21";
						this->groupBox21->Size = System::Drawing::Size(453, 72);
						this->groupBox21->TabIndex = 20;
						this->groupBox21->TabStop = false;
						this->groupBox21->Text = L"Termination Condition";
						// 
						// numericUpDown22
						// 
						this->numericUpDown22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->numericUpDown22->Location = System::Drawing::Point(328, 46);
						this->numericUpDown22->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown22->Name = L"numericUpDown22";
						this->numericUpDown22->Size = System::Drawing::Size(95, 20);
						this->numericUpDown22->TabIndex = 5;
						this->numericUpDown22->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// numericUpDown23
						// 
						this->numericUpDown23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->numericUpDown23->Location = System::Drawing::Point(154, 46);
						this->numericUpDown23->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
						this->numericUpDown23->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown23->Name = L"numericUpDown23";
						this->numericUpDown23->Size = System::Drawing::Size(68, 20);
						this->numericUpDown23->TabIndex = 6;
						this->numericUpDown23->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
						// 
						// label47
						// 
						this->label47->AutoSize = true;
						this->label47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label47->ForeColor = System::Drawing::SystemColors::WindowText;
						this->label47->Location = System::Drawing::Point(277, 48);
						this->label47->Name = L"label47";
						this->label47->Size = System::Drawing::Size(47, 13);
						this->label47->TabIndex = 3;
						this->label47->Text = L"F(x) limit:";
						// 
						// label48
						// 
						this->label48->AutoSize = true;
						this->label48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label48->ForeColor = System::Drawing::SystemColors::WindowText;
						this->label48->Location = System::Drawing::Point(31, 48);
						this->label48->Name = L"label48";
						this->label48->Size = System::Drawing::Size(117, 13);
						this->label48->TabIndex = 4;
						this->label48->Text = L"Number of generations:";
						// 
						// comboBox5
						// 
						this->comboBox5->FormattingEnabled = true;
						this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"[1] Maximum number of generations", L"[2] If best individuum has fitness less then (X) -> STOP", 
										L"[3] If best individuum has fitness greater then (X) -> STOP", L"[4] Stop if Fit(BestInd) <= Limit OR Generation >= MaxGeneration", 
										L"[5] Stop if Fit(BestInd) >= Limit OR Generation >= MaxGeneration"});
						this->comboBox5->Location = System::Drawing::Point(6, 19);
						this->comboBox5->Name = L"comboBox5";
						this->comboBox5->Size = System::Drawing::Size(441, 21);
						this->comboBox5->TabIndex = 0;
						// 
						// groupBox22
						// 
						this->groupBox22->Controls->Add(this->maskedTextBox9);
						this->groupBox22->Controls->Add(this->label49);
						this->groupBox22->Controls->Add(this->label50);
						this->groupBox22->Controls->Add(this->maskedTextBox10);
						this->groupBox22->Location = System::Drawing::Point(4, 150);
						this->groupBox22->Name = L"groupBox22";
						this->groupBox22->Size = System::Drawing::Size(454, 45);
						this->groupBox22->TabIndex = 19;
						this->groupBox22->TabStop = false;
						this->groupBox22->Text = L"DE algorithm Parameters";
						// 
						// maskedTextBox9
						// 
						this->maskedTextBox9->Location = System::Drawing::Point(320, 20);
						this->maskedTextBox9->Mask = L"CCCCCCCCC";
						this->maskedTextBox9->Name = L"maskedTextBox9";
						this->maskedTextBox9->Size = System::Drawing::Size(66, 20);
						this->maskedTextBox9->TabIndex = 23;
						this->maskedTextBox9->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MapBuilding_LM104::maskedTextBox9_Validating);
						this->maskedTextBox9->Leave += gcnew System::EventHandler(this, &MapBuilding_LM104::maskedTextBox9_Leave);
						// 
						// label49
						// 
						this->label49->AutoSize = true;
						this->label49->Location = System::Drawing::Point(53, 23);
						this->label49->Name = L"label49";
						this->label49->Size = System::Drawing::Size(48, 13);
						this->label49->TabIndex = 20;
						this->label49->Text = L"param F:";
						// 
						// label50
						// 
						this->label50->AutoSize = true;
						this->label50->Location = System::Drawing::Point(208, 23);
						this->label50->Name = L"label50";
						this->label50->Size = System::Drawing::Size(108, 13);
						this->label50->TabIndex = 21;
						this->label50->Text = L"Crossover Probability:";
						// 
						// maskedTextBox10
						// 
						this->maskedTextBox10->Location = System::Drawing::Point(109, 20);
						this->maskedTextBox10->Mask = L"CCCCCCCCC";
						this->maskedTextBox10->Name = L"maskedTextBox10";
						this->maskedTextBox10->Size = System::Drawing::Size(66, 20);
						this->maskedTextBox10->TabIndex = 22;
						this->maskedTextBox10->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MapBuilding_LM104::maskedTextBox10_Validating);
						this->maskedTextBox10->Leave += gcnew System::EventHandler(this, &MapBuilding_LM104::maskedTextBox10_Leave);
						// 
						// groupBox23
						// 
						this->groupBox23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
										static_cast<System::Int32>(static_cast<System::Byte>(224)));
						this->groupBox23->Controls->Add(this->numericUpDown24);
						this->groupBox23->Controls->Add(this->label51);
						this->groupBox23->Controls->Add(this->numericUpDown25);
						this->groupBox23->Controls->Add(this->numericUpDown26);
						this->groupBox23->Controls->Add(this->label53);
						this->groupBox23->Controls->Add(this->label54);
						this->groupBox23->Controls->Add(this->label55);
						this->groupBox23->Controls->Add(this->label60);
						this->groupBox23->Controls->Add(this->label61);
						this->groupBox23->Controls->Add(this->numericUpDown27);
						this->groupBox23->Controls->Add(this->label62);
						this->groupBox23->Controls->Add(this->label63);
						this->groupBox23->Location = System::Drawing::Point(86, 77);
						this->groupBox23->Name = L"groupBox23";
						this->groupBox23->Size = System::Drawing::Size(295, 67);
						this->groupBox23->TabIndex = 18;
						this->groupBox23->TabStop = false;
						this->groupBox23->Text = L"Searching Area";
						// 
						// numericUpDown24
						// 
						this->numericUpDown24->Location = System::Drawing::Point(59, 17);
						this->numericUpDown24->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown24->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown24->Name = L"numericUpDown24";
						this->numericUpDown24->Size = System::Drawing::Size(83, 20);
						this->numericUpDown24->TabIndex = 2;
						this->numericUpDown24->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label51
						// 
						this->label51->AutoSize = true;
						this->label51->Location = System::Drawing::Point(23, 21);
						this->label51->Name = L"label51";
						this->label51->Size = System::Drawing::Size(30, 13);
						this->label51->TabIndex = 17;
						this->label51->Text = L"minX";
						// 
						// numericUpDown25
						// 
						this->numericUpDown25->Location = System::Drawing::Point(59, 38);
						this->numericUpDown25->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown25->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown25->Name = L"numericUpDown25";
						this->numericUpDown25->Size = System::Drawing::Size(83, 20);
						this->numericUpDown25->TabIndex = 3;
						this->numericUpDown25->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// numericUpDown26
						// 
						this->numericUpDown26->Location = System::Drawing::Point(201, 40);
						this->numericUpDown26->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown26->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown26->Name = L"numericUpDown26";
						this->numericUpDown26->Size = System::Drawing::Size(83, 20);
						this->numericUpDown26->TabIndex = 7;
						this->numericUpDown26->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label53
						// 
						this->label53->AutoSize = true;
						this->label53->Location = System::Drawing::Point(24, 40);
						this->label53->Name = L"label53";
						this->label53->Size = System::Drawing::Size(30, 13);
						this->label53->TabIndex = 17;
						this->label53->Text = L"minY";
						// 
						// label54
						// 
						this->label54->AutoSize = true;
						this->label54->Font = (gcnew System::Drawing::Font(L"Symbol", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(2)));
						this->label54->Location = System::Drawing::Point(8, 19);
						this->label54->Name = L"label54";
						this->label54->Size = System::Drawing::Size(15, 13);
						this->label54->TabIndex = 16;
						this->label54->Text = L"D";
						// 
						// label55
						// 
						this->label55->AutoSize = true;
						this->label55->Font = (gcnew System::Drawing::Font(L"Symbol", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(2)));
						this->label55->Location = System::Drawing::Point(151, 21);
						this->label55->Name = L"label55";
						this->label55->Size = System::Drawing::Size(15, 13);
						this->label55->TabIndex = 16;
						this->label55->Text = L"D";
						// 
						// label60
						// 
						this->label60->AutoSize = true;
						this->label60->Font = (gcnew System::Drawing::Font(L"Symbol", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(2)));
						this->label60->Location = System::Drawing::Point(8, 40);
						this->label60->Name = L"label60";
						this->label60->Size = System::Drawing::Size(15, 13);
						this->label60->TabIndex = 16;
						this->label60->Text = L"D";
						// 
						// label61
						// 
						this->label61->AutoSize = true;
						this->label61->Location = System::Drawing::Point(167, 42);
						this->label61->Name = L"label61";
						this->label61->Size = System::Drawing::Size(33, 13);
						this->label61->TabIndex = 17;
						this->label61->Text = L"maxY";
						// 
						// numericUpDown27
						// 
						this->numericUpDown27->Location = System::Drawing::Point(201, 19);
						this->numericUpDown27->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown27->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown27->Name = L"numericUpDown27";
						this->numericUpDown27->Size = System::Drawing::Size(83, 20);
						this->numericUpDown27->TabIndex = 6;
						this->numericUpDown27->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label62
						// 
						this->label62->AutoSize = true;
						this->label62->Location = System::Drawing::Point(166, 21);
						this->label62->Name = L"label62";
						this->label62->Size = System::Drawing::Size(33, 13);
						this->label62->TabIndex = 17;
						this->label62->Text = L"maxX";
						// 
						// label63
						// 
						this->label63->AutoSize = true;
						this->label63->Font = (gcnew System::Drawing::Font(L"Symbol", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(2)));
						this->label63->Location = System::Drawing::Point(151, 42);
						this->label63->Name = L"label63";
						this->label63->Size = System::Drawing::Size(15, 13);
						this->label63->TabIndex = 16;
						this->label63->Text = L"D";
						// 
						// comboBox6
						// 
						this->comboBox6->DropDownWidth = 253;
						this->comboBox6->FormattingEnabled = true;
						this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"[0] .NET C++ Random number generator"});
						this->comboBox6->Location = System::Drawing::Point(240, 45);
						this->comboBox6->Name = L"comboBox6";
						this->comboBox6->Size = System::Drawing::Size(217, 21);
						this->comboBox6->TabIndex = 0;
						// 
						// label64
						// 
						this->label64->AutoSize = true;
						this->label64->Location = System::Drawing::Point(6, 22);
						this->label64->Name = L"label64";
						this->label64->Size = System::Drawing::Size(105, 13);
						this->label64->TabIndex = 17;
						this->label64->Text = L"DE type: rand/1/exp";
						// 
						// numericUpDown28
						// 
						this->numericUpDown28->Location = System::Drawing::Point(86, 46);
						this->numericUpDown28->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown28->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown28->Name = L"numericUpDown28";
						this->numericUpDown28->Size = System::Drawing::Size(57, 20);
						this->numericUpDown28->TabIndex = 6;
						this->numericUpDown28->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label65
						// 
						this->label65->AutoSize = true;
						this->label65->Location = System::Drawing::Point(149, 48);
						this->label65->Name = L"label65";
						this->label65->Size = System::Drawing::Size(85, 13);
						this->label65->TabIndex = 17;
						this->label65->Text = L"Way of creation:";
						// 
						// label66
						// 
						this->label66->AutoSize = true;
						this->label66->Location = System::Drawing::Point(6, 48);
						this->label66->Name = L"label66";
						this->label66->Size = System::Drawing::Size(77, 13);
						this->label66->TabIndex = 17;
						this->label66->Text = L"Number of Ind:";
						// 
						// groupBox24
						// 
						this->groupBox24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->groupBox24->Controls->Add(this->label67);
						this->groupBox24->Controls->Add(this->label68);
						this->groupBox24->Controls->Add(this->label69);
						this->groupBox24->Controls->Add(this->numericUpDown29);
						this->groupBox24->Controls->Add(this->label70);
						this->groupBox24->Controls->Add(this->label71);
						this->groupBox24->Controls->Add(this->label72);
						this->groupBox24->Controls->Add(this->label73);
						this->groupBox24->Controls->Add(this->numericUpDown30);
						this->groupBox24->Controls->Add(this->numericUpDown31);
						this->groupBox24->Controls->Add(this->label74);
						this->groupBox24->Controls->Add(this->numericUpDown32);
						this->groupBox24->Controls->Add(this->label75);
						this->groupBox24->Controls->Add(this->numericUpDown33);
						this->groupBox24->Controls->Add(this->label76);
						this->groupBox24->Controls->Add(this->numericUpDown34);
						this->groupBox24->Location = System::Drawing::Point(3, 46);
						this->groupBox24->Name = L"groupBox24";
						this->groupBox24->Size = System::Drawing::Size(464, 69);
						this->groupBox24->TabIndex = 68;
						this->groupBox24->TabStop = false;
						this->groupBox24->Text = L"Brute Force algorithm";
						// 
						// label67
						// 
						this->label67->AutoSize = true;
						this->label67->Location = System::Drawing::Point(161, 23);
						this->label67->Name = L"label67";
						this->label67->Size = System::Drawing::Size(34, 13);
						this->label67->TabIndex = 17;
						this->label67->Text = L"stepX";
						// 
						// label68
						// 
						this->label68->AutoSize = true;
						this->label68->Location = System::Drawing::Point(22, 23);
						this->label68->Name = L"label68";
						this->label68->Size = System::Drawing::Size(30, 13);
						this->label68->TabIndex = 17;
						this->label68->Text = L"minX";
						// 
						// label69
						// 
						this->label69->AutoSize = true;
						this->label69->Location = System::Drawing::Point(22, 44);
						this->label69->Name = L"label69";
						this->label69->Size = System::Drawing::Size(30, 13);
						this->label69->TabIndex = 17;
						this->label69->Text = L"minY";
						// 
						// numericUpDown29
						// 
						this->numericUpDown29->Location = System::Drawing::Point(356, 42);
						this->numericUpDown29->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown29->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown29->Name = L"numericUpDown29";
						this->numericUpDown29->Size = System::Drawing::Size(83, 20);
						this->numericUpDown29->TabIndex = 7;
						this->numericUpDown29->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label70
						// 
						this->label70->AutoSize = true;
						this->label70->Location = System::Drawing::Point(162, 42);
						this->label70->Name = L"label70";
						this->label70->Size = System::Drawing::Size(34, 13);
						this->label70->TabIndex = 17;
						this->label70->Text = L"stepY";
						// 
						// label71
						// 
						this->label71->AutoSize = true;
						this->label71->Font = (gcnew System::Drawing::Font(L"Symbol", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(2)));
						this->label71->Location = System::Drawing::Point(306, 23);
						this->label71->Name = L"label71";
						this->label71->Size = System::Drawing::Size(15, 13);
						this->label71->TabIndex = 16;
						this->label71->Text = L"D";
						// 
						// label72
						// 
						this->label72->AutoSize = true;
						this->label72->Location = System::Drawing::Point(322, 44);
						this->label72->Name = L"label72";
						this->label72->Size = System::Drawing::Size(33, 13);
						this->label72->TabIndex = 17;
						this->label72->Text = L"maxY";
						// 
						// label73
						// 
						this->label73->AutoSize = true;
						this->label73->Font = (gcnew System::Drawing::Font(L"Symbol", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(2)));
						this->label73->Location = System::Drawing::Point(6, 44);
						this->label73->Name = L"label73";
						this->label73->Size = System::Drawing::Size(15, 13);
						this->label73->TabIndex = 16;
						this->label73->Text = L"D";
						// 
						// numericUpDown30
						// 
						this->numericUpDown30->Location = System::Drawing::Point(202, 21);
						this->numericUpDown30->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown30->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown30->Name = L"numericUpDown30";
						this->numericUpDown30->Size = System::Drawing::Size(83, 20);
						this->numericUpDown30->TabIndex = 4;
						this->numericUpDown30->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// numericUpDown31
						// 
						this->numericUpDown31->Location = System::Drawing::Point(356, 21);
						this->numericUpDown31->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown31->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown31->Name = L"numericUpDown31";
						this->numericUpDown31->Size = System::Drawing::Size(83, 20);
						this->numericUpDown31->TabIndex = 6;
						this->numericUpDown31->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label74
						// 
						this->label74->AutoSize = true;
						this->label74->Font = (gcnew System::Drawing::Font(L"Symbol", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(2)));
						this->label74->Location = System::Drawing::Point(306, 44);
						this->label74->Name = L"label74";
						this->label74->Size = System::Drawing::Size(15, 13);
						this->label74->TabIndex = 16;
						this->label74->Text = L"D";
						// 
						// numericUpDown32
						// 
						this->numericUpDown32->Location = System::Drawing::Point(202, 42);
						this->numericUpDown32->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown32->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown32->Name = L"numericUpDown32";
						this->numericUpDown32->Size = System::Drawing::Size(82, 20);
						this->numericUpDown32->TabIndex = 5;
						this->numericUpDown32->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label75
						// 
						this->label75->AutoSize = true;
						this->label75->Location = System::Drawing::Point(322, 23);
						this->label75->Name = L"label75";
						this->label75->Size = System::Drawing::Size(33, 13);
						this->label75->TabIndex = 17;
						this->label75->Text = L"maxX";
						// 
						// numericUpDown33
						// 
						this->numericUpDown33->Location = System::Drawing::Point(58, 21);
						this->numericUpDown33->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown33->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown33->Name = L"numericUpDown33";
						this->numericUpDown33->Size = System::Drawing::Size(83, 20);
						this->numericUpDown33->TabIndex = 2;
						this->numericUpDown33->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label76
						// 
						this->label76->AutoSize = true;
						this->label76->Font = (gcnew System::Drawing::Font(L"Symbol", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(2)));
						this->label76->Location = System::Drawing::Point(7, 23);
						this->label76->Name = L"label76";
						this->label76->Size = System::Drawing::Size(15, 13);
						this->label76->TabIndex = 16;
						this->label76->Text = L"D";
						// 
						// numericUpDown34
						// 
						this->numericUpDown34->Location = System::Drawing::Point(58, 42);
						this->numericUpDown34->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown34->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown34->Name = L"numericUpDown34";
						this->numericUpDown34->Size = System::Drawing::Size(83, 20);
						this->numericUpDown34->TabIndex = 3;
						this->numericUpDown34->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// comboBox8
						// 
						this->comboBox8->FormattingEnabled = true;
						this->comboBox8->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"[0] DS/MAE-1 + BruteForce", L"[1] DS/MAE-2 + BruteForce", 
										L"[2] DS/MAE-1 + EA ", L"[3] DS/MAE-2 + EA "});
						this->comboBox8->Location = System::Drawing::Point(6, 19);
						this->comboBox8->Name = L"comboBox8";
						this->comboBox8->Size = System::Drawing::Size(458, 21);
						this->comboBox8->TabIndex = 0;
						// 
						// groupBox18
						// 
						this->groupBox18->Controls->Add(this->numericUpDown19);
						this->groupBox18->Controls->Add(this->label43);
						this->groupBox18->Controls->Add(this->label44);
						this->groupBox18->Controls->Add(this->numericUpDown20);
						this->groupBox18->Controls->Add(this->label45);
						this->groupBox18->Controls->Add(this->numericUpDown21);
						this->groupBox18->Controls->Add(this->label46);
						this->groupBox18->Location = System::Drawing::Point(2, 77);
						this->groupBox18->Name = L"groupBox18";
						this->groupBox18->Size = System::Drawing::Size(471, 49);
						this->groupBox18->TabIndex = 3;
						this->groupBox18->TabStop = false;
						this->groupBox18->Text = L"Step Angle properties";
						// 
						// numericUpDown19
						// 
						this->numericUpDown19->Location = System::Drawing::Point(317, 18);
						this->numericUpDown19->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
						this->numericUpDown19->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown19->Name = L"numericUpDown19";
						this->numericUpDown19->Size = System::Drawing::Size(59, 20);
						this->numericUpDown19->TabIndex = 5;
						this->numericUpDown19->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {60, 0, 0, 0});
						// 
						// label43
						// 
						this->label43->AutoSize = true;
						this->label43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label43->Location = System::Drawing::Point(382, 21);
						this->label43->Name = L"label43";
						this->label43->Size = System::Drawing::Size(80, 12);
						this->label43->TabIndex = 9;
						this->label43->Text = L"LS resolution units";
						// 
						// label44
						// 
						this->label44->AutoSize = true;
						this->label44->Location = System::Drawing::Point(254, 21);
						this->label44->Name = L"label44";
						this->label44->Size = System::Drawing::Size(57, 13);
						this->label44->TabIndex = 8;
						this->label44->Text = L"Det.Angle:";
						// 
						// numericUpDown20
						// 
						this->numericUpDown20->Location = System::Drawing::Point(171, 19);
						this->numericUpDown20->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown20->Name = L"numericUpDown20";
						this->numericUpDown20->Size = System::Drawing::Size(59, 20);
						this->numericUpDown20->TabIndex = 3;
						this->numericUpDown20->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label45
						// 
						this->label45->AutoSize = true;
						this->label45->Location = System::Drawing::Point(120, 21);
						this->label45->Name = L"label45";
						this->label45->Size = System::Drawing::Size(46, 13);
						this->label45->TabIndex = 7;
						this->label45->Text = L"StepDe:";
						// 
						// numericUpDown21
						// 
						this->numericUpDown21->Location = System::Drawing::Point(54, 19);
						this->numericUpDown21->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown21->Name = L"numericUpDown21";
						this->numericUpDown21->Size = System::Drawing::Size(59, 20);
						this->numericUpDown21->TabIndex = 4;
						this->numericUpDown21->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label46
						// 
						this->label46->AutoSize = true;
						this->label46->Location = System::Drawing::Point(3, 21);
						this->label46->Name = L"label46";
						this->label46->Size = System::Drawing::Size(45, 13);
						this->label46->TabIndex = 6;
						this->label46->Text = L"StepDs:";
						// 
						// groupBox17
						// 
						this->groupBox17->Controls->Add(this->maskedTextBox8);
						this->groupBox17->Controls->Add(this->label42);
						this->groupBox17->Controls->Add(this->label41);
						this->groupBox17->Controls->Add(this->label40);
						this->groupBox17->Controls->Add(this->label39);
						this->groupBox17->Controls->Add(this->radioButton5);
						this->groupBox17->Controls->Add(this->radioButton4);
						this->groupBox17->Location = System::Drawing::Point(2, 6);
						this->groupBox17->Name = L"groupBox17";
						this->groupBox17->Size = System::Drawing::Size(471, 65);
						this->groupBox17->TabIndex = 2;
						this->groupBox17->TabStop = false;
						this->groupBox17->Text = L"EpsT ";
						// 
						// maskedTextBox8
						// 
						this->maskedTextBox8->Location = System::Drawing::Point(265, 31);
						this->maskedTextBox8->Mask = L"CCCCCCCCC";
						this->maskedTextBox8->Name = L"maskedTextBox8";
						this->maskedTextBox8->Size = System::Drawing::Size(63, 20);
						this->maskedTextBox8->TabIndex = 3;
						// 
						// label42
						// 
						this->label42->AutoSize = true;
						this->label42->Location = System::Drawing::Point(215, 34);
						this->label42->Name = L"label42";
						this->label42->Size = System::Drawing::Size(44, 13);
						this->label42->TabIndex = 2;
						this->label42->Text = L"EpsT = ";
						// 
						// label41
						// 
						this->label41->AutoSize = true;
						this->label41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label41->Location = System::Drawing::Point(192, 32);
						this->label41->Name = L"label41";
						this->label41->Size = System::Drawing::Size(19, 16);
						this->label41->TabIndex = 1;
						this->label41->Text = L"->";
						// 
						// label40
						// 
						this->label40->AutoSize = true;
						this->label40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label40->Location = System::Drawing::Point(183, 42);
						this->label40->Name = L"label40";
						this->label40->Size = System::Drawing::Size(12, 13);
						this->label40->TabIndex = 1;
						this->label40->Text = L"/";
						// 
						// label39
						// 
						this->label39->AutoSize = true;
						this->label39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label39->Location = System::Drawing::Point(183, 23);
						this->label39->Name = L"label39";
						this->label39->Size = System::Drawing::Size(12, 13);
						this->label39->TabIndex = 1;
						this->label39->Text = L"\\";
						// 
						// radioButton5
						// 
						this->radioButton5->AutoSize = true;
						this->radioButton5->Location = System::Drawing::Point(4, 38);
						this->radioButton5->Name = L"radioButton5";
						this->radioButton5->Size = System::Drawing::Size(183, 17);
						this->radioButton5->TabIndex = 0;
						this->radioButton5->TabStop = true;
						this->radioButton5->Text = L"Use dynamic computing: Ds + De";
						this->radioButton5->UseVisualStyleBackColor = true;
						// 
						// radioButton4
						// 
						this->radioButton4->AutoSize = true;
						this->radioButton4->Location = System::Drawing::Point(4, 19);
						this->radioButton4->Name = L"radioButton4";
						this->radioButton4->Size = System::Drawing::Size(157, 17);
						this->radioButton4->TabIndex = 0;
						this->radioButton4->TabStop = true;
						this->radioButton4->Text = L"Use dynamic computing: Ds";
						this->radioButton4->UseVisualStyleBackColor = true;
						// 
						// tabPage25
						// 
						this->tabPage25->Controls->Add(this->panel12);
						this->tabPage25->Location = System::Drawing::Point(4, 22);
						this->tabPage25->Name = L"tabPage25";
						this->tabPage25->Padding = System::Windows::Forms::Padding(3);
						this->tabPage25->Size = System::Drawing::Size(494, 320);
						this->tabPage25->TabIndex = 7;
						this->tabPage25->Text = L"Split/Merge";
						this->tabPage25->UseVisualStyleBackColor = true;
						// 
						// panel12
						// 
						this->panel12->AutoScroll = true;
						this->panel12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->panel12->Controls->Add(this->groupBox74);
						this->panel12->Controls->Add(this->groupBox78);
						this->panel12->Controls->Add(this->groupBox76);
						this->panel12->Controls->Add(this->groupBox72);
						this->panel12->Controls->Add(this->groupBox73);
						this->panel12->Controls->Add(this->groupBox71);
						this->panel12->Controls->Add(this->groupBox68);
						this->panel12->Controls->Add(this->groupBox67);
						this->panel12->Location = System::Drawing::Point(0, 0);
						this->panel12->Name = L"panel12";
						this->panel12->Size = System::Drawing::Size(494, 320);
						this->panel12->TabIndex = 0;
						// 
						// groupBox74
						// 
						this->groupBox74->Controls->Add(this->label239);
						this->groupBox74->Controls->Add(this->maskedTextBox47);
						this->groupBox74->Controls->Add(this->label240);
						this->groupBox74->Controls->Add(this->numericUpDown82);
						this->groupBox74->Controls->Add(this->numericUpDown83);
						this->groupBox74->Controls->Add(this->label241);
						this->groupBox74->Controls->Add(this->label242);
						this->groupBox74->Controls->Add(this->numericUpDown84);
						this->groupBox74->Controls->Add(this->label243);
						this->groupBox74->Controls->Add(this->numericUpDown85);
						this->groupBox74->Controls->Add(this->label244);
						this->groupBox74->Location = System::Drawing::Point(2, 621);
						this->groupBox74->Name = L"groupBox74";
						this->groupBox74->Size = System::Drawing::Size(471, 150);
						this->groupBox74->TabIndex = 5;
						this->groupBox74->TabStop = false;
						this->groupBox74->Text = L"Final Map Refinement";
						// 
						// label239
						// 
						this->label239->AutoSize = true;
						this->label239->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label239->Location = System::Drawing::Point(366, 17);
						this->label239->Name = L"label239";
						this->label239->Size = System::Drawing::Size(26, 12);
						this->label239->TabIndex = 14;
						this->label239->Text = L"RAD";
						// 
						// maskedTextBox47
						// 
						this->maskedTextBox47->Location = System::Drawing::Point(280, 13);
						this->maskedTextBox47->Mask = L"CCCCCCCCC";
						this->maskedTextBox47->Name = L"maskedTextBox47";
						this->maskedTextBox47->Size = System::Drawing::Size(80, 20);
						this->maskedTextBox47->TabIndex = 13;
						this->maskedTextBox47->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MapBuilding_LM104::maskedTextBox47_Validating);
						this->maskedTextBox47->Leave += gcnew System::EventHandler(this, &MapBuilding_LM104::maskedTextBox47_Leave);
						// 
						// label240
						// 
						this->label240->AutoSize = true;
						this->label240->Location = System::Drawing::Point(6, 16);
						this->label240->Name = L"label240";
						this->label240->Size = System::Drawing::Size(191, 13);
						this->label240->TabIndex = 8;
						this->label240->Text = L"Maximum angle of two lines at merging:";
						// 
						// numericUpDown82
						// 
						this->numericUpDown82->Location = System::Drawing::Point(280, 122);
						this->numericUpDown82->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown82->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown82->Name = L"numericUpDown82";
						this->numericUpDown82->Size = System::Drawing::Size(55, 20);
						this->numericUpDown82->TabIndex = 10;
						this->numericUpDown82->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
						// 
						// numericUpDown83
						// 
						this->numericUpDown83->Location = System::Drawing::Point(280, 39);
						this->numericUpDown83->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown83->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown83->Name = L"numericUpDown83";
						this->numericUpDown83->Size = System::Drawing::Size(55, 20);
						this->numericUpDown83->TabIndex = 11;
						this->numericUpDown83->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
						// 
						// label241
						// 
						this->label241->AutoSize = true;
						this->label241->Location = System::Drawing::Point(6, 124);
						this->label241->Name = L"label241";
						this->label241->Size = System::Drawing::Size(114, 13);
						this->label241->TabIndex = 7;
						this->label241->Text = L"Minimum length of line:";
						// 
						// label242
						// 
						this->label242->AutoSize = true;
						this->label242->Location = System::Drawing::Point(6, 41);
						this->label242->Name = L"label242";
						this->label242->Size = System::Drawing::Size(271, 13);
						this->label242->TabIndex = 5;
						this->label242->Text = L"Maximum perpendicular distance from point P to line AB:";
						// 
						// numericUpDown84
						// 
						this->numericUpDown84->Location = System::Drawing::Point(280, 96);
						this->numericUpDown84->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown84->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown84->Name = L"numericUpDown84";
						this->numericUpDown84->Size = System::Drawing::Size(55, 20);
						this->numericUpDown84->TabIndex = 9;
						this->numericUpDown84->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
						// 
						// label243
						// 
						this->label243->AutoSize = true;
						this->label243->Location = System::Drawing::Point(6, 98);
						this->label243->Name = L"label243";
						this->label243->Size = System::Drawing::Size(131, 13);
						this->label243->TabIndex = 6;
						this->label243->Text = L"Minimum overhang length:";
						// 
						// numericUpDown85
						// 
						this->numericUpDown85->Location = System::Drawing::Point(280, 65);
						this->numericUpDown85->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown85->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown85->Name = L"numericUpDown85";
						this->numericUpDown85->Size = System::Drawing::Size(55, 20);
						this->numericUpDown85->TabIndex = 12;
						this->numericUpDown85->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
						// 
						// label244
						// 
						this->label244->AutoSize = true;
						this->label244->Location = System::Drawing::Point(6, 67);
						this->label244->Name = L"label244";
						this->label244->Size = System::Drawing::Size(241, 13);
						this->label244->TabIndex = 4;
						this->label244->Text = L"Minimum distance between two points at merging:";
						// 
						// groupBox78
						// 
						this->groupBox78->Location = System::Drawing::Point(2, 777);
						this->groupBox78->Name = L"groupBox78";
						this->groupBox78->Size = System::Drawing::Size(471, 24);
						this->groupBox78->TabIndex = 5;
						this->groupBox78->TabStop = false;
						this->groupBox78->Text = L"Misc";
						// 
						// groupBox76
						// 
						this->groupBox76->Controls->Add(this->comboBox23);
						this->groupBox76->Controls->Add(this->label254);
						this->groupBox76->Controls->Add(this->label252);
						this->groupBox76->Controls->Add(this->numericUpDown86);
						this->groupBox76->Controls->Add(this->label253);
						this->groupBox76->Controls->Add(this->numericUpDown87);
						this->groupBox76->Location = System::Drawing::Point(2, 508);
						this->groupBox76->Name = L"groupBox76";
						this->groupBox76->Size = System::Drawing::Size(472, 105);
						this->groupBox76->TabIndex = 1;
						this->groupBox76->TabStop = false;
						this->groupBox76->Text = L"Temporary Map - Linear Regression and Recursive Line Splitting";
						// 
						// comboBox23
						// 
						this->comboBox23->FormattingEnabled = true;
						this->comboBox23->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"[0] Use Global Map", L"[1] Use Last De vector"});
						this->comboBox23->Location = System::Drawing::Point(80, 19);
						this->comboBox23->Name = L"comboBox23";
						this->comboBox23->Size = System::Drawing::Size(256, 21);
						this->comboBox23->TabIndex = 3;
						// 
						// label254
						// 
						this->label254->AutoSize = true;
						this->label254->Location = System::Drawing::Point(7, 22);
						this->label254->Name = L"label254";
						this->label254->Size = System::Drawing::Size(53, 13);
						this->label254->TabIndex = 2;
						this->label254->Text = L"Algorithm:";
						// 
						// label252
						// 
						this->label252->AutoSize = true;
						this->label252->Location = System::Drawing::Point(7, 53);
						this->label252->Name = L"label252";
						this->label252->Size = System::Drawing::Size(158, 13);
						this->label252->TabIndex = 0;
						this->label252->Text = L"Minimum point-to-point distance:";
						// 
						// numericUpDown86
						// 
						this->numericUpDown86->Location = System::Drawing::Point(281, 51);
						this->numericUpDown86->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown86->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown86->Name = L"numericUpDown86";
						this->numericUpDown86->Size = System::Drawing::Size(55, 20);
						this->numericUpDown86->TabIndex = 1;
						this->numericUpDown86->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
						// 
						// label253
						// 
						this->label253->AutoSize = true;
						this->label253->Location = System::Drawing::Point(7, 79);
						this->label253->Name = L"label253";
						this->label253->Size = System::Drawing::Size(151, 13);
						this->label253->TabIndex = 0;
						this->label253->Text = L"Minimum point-to-line distance:";
						// 
						// numericUpDown87
						// 
						this->numericUpDown87->Location = System::Drawing::Point(281, 77);
						this->numericUpDown87->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown87->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown87->Name = L"numericUpDown87";
						this->numericUpDown87->Size = System::Drawing::Size(55, 20);
						this->numericUpDown87->TabIndex = 1;
						this->numericUpDown87->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
						// 
						// groupBox72
						// 
						this->groupBox72->Controls->Add(this->numericUpDown81);
						this->groupBox72->Controls->Add(this->label238);
						this->groupBox72->Location = System::Drawing::Point(2, 373);
						this->groupBox72->Name = L"groupBox72";
						this->groupBox72->Size = System::Drawing::Size(471, 45);
						this->groupBox72->TabIndex = 3;
						this->groupBox72->TabStop = false;
						this->groupBox72->Text = L"Removing small lines ( Global Map )";
						// 
						// numericUpDown81
						// 
						this->numericUpDown81->Location = System::Drawing::Point(280, 19);
						this->numericUpDown81->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown81->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown81->Name = L"numericUpDown81";
						this->numericUpDown81->Size = System::Drawing::Size(55, 20);
						this->numericUpDown81->TabIndex = 1;
						this->numericUpDown81->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
						// 
						// label238
						// 
						this->label238->AutoSize = true;
						this->label238->Location = System::Drawing::Point(6, 21);
						this->label238->Name = L"label238";
						this->label238->Size = System::Drawing::Size(114, 13);
						this->label238->TabIndex = 0;
						this->label238->Text = L"Minimum length of line:";
						// 
						// groupBox73
						// 
						this->groupBox73->Controls->Add(this->checkBox21);
						this->groupBox73->Controls->Add(this->checkBox20);
						this->groupBox73->Controls->Add(this->checkBox19);
						this->groupBox73->Location = System::Drawing::Point(2, 8);
						this->groupBox73->Name = L"groupBox73";
						this->groupBox73->Size = System::Drawing::Size(473, 72);
						this->groupBox73->TabIndex = 4;
						this->groupBox73->TabStop = false;
						this->groupBox73->Text = L"Use process";
						// 
						// checkBox21
						// 
						this->checkBox21->AutoSize = true;
						this->checkBox21->Location = System::Drawing::Point(153, 19);
						this->checkBox21->Name = L"checkBox21";
						this->checkBox21->Size = System::Drawing::Size(145, 17);
						this->checkBox21->TabIndex = 0;
						this->checkBox21->Text = L"Use Final map refinement";
						this->checkBox21->UseVisualStyleBackColor = true;
						// 
						// checkBox20
						// 
						this->checkBox20->AutoSize = true;
						this->checkBox20->Location = System::Drawing::Point(6, 42);
						this->checkBox20->Name = L"checkBox20";
						this->checkBox20->Size = System::Drawing::Size(138, 17);
						this->checkBox20->TabIndex = 0;
						this->checkBox20->Text = L"Use Small line removing";
						this->checkBox20->UseVisualStyleBackColor = true;
						// 
						// checkBox19
						// 
						this->checkBox19->AutoSize = true;
						this->checkBox19->Location = System::Drawing::Point(6, 19);
						this->checkBox19->Name = L"checkBox19";
						this->checkBox19->Size = System::Drawing::Size(86, 17);
						this->checkBox19->TabIndex = 0;
						this->checkBox19->Text = L"Use Merging";
						this->checkBox19->UseVisualStyleBackColor = true;
						// 
						// groupBox71
						// 
						this->groupBox71->Controls->Add(this->label200);
						this->groupBox71->Controls->Add(this->maskedTextBox46);
						this->groupBox71->Controls->Add(this->label226);
						this->groupBox71->Controls->Add(this->label221);
						this->groupBox71->Controls->Add(this->numericUpDown79);
						this->groupBox71->Controls->Add(this->maskedTextBox44);
						this->groupBox71->Controls->Add(this->label219);
						this->groupBox71->Controls->Add(this->numericUpDown80);
						this->groupBox71->Controls->Add(this->label237);
						this->groupBox71->Location = System::Drawing::Point(2, 86);
						this->groupBox71->Name = L"groupBox71";
						this->groupBox71->Size = System::Drawing::Size(472, 120);
						this->groupBox71->TabIndex = 2;
						this->groupBox71->TabStop = false;
						this->groupBox71->Text = L"Line inserting From Local map to Global map";
						// 
						// label200
						// 
						this->label200->AutoSize = true;
						this->label200->Location = System::Drawing::Point(6, 16);
						this->label200->Name = L"label200";
						this->label200->Size = System::Drawing::Size(271, 13);
						this->label200->TabIndex = 0;
						this->label200->Text = L"Maximum perpendicular distance from point P to line AB:";
						// 
						// maskedTextBox46
						// 
						this->maskedTextBox46->Location = System::Drawing::Point(280, 66);
						this->maskedTextBox46->Mask = L"CCCCCCCCC";
						this->maskedTextBox46->Name = L"maskedTextBox46";
						this->maskedTextBox46->Size = System::Drawing::Size(80, 20);
						this->maskedTextBox46->TabIndex = 2;
						this->maskedTextBox46->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MapBuilding_LM104::maskedTextBox46_Validating);
						this->maskedTextBox46->Leave += gcnew System::EventHandler(this, &MapBuilding_LM104::maskedTextBox46_Leave);
						// 
						// label226
						// 
						this->label226->AutoSize = true;
						this->label226->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label226->Location = System::Drawing::Point(366, 43);
						this->label226->Name = L"label226";
						this->label226->Size = System::Drawing::Size(26, 12);
						this->label226->TabIndex = 3;
						this->label226->Text = L"RAD";
						// 
						// label221
						// 
						this->label221->AutoSize = true;
						this->label221->Location = System::Drawing::Point(6, 69);
						this->label221->Name = L"label221";
						this->label221->Size = System::Drawing::Size(143, 13);
						this->label221->TabIndex = 0;
						this->label221->Text = L"Length decrement at spliting:";
						// 
						// numericUpDown79
						// 
						this->numericUpDown79->Location = System::Drawing::Point(280, 14);
						this->numericUpDown79->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown79->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown79->Name = L"numericUpDown79";
						this->numericUpDown79->Size = System::Drawing::Size(55, 20);
						this->numericUpDown79->TabIndex = 1;
						this->numericUpDown79->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
						// 
						// maskedTextBox44
						// 
						this->maskedTextBox44->Location = System::Drawing::Point(280, 40);
						this->maskedTextBox44->Mask = L"CCCCCCCCC";
						this->maskedTextBox44->Name = L"maskedTextBox44";
						this->maskedTextBox44->Size = System::Drawing::Size(80, 20);
						this->maskedTextBox44->TabIndex = 2;
						this->maskedTextBox44->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MapBuilding_LM104::maskedTextBox44_Validating);
						this->maskedTextBox44->Leave += gcnew System::EventHandler(this, &MapBuilding_LM104::maskedTextBox44_Leave);
						// 
						// label219
						// 
						this->label219->AutoSize = true;
						this->label219->Location = System::Drawing::Point(6, 43);
						this->label219->Name = L"label219";
						this->label219->Size = System::Drawing::Size(186, 13);
						this->label219->TabIndex = 0;
						this->label219->Text = L"Maximum angle of two lines at spliting:";
						// 
						// numericUpDown80
						// 
						this->numericUpDown80->Location = System::Drawing::Point(280, 92);
						this->numericUpDown80->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown80->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown80->Name = L"numericUpDown80";
						this->numericUpDown80->Size = System::Drawing::Size(55, 20);
						this->numericUpDown80->TabIndex = 1;
						this->numericUpDown80->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
						// 
						// label237
						// 
						this->label237->AutoSize = true;
						this->label237->Location = System::Drawing::Point(6, 94);
						this->label237->Name = L"label237";
						this->label237->Size = System::Drawing::Size(131, 13);
						this->label237->TabIndex = 0;
						this->label237->Text = L"Minimum overhang length:";
						// 
						// groupBox68
						// 
						this->groupBox68->Controls->Add(this->label224);
						this->groupBox68->Controls->Add(this->numericUpDown77);
						this->groupBox68->Controls->Add(this->label225);
						this->groupBox68->Controls->Add(this->numericUpDown78);
						this->groupBox68->Location = System::Drawing::Point(2, 424);
						this->groupBox68->Name = L"groupBox68";
						this->groupBox68->Size = System::Drawing::Size(472, 78);
						this->groupBox68->TabIndex = 1;
						this->groupBox68->TabStop = false;
						this->groupBox68->Text = L"Linear Regression and Recursive Line Splitting";
						// 
						// label224
						// 
						this->label224->AutoSize = true;
						this->label224->Location = System::Drawing::Point(6, 21);
						this->label224->Name = L"label224";
						this->label224->Size = System::Drawing::Size(158, 13);
						this->label224->TabIndex = 0;
						this->label224->Text = L"Minimum point-to-point distance:";
						// 
						// numericUpDown77
						// 
						this->numericUpDown77->Location = System::Drawing::Point(280, 19);
						this->numericUpDown77->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown77->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown77->Name = L"numericUpDown77";
						this->numericUpDown77->Size = System::Drawing::Size(55, 20);
						this->numericUpDown77->TabIndex = 1;
						this->numericUpDown77->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
						// 
						// label225
						// 
						this->label225->AutoSize = true;
						this->label225->Location = System::Drawing::Point(6, 47);
						this->label225->Name = L"label225";
						this->label225->Size = System::Drawing::Size(151, 13);
						this->label225->TabIndex = 0;
						this->label225->Text = L"Minimum point-to-line distance:";
						// 
						// numericUpDown78
						// 
						this->numericUpDown78->Location = System::Drawing::Point(280, 45);
						this->numericUpDown78->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown78->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown78->Name = L"numericUpDown78";
						this->numericUpDown78->Size = System::Drawing::Size(55, 20);
						this->numericUpDown78->TabIndex = 1;
						this->numericUpDown78->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
						// 
						// groupBox67
						// 
						this->groupBox67->Controls->Add(this->label227);
						this->groupBox67->Controls->Add(this->maskedTextBox45);
						this->groupBox67->Controls->Add(this->label220);
						this->groupBox67->Controls->Add(this->numericUpDown76);
						this->groupBox67->Controls->Add(this->numericUpDown75);
						this->groupBox67->Controls->Add(this->label222);
						this->groupBox67->Controls->Add(this->label213);
						this->groupBox67->Controls->Add(this->numericUpDown74);
						this->groupBox67->Controls->Add(this->label212);
						this->groupBox67->Controls->Add(this->numericUpDown73);
						this->groupBox67->Controls->Add(this->label206);
						this->groupBox67->Location = System::Drawing::Point(2, 212);
						this->groupBox67->Name = L"groupBox67";
						this->groupBox67->Size = System::Drawing::Size(472, 155);
						this->groupBox67->TabIndex = 0;
						this->groupBox67->TabStop = false;
						this->groupBox67->Text = L"Merging proces ( Global Map )";
						// 
						// label227
						// 
						this->label227->AutoSize = true;
						this->label227->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label227->Location = System::Drawing::Point(366, 23);
						this->label227->Name = L"label227";
						this->label227->Size = System::Drawing::Size(26, 12);
						this->label227->TabIndex = 3;
						this->label227->Text = L"RAD";
						// 
						// maskedTextBox45
						// 
						this->maskedTextBox45->Location = System::Drawing::Point(280, 19);
						this->maskedTextBox45->Mask = L"CCCCCCCCC";
						this->maskedTextBox45->Name = L"maskedTextBox45";
						this->maskedTextBox45->Size = System::Drawing::Size(80, 20);
						this->maskedTextBox45->TabIndex = 2;
						this->maskedTextBox45->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MapBuilding_LM104::maskedTextBox45_Validating);
						this->maskedTextBox45->Leave += gcnew System::EventHandler(this, &MapBuilding_LM104::maskedTextBox45_Leave);
						// 
						// label220
						// 
						this->label220->AutoSize = true;
						this->label220->Location = System::Drawing::Point(6, 22);
						this->label220->Name = L"label220";
						this->label220->Size = System::Drawing::Size(191, 13);
						this->label220->TabIndex = 0;
						this->label220->Text = L"Maximum angle of two lines at merging:";
						// 
						// numericUpDown76
						// 
						this->numericUpDown76->Location = System::Drawing::Point(280, 128);
						this->numericUpDown76->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown76->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown76->Name = L"numericUpDown76";
						this->numericUpDown76->Size = System::Drawing::Size(55, 20);
						this->numericUpDown76->TabIndex = 1;
						this->numericUpDown76->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
						// 
						// numericUpDown75
						// 
						this->numericUpDown75->Location = System::Drawing::Point(280, 45);
						this->numericUpDown75->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown75->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown75->Name = L"numericUpDown75";
						this->numericUpDown75->Size = System::Drawing::Size(55, 20);
						this->numericUpDown75->TabIndex = 1;
						this->numericUpDown75->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
						// 
						// label222
						// 
						this->label222->AutoSize = true;
						this->label222->Location = System::Drawing::Point(6, 130);
						this->label222->Name = L"label222";
						this->label222->Size = System::Drawing::Size(114, 13);
						this->label222->TabIndex = 0;
						this->label222->Text = L"Minimum length of line:";
						// 
						// label213
						// 
						this->label213->AutoSize = true;
						this->label213->Location = System::Drawing::Point(6, 47);
						this->label213->Name = L"label213";
						this->label213->Size = System::Drawing::Size(271, 13);
						this->label213->TabIndex = 0;
						this->label213->Text = L"Maximum perpendicular distance from point P to line AB:";
						// 
						// numericUpDown74
						// 
						this->numericUpDown74->Location = System::Drawing::Point(280, 102);
						this->numericUpDown74->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown74->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown74->Name = L"numericUpDown74";
						this->numericUpDown74->Size = System::Drawing::Size(55, 20);
						this->numericUpDown74->TabIndex = 1;
						this->numericUpDown74->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
						// 
						// label212
						// 
						this->label212->AutoSize = true;
						this->label212->Location = System::Drawing::Point(6, 104);
						this->label212->Name = L"label212";
						this->label212->Size = System::Drawing::Size(131, 13);
						this->label212->TabIndex = 0;
						this->label212->Text = L"Minimum overhang length:";
						// 
						// numericUpDown73
						// 
						this->numericUpDown73->Location = System::Drawing::Point(280, 71);
						this->numericUpDown73->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
						this->numericUpDown73->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown73->Name = L"numericUpDown73";
						this->numericUpDown73->Size = System::Drawing::Size(55, 20);
						this->numericUpDown73->TabIndex = 1;
						this->numericUpDown73->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
						// 
						// label206
						// 
						this->label206->AutoSize = true;
						this->label206->Location = System::Drawing::Point(6, 73);
						this->label206->Name = L"label206";
						this->label206->Size = System::Drawing::Size(241, 13);
						this->label206->TabIndex = 0;
						this->label206->Text = L"Minimum distance between two points at merging:";
						// 
						// tabControl3
						// 
						this->tabControl3->Controls->Add(this->tabPage9);
						this->tabControl3->Controls->Add(this->tabPage16);
						this->tabControl3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->tabControl3->Location = System::Drawing::Point(0, 0);
						this->tabControl3->Name = L"tabControl3";
						this->tabControl3->SelectedIndex = 0;
						this->tabControl3->Size = System::Drawing::Size(502, 93);
						this->tabControl3->TabIndex = 30;
						// 
						// tabPage9
						// 
						this->tabPage9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->tabPage9->Controls->Add(this->label269);
						this->tabPage9->Controls->Add(this->numericUpDown69);
						this->tabPage9->Controls->Add(this->label223);
						this->tabPage9->Controls->Add(this->comboBox13);
						this->tabPage9->Controls->Add(this->label22);
						this->tabPage9->Controls->Add(this->numericUpDown35);
						this->tabPage9->Controls->Add(this->label82);
						this->tabPage9->Controls->Add(this->numericUpDown1);
						this->tabPage9->Controls->Add(this->numericUpDown2);
						this->tabPage9->Controls->Add(this->label20);
						this->tabPage9->Location = System::Drawing::Point(4, 21);
						this->tabPage9->Name = L"tabPage9";
						this->tabPage9->Padding = System::Windows::Forms::Padding(3);
						this->tabPage9->Size = System::Drawing::Size(494, 68);
						this->tabPage9->TabIndex = 0;
						this->tabPage9->Text = L"StartPose/ScanCount";
						// 
						// label269
						// 
						this->label269->AutoSize = true;
						this->label269->Location = System::Drawing::Point(172, 4);
						this->label269->Name = L"label269";
						this->label269->Size = System::Drawing::Size(75, 12);
						this->label269->TabIndex = 38;
						this->label269->Text = L"PredefinedPoses";
						// 
						// numericUpDown69
						// 
						this->numericUpDown69->Location = System::Drawing::Point(47, 42);
						this->numericUpDown69->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {360, 0, 0, 0});
						this->numericUpDown69->Name = L"numericUpDown69";
						this->numericUpDown69->Size = System::Drawing::Size(119, 18);
						this->numericUpDown69->TabIndex = 2;
						// 
						// label223
						// 
						this->label223->AutoSize = true;
						this->label223->Location = System::Drawing::Point(7, 44);
						this->label223->Name = L"label223";
						this->label223->Size = System::Drawing::Size(32, 12);
						this->label223->TabIndex = 35;
						this->label223->Text = L"Angle:";
						// 
						// comboBox13
						// 
						this->comboBox13->AllowDrop = true;
						this->comboBox13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
						this->comboBox13->DropDownHeight = 200;
						this->comboBox13->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
						this->comboBox13->DropDownWidth = 200;
						this->comboBox13->FormattingEnabled = true;
						this->comboBox13->IntegralHeight = false;
						this->comboBox13->Location = System::Drawing::Point(174, 17);
						this->comboBox13->Name = L"comboBox13";
						this->comboBox13->RightToLeft = System::Windows::Forms::RightToLeft::No;
						this->comboBox13->Size = System::Drawing::Size(310, 20);
						this->comboBox13->TabIndex = 3;
						this->comboBox13->SelectedIndexChanged += gcnew System::EventHandler(this, &MapBuilding_LM104::comboBox13_SelectedIndexChanged);
						// 
						// label22
						// 
						this->label22->AutoSize = true;
						this->label22->Location = System::Drawing::Point(5, 6);
						this->label22->Name = L"label22";
						this->label22->Size = System::Drawing::Size(29, 12);
						this->label22->TabIndex = 0;
						this->label22->Text = L"Pos X";
						// 
						// numericUpDown35
						// 
						this->numericUpDown35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->numericUpDown35->Location = System::Drawing::Point(234, 43);
						this->numericUpDown35->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown35->Name = L"numericUpDown35";
						this->numericUpDown35->Size = System::Drawing::Size(59, 20);
						this->numericUpDown35->TabIndex = 4;
						this->numericUpDown35->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label82
						// 
						this->label82->AutoSize = true;
						this->label82->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label82->Location = System::Drawing::Point(171, 45);
						this->label82->Name = L"label82";
						this->label82->Size = System::Drawing::Size(57, 13);
						this->label82->TabIndex = 2;
						this->label82->Text = L"StepScan:";
						// 
						// numericUpDown1
						// 
						this->numericUpDown1->Location = System::Drawing::Point(47, 4);
						this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65000, 0, 0, 0});
						this->numericUpDown1->Name = L"numericUpDown1";
						this->numericUpDown1->Size = System::Drawing::Size(119, 18);
						this->numericUpDown1->TabIndex = 0;
						// 
						// numericUpDown2
						// 
						this->numericUpDown2->Location = System::Drawing::Point(47, 23);
						this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65000, 0, 0, 0});
						this->numericUpDown2->Name = L"numericUpDown2";
						this->numericUpDown2->Size = System::Drawing::Size(119, 18);
						this->numericUpDown2->TabIndex = 1;
						// 
						// label20
						// 
						this->label20->AutoSize = true;
						this->label20->Location = System::Drawing::Point(6, 25);
						this->label20->Name = L"label20";
						this->label20->Size = System::Drawing::Size(28, 12);
						this->label20->TabIndex = 0;
						this->label20->Text = L"Pos Y";
						// 
						// tabPage16
						// 
						this->tabPage16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->tabPage16->Controls->Add(this->textBox14);
						this->tabPage16->Controls->Add(this->textBox11);
						this->tabPage16->Controls->Add(this->label17);
						this->tabPage16->Controls->Add(this->textBox13);
						this->tabPage16->Controls->Add(this->label16);
						this->tabPage16->Controls->Add(this->textBox12);
						this->tabPage16->Controls->Add(this->label19);
						this->tabPage16->Controls->Add(this->label18);
						this->tabPage16->Location = System::Drawing::Point(4, 21);
						this->tabPage16->Name = L"tabPage16";
						this->tabPage16->Padding = System::Windows::Forms::Padding(3);
						this->tabPage16->Size = System::Drawing::Size(494, 68);
						this->tabPage16->TabIndex = 2;
						this->tabPage16->Text = L"MapArea";
						// 
						// textBox14
						// 
						this->textBox14->BackColor = System::Drawing::Color::Gainsboro;
						this->textBox14->Location = System::Drawing::Point(154, 35);
						this->textBox14->Name = L"textBox14";
						this->textBox14->Size = System::Drawing::Size(64, 18);
						this->textBox14->TabIndex = 0;
						// 
						// textBox11
						// 
						this->textBox11->BackColor = System::Drawing::Color::Gainsboro;
						this->textBox11->Location = System::Drawing::Point(44, 13);
						this->textBox11->Name = L"textBox11";
						this->textBox11->Size = System::Drawing::Size(64, 18);
						this->textBox11->TabIndex = 0;
						// 
						// label17
						// 
						this->label17->AutoSize = true;
						this->label17->Location = System::Drawing::Point(119, 15);
						this->label17->Name = L"label17";
						this->label17->Size = System::Drawing::Size(29, 12);
						this->label17->TabIndex = 0;
						this->label17->Text = L"maxX";
						// 
						// textBox13
						// 
						this->textBox13->BackColor = System::Drawing::Color::Gainsboro;
						this->textBox13->Location = System::Drawing::Point(154, 13);
						this->textBox13->Name = L"textBox13";
						this->textBox13->Size = System::Drawing::Size(64, 18);
						this->textBox13->TabIndex = 0;
						// 
						// label16
						// 
						this->label16->AutoSize = true;
						this->label16->Location = System::Drawing::Point(12, 15);
						this->label16->Name = L"label16";
						this->label16->Size = System::Drawing::Size(26, 12);
						this->label16->TabIndex = 0;
						this->label16->Text = L"minX";
						// 
						// textBox12
						// 
						this->textBox12->BackColor = System::Drawing::Color::Gainsboro;
						this->textBox12->Location = System::Drawing::Point(44, 35);
						this->textBox12->Name = L"textBox12";
						this->textBox12->Size = System::Drawing::Size(64, 18);
						this->textBox12->TabIndex = 0;
						// 
						// label19
						// 
						this->label19->AutoSize = true;
						this->label19->Location = System::Drawing::Point(13, 38);
						this->label19->Name = L"label19";
						this->label19->Size = System::Drawing::Size(25, 12);
						this->label19->TabIndex = 0;
						this->label19->Text = L"minY";
						// 
						// label18
						// 
						this->label18->AutoSize = true;
						this->label18->Location = System::Drawing::Point(119, 38);
						this->label18->Name = L"label18";
						this->label18->Size = System::Drawing::Size(28, 12);
						this->label18->TabIndex = 0;
						this->label18->Text = L"maxY";
						// 
						// tabPage5
						// 
						this->tabPage5->Controls->Add(this->tabControl7);
						this->tabPage5->Controls->Add(this->label181);
						this->tabPage5->Controls->Add(this->listBox1);
						this->tabPage5->Controls->Add(this->label182);
						this->tabPage5->Controls->Add(this->label183);
						this->tabPage5->Controls->Add(this->pictureBox2);
						this->tabPage5->Controls->Add(this->label188);
						this->tabPage5->Location = System::Drawing::Point(4, 22);
						this->tabPage5->Name = L"tabPage5";
						this->tabPage5->Padding = System::Windows::Forms::Padding(3);
						this->tabPage5->Size = System::Drawing::Size(502, 842);
						this->tabPage5->TabIndex = 2;
						this->tabPage5->Text = L"LSB Data file";
						this->tabPage5->UseVisualStyleBackColor = true;
						// 
						// tabControl7
						// 
						this->tabControl7->Controls->Add(this->tabPage26);
						this->tabControl7->Controls->Add(this->tabPage27);
						this->tabControl7->Location = System::Drawing::Point(3, 644);
						this->tabControl7->Name = L"tabControl7";
						this->tabControl7->SelectedIndex = 0;
						this->tabControl7->Size = System::Drawing::Size(496, 198);
						this->tabControl7->TabIndex = 59;
						// 
						// tabPage26
						// 
						this->tabPage26->Controls->Add(this->groupBox32);
						this->tabPage26->Controls->Add(this->groupBox31);
						this->tabPage26->Controls->Add(this->groupBox33);
						this->tabPage26->Location = System::Drawing::Point(4, 22);
						this->tabPage26->Name = L"tabPage26";
						this->tabPage26->Padding = System::Windows::Forms::Padding(3);
						this->tabPage26->Size = System::Drawing::Size(488, 172);
						this->tabPage26->TabIndex = 0;
						this->tabPage26->Text = L"View/Coordinates";
						this->tabPage26->UseVisualStyleBackColor = true;
						// 
						// groupBox32
						// 
						this->groupBox32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->groupBox32->Controls->Add(this->radioButton6);
						this->groupBox32->Controls->Add(this->radioButton7);
						this->groupBox32->Controls->Add(this->radioButton8);
						this->groupBox32->Location = System::Drawing::Point(127, 99);
						this->groupBox32->Name = L"groupBox32";
						this->groupBox32->Size = System::Drawing::Size(242, 43);
						this->groupBox32->TabIndex = 57;
						this->groupBox32->TabStop = false;
						this->groupBox32->Text = L"View style";
						// 
						// radioButton6
						// 
						this->radioButton6->AutoSize = true;
						this->radioButton6->Location = System::Drawing::Point(136, 19);
						this->radioButton6->Name = L"radioButton6";
						this->radioButton6->Size = System::Drawing::Size(101, 17);
						this->radioButton6->TabIndex = 0;
						this->radioButton6->TabStop = true;
						this->radioButton6->Text = L"Polar Y-mirorring";
						this->radioButton6->UseVisualStyleBackColor = true;
						// 
						// radioButton7
						// 
						this->radioButton7->AutoSize = true;
						this->radioButton7->Location = System::Drawing::Point(61, 19);
						this->radioButton7->Name = L"radioButton7";
						this->radioButton7->Size = System::Drawing::Size(69, 17);
						this->radioButton7->TabIndex = 0;
						this->radioButton7->TabStop = true;
						this->radioButton7->Text = L"Cartesian";
						this->radioButton7->UseVisualStyleBackColor = true;
						// 
						// radioButton8
						// 
						this->radioButton8->AutoSize = true;
						this->radioButton8->Location = System::Drawing::Point(6, 19);
						this->radioButton8->Name = L"radioButton8";
						this->radioButton8->Size = System::Drawing::Size(49, 17);
						this->radioButton8->TabIndex = 0;
						this->radioButton8->TabStop = true;
						this->radioButton8->Text = L"Polar";
						this->radioButton8->UseVisualStyleBackColor = true;
						// 
						// groupBox31
						// 
						this->groupBox31->BackColor = System::Drawing::Color::WhiteSmoke;
						this->groupBox31->Controls->Add(this->textBox15);
						this->groupBox31->Controls->Add(this->textBox16);
						this->groupBox31->Controls->Add(this->textBox17);
						this->groupBox31->Controls->Add(this->label177);
						this->groupBox31->Controls->Add(this->label178);
						this->groupBox31->Controls->Add(this->label179);
						this->groupBox31->Controls->Add(this->textBox18);
						this->groupBox31->Controls->Add(this->label180);
						this->groupBox31->Location = System::Drawing::Point(3, 6);
						this->groupBox31->Name = L"groupBox31";
						this->groupBox31->Size = System::Drawing::Size(242, 71);
						this->groupBox31->TabIndex = 59;
						this->groupBox31->TabStop = false;
						this->groupBox31->Text = L"Cartesian coordinates min/max";
						// 
						// textBox15
						// 
						this->textBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->textBox15->Location = System::Drawing::Point(142, 43);
						this->textBox15->Name = L"textBox15";
						this->textBox15->Size = System::Drawing::Size(53, 18);
						this->textBox15->TabIndex = 1;
						// 
						// textBox16
						// 
						this->textBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->textBox16->Location = System::Drawing::Point(42, 19);
						this->textBox16->Name = L"textBox16";
						this->textBox16->Size = System::Drawing::Size(53, 18);
						this->textBox16->TabIndex = 1;
						// 
						// textBox17
						// 
						this->textBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->textBox17->Location = System::Drawing::Point(142, 19);
						this->textBox17->Name = L"textBox17";
						this->textBox17->Size = System::Drawing::Size(53, 18);
						this->textBox17->TabIndex = 1;
						// 
						// label177
						// 
						this->label177->AutoSize = true;
						this->label177->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label177->Location = System::Drawing::Point(11, 22);
						this->label177->Name = L"label177";
						this->label177->Size = System::Drawing::Size(26, 12);
						this->label177->TabIndex = 0;
						this->label177->Text = L"minX";
						// 
						// label178
						// 
						this->label178->AutoSize = true;
						this->label178->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label178->Location = System::Drawing::Point(108, 46);
						this->label178->Name = L"label178";
						this->label178->Size = System::Drawing::Size(28, 12);
						this->label178->TabIndex = 0;
						this->label178->Text = L"maxY";
						// 
						// label179
						// 
						this->label179->AutoSize = true;
						this->label179->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label179->Location = System::Drawing::Point(11, 46);
						this->label179->Name = L"label179";
						this->label179->Size = System::Drawing::Size(25, 12);
						this->label179->TabIndex = 0;
						this->label179->Text = L"minY";
						// 
						// textBox18
						// 
						this->textBox18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->textBox18->Location = System::Drawing::Point(42, 43);
						this->textBox18->Name = L"textBox18";
						this->textBox18->Size = System::Drawing::Size(53, 18);
						this->textBox18->TabIndex = 1;
						// 
						// label180
						// 
						this->label180->AutoSize = true;
						this->label180->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label180->Location = System::Drawing::Point(107, 22);
						this->label180->Name = L"label180";
						this->label180->Size = System::Drawing::Size(29, 12);
						this->label180->TabIndex = 0;
						this->label180->Text = L"maxX";
						// 
						// groupBox33
						// 
						this->groupBox33->BackColor = System::Drawing::Color::WhiteSmoke;
						this->groupBox33->Controls->Add(this->textBox19);
						this->groupBox33->Controls->Add(this->textBox20);
						this->groupBox33->Controls->Add(this->label184);
						this->groupBox33->Controls->Add(this->textBox21);
						this->groupBox33->Controls->Add(this->label185);
						this->groupBox33->Controls->Add(this->textBox22);
						this->groupBox33->Controls->Add(this->label186);
						this->groupBox33->Controls->Add(this->label187);
						this->groupBox33->Location = System::Drawing::Point(250, 6);
						this->groupBox33->Name = L"groupBox33";
						this->groupBox33->Size = System::Drawing::Size(232, 71);
						this->groupBox33->TabIndex = 51;
						this->groupBox33->TabStop = false;
						this->groupBox33->Text = L"Polar coordinates min/max";
						// 
						// textBox19
						// 
						this->textBox19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->textBox19->Location = System::Drawing::Point(138, 43);
						this->textBox19->Name = L"textBox19";
						this->textBox19->Size = System::Drawing::Size(53, 18);
						this->textBox19->TabIndex = 1;
						// 
						// textBox20
						// 
						this->textBox20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->textBox20->Location = System::Drawing::Point(138, 19);
						this->textBox20->Name = L"textBox20";
						this->textBox20->Size = System::Drawing::Size(53, 18);
						this->textBox20->TabIndex = 1;
						// 
						// label184
						// 
						this->label184->AutoSize = true;
						this->label184->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label184->Location = System::Drawing::Point(104, 46);
						this->label184->Name = L"label184";
						this->label184->Size = System::Drawing::Size(28, 12);
						this->label184->TabIndex = 0;
						this->label184->Text = L"maxY";
						// 
						// textBox21
						// 
						this->textBox21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->textBox21->Location = System::Drawing::Point(38, 43);
						this->textBox21->Name = L"textBox21";
						this->textBox21->Size = System::Drawing::Size(53, 18);
						this->textBox21->TabIndex = 1;
						// 
						// label185
						// 
						this->label185->AutoSize = true;
						this->label185->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label185->Location = System::Drawing::Point(103, 22);
						this->label185->Name = L"label185";
						this->label185->Size = System::Drawing::Size(29, 12);
						this->label185->TabIndex = 0;
						this->label185->Text = L"maxX";
						// 
						// textBox22
						// 
						this->textBox22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->textBox22->Location = System::Drawing::Point(38, 19);
						this->textBox22->Name = L"textBox22";
						this->textBox22->Size = System::Drawing::Size(53, 18);
						this->textBox22->TabIndex = 1;
						// 
						// label186
						// 
						this->label186->AutoSize = true;
						this->label186->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label186->Location = System::Drawing::Point(7, 46);
						this->label186->Name = L"label186";
						this->label186->Size = System::Drawing::Size(25, 12);
						this->label186->TabIndex = 0;
						this->label186->Text = L"minY";
						// 
						// label187
						// 
						this->label187->AutoSize = true;
						this->label187->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label187->Location = System::Drawing::Point(7, 22);
						this->label187->Name = L"label187";
						this->label187->Size = System::Drawing::Size(26, 12);
						this->label187->TabIndex = 0;
						this->label187->Text = L"minX";
						// 
						// tabPage27
						// 
						this->tabPage27->Controls->Add(this->panel14);
						this->tabPage27->Location = System::Drawing::Point(4, 22);
						this->tabPage27->Name = L"tabPage27";
						this->tabPage27->Padding = System::Windows::Forms::Padding(3);
						this->tabPage27->Size = System::Drawing::Size(488, 172);
						this->tabPage27->TabIndex = 1;
						this->tabPage27->Text = L"LSB Data";
						this->tabPage27->UseVisualStyleBackColor = true;
						// 
						// panel14
						// 
						this->panel14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->panel14->Controls->Add(this->button11);
						this->panel14->Controls->Add(this->checkBox39);
						this->panel14->Controls->Add(this->numericUpDown88);
						this->panel14->Controls->Add(this->label250);
						this->panel14->Controls->Add(this->label251);
						this->panel14->Location = System::Drawing::Point(0, 0);
						this->panel14->Name = L"panel14";
						this->panel14->Size = System::Drawing::Size(488, 172);
						this->panel14->TabIndex = 0;
						// 
						// button11
						// 
						this->button11->Location = System::Drawing::Point(179, 124);
						this->button11->Name = L"button11";
						this->button11->Size = System::Drawing::Size(96, 29);
						this->button11->TabIndex = 8;
						this->button11->Text = L"Apply";
						this->button11->UseVisualStyleBackColor = true;
						this->button11->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button11_Click);
						// 
						// checkBox39
						// 
						this->checkBox39->AutoSize = true;
						this->checkBox39->Location = System::Drawing::Point(7, 11);
						this->checkBox39->Name = L"checkBox39";
						this->checkBox39->Size = System::Drawing::Size(166, 17);
						this->checkBox39->TabIndex = 7;
						this->checkBox39->Text = L"If beam Length is bigger than:";
						this->checkBox39->UseVisualStyleBackColor = true;
						// 
						// numericUpDown88
						// 
						this->numericUpDown88->Location = System::Drawing::Point(179, 10);
						this->numericUpDown88->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {20000000, 0, 0, 0});
						this->numericUpDown88->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						this->numericUpDown88->Name = L"numericUpDown88";
						this->numericUpDown88->Size = System::Drawing::Size(86, 20);
						this->numericUpDown88->TabIndex = 6;
						this->numericUpDown88->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
						// 
						// label250
						// 
						this->label250->AutoSize = true;
						this->label250->Location = System::Drawing::Point(271, 12);
						this->label250->Name = L"label250";
						this->label250->Size = System::Drawing::Size(171, 13);
						this->label250->TabIndex = 4;
						this->label250->Text = L"use average of bunch instead of it.";
						// 
						// label251
						// 
						this->label251->AutoSize = true;
						this->label251->Location = System::Drawing::Point(271, 25);
						this->label251->Name = L"label251";
						this->label251->Size = System::Drawing::Size(101, 13);
						this->label251->TabIndex = 5;
						this->label251->Text = L"Without limit values.";
						// 
						// label181
						// 
						this->label181->AutoSize = true;
						this->label181->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label181->Location = System::Drawing::Point(181, 3);
						this->label181->Name = L"label181";
						this->label181->Size = System::Drawing::Size(112, 13);
						this->label181->TabIndex = 53;
						this->label181->Text = L"Scan from LSB file";
						// 
						// listBox1
						// 
						this->listBox1->FormattingEnabled = true;
						this->listBox1->Location = System::Drawing::Point(6, 335);
						this->listBox1->Name = L"listBox1";
						this->listBox1->Size = System::Drawing::Size(493, 303);
						this->listBox1->TabIndex = 58;
						this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MapBuilding_LM104::listBox1_SelectedIndexChanged);
						// 
						// label182
						// 
						this->label182->AutoSize = true;
						this->label182->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label182->Location = System::Drawing::Point(181, 319);
						this->label182->Name = L"label182";
						this->label182->Size = System::Drawing::Size(60, 13);
						this->label182->TabIndex = 55;
						this->label182->Text = L"Scan List";
						// 
						// label183
						// 
						this->label183->AutoSize = true;
						this->label183->Location = System::Drawing::Point(6, 319);
						this->label183->Name = L"label183";
						this->label183->Size = System::Drawing::Size(99, 13);
						this->label183->TabIndex = 54;
						this->label183->Text = L"( Define start scan )";
						// 
						// pictureBox2
						// 
						this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
						this->pictureBox2->Location = System::Drawing::Point(6, 19);
						this->pictureBox2->Name = L"pictureBox2";
						this->pictureBox2->Size = System::Drawing::Size(490, 297);
						this->pictureBox2->TabIndex = 52;
						this->pictureBox2->TabStop = false;
						// 
						// label188
						// 
						this->label188->AutoSize = true;
						this->label188->Location = System::Drawing::Point(314, 319);
						this->label188->Name = L"label188";
						this->label188->Size = System::Drawing::Size(115, 13);
						this->label188->TabIndex = 56;
						this->label188->Text = L"[ Number of samples: ] ";
						// 
						// tabPage6
						// 
						this->tabPage6->Controls->Add(this->groupBox58);
						this->tabPage6->Controls->Add(this->groupBox60);
						this->tabPage6->Controls->Add(this->listBox2);
						this->tabPage6->Controls->Add(this->groupBox62);
						this->tabPage6->Controls->Add(this->label211);
						this->tabPage6->Location = System::Drawing::Point(4, 22);
						this->tabPage6->Name = L"tabPage6";
						this->tabPage6->Padding = System::Windows::Forms::Padding(3);
						this->tabPage6->Size = System::Drawing::Size(502, 842);
						this->tabPage6->TabIndex = 3;
						this->tabPage6->Text = L"Found positions";
						this->tabPage6->UseVisualStyleBackColor = true;
						// 
						// groupBox58
						// 
						this->groupBox58->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->groupBox58->Controls->Add(this->groupBox59);
						this->groupBox58->Controls->Add(this->checkBox46);
						this->groupBox58->Controls->Add(this->checkBox45);
						this->groupBox58->Controls->Add(this->button24);
						this->groupBox58->Location = System::Drawing::Point(3, 607);
						this->groupBox58->Name = L"groupBox58";
						this->groupBox58->Size = System::Drawing::Size(493, 99);
						this->groupBox58->TabIndex = 19;
						this->groupBox58->TabStop = false;
						this->groupBox58->Text = L"Data file";
						// 
						// groupBox59
						// 
						this->groupBox59->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->groupBox59->Controls->Add(this->numericUpDown72);
						this->groupBox59->Controls->Add(this->radioButton34);
						this->groupBox59->Controls->Add(this->radioButton35);
						this->groupBox59->Controls->Add(this->radioButton36);
						this->groupBox59->Controls->Add(this->radioButton37);
						this->groupBox59->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->groupBox59->Location = System::Drawing::Point(7, 58);
						this->groupBox59->Name = L"groupBox59";
						this->groupBox59->Size = System::Drawing::Size(271, 34);
						this->groupBox59->TabIndex = 14;
						this->groupBox59->TabStop = false;
						this->groupBox59->Text = L"Group separator";
						// 
						// numericUpDown72
						// 
						this->numericUpDown72->Location = System::Drawing::Point(220, 13);
						this->numericUpDown72->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
						this->numericUpDown72->Name = L"numericUpDown72";
						this->numericUpDown72->Size = System::Drawing::Size(44, 18);
						this->numericUpDown72->TabIndex = 6;
						this->numericUpDown72->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {9, 0, 0, 0});
						// 
						// radioButton34
						// 
						this->radioButton34->AutoSize = true;
						this->radioButton34->Location = System::Drawing::Point(163, 14);
						this->radioButton34->Name = L"radioButton34";
						this->radioButton34->Size = System::Drawing::Size(58, 16);
						this->radioButton34->TabIndex = 5;
						this->radioButton34->TabStop = true;
						this->radioButton34->Text = L"UserDef";
						this->radioButton34->UseVisualStyleBackColor = true;
						// 
						// radioButton35
						// 
						this->radioButton35->AutoSize = true;
						this->radioButton35->Location = System::Drawing::Point(108, 14);
						this->radioButton35->Name = L"radioButton35";
						this->radioButton35->Size = System::Drawing::Size(56, 16);
						this->radioButton35->TabIndex = 2;
						this->radioButton35->TabStop = true;
						this->radioButton35->Text = L"Comma";
						this->radioButton35->UseVisualStyleBackColor = true;
						// 
						// radioButton36
						// 
						this->radioButton36->AutoSize = true;
						this->radioButton36->Location = System::Drawing::Point(67, 14);
						this->radioButton36->Name = L"radioButton36";
						this->radioButton36->Size = System::Drawing::Size(41, 16);
						this->radioButton36->TabIndex = 1;
						this->radioButton36->TabStop = true;
						this->radioButton36->Text = L"TAB";
						this->radioButton36->UseVisualStyleBackColor = true;
						// 
						// radioButton37
						// 
						this->radioButton37->AutoSize = true;
						this->radioButton37->Location = System::Drawing::Point(3, 14);
						this->radioButton37->Name = L"radioButton37";
						this->radioButton37->Size = System::Drawing::Size(68, 16);
						this->radioButton37->TabIndex = 0;
						this->radioButton37->TabStop = true;
						this->radioButton37->Text = L"SemiColon";
						this->radioButton37->UseVisualStyleBackColor = true;
						// 
						// checkBox46
						// 
						this->checkBox46->AutoSize = true;
						this->checkBox46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox46->Location = System::Drawing::Point(164, 19);
						this->checkBox46->Name = L"checkBox46";
						this->checkBox46->Size = System::Drawing::Size(103, 16);
						this->checkBox46->TabIndex = 13;
						this->checkBox46->Text = L"No column headers";
						this->checkBox46->UseVisualStyleBackColor = true;
						// 
						// checkBox45
						// 
						this->checkBox45->AutoSize = true;
						this->checkBox45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox45->Location = System::Drawing::Point(164, 36);
						this->checkBox45->Name = L"checkBox45";
						this->checkBox45->Size = System::Drawing::Size(152, 16);
						this->checkBox45->TabIndex = 12;
						this->checkBox45->Text = L"Use Dot as a decadic separator";
						this->checkBox45->UseVisualStyleBackColor = true;
						// 
						// button24
						// 
						this->button24->Location = System::Drawing::Point(6, 19);
						this->button24->Name = L"button24";
						this->button24->Size = System::Drawing::Size(152, 33);
						this->button24->TabIndex = 11;
						this->button24->Text = L"Save data to TXT file";
						this->button24->UseVisualStyleBackColor = true;
						this->button24->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button24_Click);
						// 
						// groupBox60
						// 
						this->groupBox60->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->groupBox60->Controls->Add(this->groupBox61);
						this->groupBox60->Controls->Add(this->checkBox50);
						this->groupBox60->Controls->Add(this->button25);
						this->groupBox60->Location = System::Drawing::Point(3, 519);
						this->groupBox60->Name = L"groupBox60";
						this->groupBox60->Size = System::Drawing::Size(493, 82);
						this->groupBox60->TabIndex = 18;
						this->groupBox60->TabStop = false;
						this->groupBox60->Text = L"View Style/Drawing";
						// 
						// groupBox61
						// 
						this->groupBox61->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->groupBox61->Controls->Add(this->checkBox37);
						this->groupBox61->Controls->Add(this->checkBox38);
						this->groupBox61->Location = System::Drawing::Point(164, 15);
						this->groupBox61->Name = L"groupBox61";
						this->groupBox61->Size = System::Drawing::Size(129, 61);
						this->groupBox61->TabIndex = 4;
						this->groupBox61->TabStop = false;
						this->groupBox61->Text = L"AutoScreenShot";
						// 
						// checkBox37
						// 
						this->checkBox37->AutoSize = true;
						this->checkBox37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox37->Location = System::Drawing::Point(6, 19);
						this->checkBox37->Name = L"checkBox37";
						this->checkBox37->Size = System::Drawing::Size(113, 16);
						this->checkBox37->TabIndex = 0;
						this->checkBox37->Text = L"Draw MovingObjects";
						this->checkBox37->UseVisualStyleBackColor = true;
						// 
						// checkBox38
						// 
						this->checkBox38->AutoSize = true;
						this->checkBox38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox38->Location = System::Drawing::Point(6, 35);
						this->checkBox38->Name = L"checkBox38";
						this->checkBox38->Size = System::Drawing::Size(105, 16);
						this->checkBox38->TabIndex = 1;
						this->checkBox38->Text = L"Draw StaticObjects";
						this->checkBox38->UseVisualStyleBackColor = true;
						// 
						// checkBox50
						// 
						this->checkBox50->AutoSize = true;
						this->checkBox50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->checkBox50->Location = System::Drawing::Point(299, 17);
						this->checkBox50->Name = L"checkBox50";
						this->checkBox50->Size = System::Drawing::Size(74, 16);
						this->checkBox50->TabIndex = 3;
						this->checkBox50->Text = L"Draw Robot";
						this->checkBox50->UseVisualStyleBackColor = true;
						// 
						// button25
						// 
						this->button25->Location = System::Drawing::Point(4, 15);
						this->button25->Name = L"button25";
						this->button25->Size = System::Drawing::Size(154, 29);
						this->button25->TabIndex = 2;
						this->button25->Text = L"Draw All scans ";
						this->button25->UseVisualStyleBackColor = true;
						this->button25->Click += gcnew System::EventHandler(this, &MapBuilding_LM104::button25_Click);
						// 
						// listBox2
						// 
						this->listBox2->FormattingEnabled = true;
						this->listBox2->Location = System::Drawing::Point(3, 21);
						this->listBox2->Name = L"listBox2";
						this->listBox2->Size = System::Drawing::Size(493, 368);
						this->listBox2->TabIndex = 17;
						this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MapBuilding_LM104::listBox2_SelectedIndexChanged);
						// 
						// groupBox62
						// 
						this->groupBox62->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(255)));
						this->groupBox62->Controls->Add(this->label207);
						this->groupBox62->Controls->Add(this->label208);
						this->groupBox62->Controls->Add(this->label209);
						this->groupBox62->Controls->Add(this->label210);
						this->groupBox62->Location = System::Drawing::Point(3, 395);
						this->groupBox62->Name = L"groupBox62";
						this->groupBox62->Size = System::Drawing::Size(493, 118);
						this->groupBox62->TabIndex = 16;
						this->groupBox62->TabStop = false;
						this->groupBox62->Text = L"Info";
						// 
						// label207
						// 
						this->label207->AutoSize = true;
						this->label207->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label207->Location = System::Drawing::Point(6, 65);
						this->label207->Name = L"label207";
						this->label207->Size = System::Drawing::Size(94, 13);
						this->label207->TabIndex = 0;
						this->label207->Text = L"Local Optimum:";
						// 
						// label208
						// 
						this->label208->AutoSize = true;
						this->label208->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label208->Location = System::Drawing::Point(6, 42);
						this->label208->Name = L"label208";
						this->label208->Size = System::Drawing::Size(56, 13);
						this->label208->TabIndex = 0;
						this->label208->Text = L"Position:";
						// 
						// label209
						// 
						this->label209->AutoSize = true;
						this->label209->Location = System::Drawing::Point(6, 90);
						this->label209->Name = L"label209";
						this->label209->Size = System::Drawing::Size(60, 13);
						this->label209->TabIndex = 0;
						this->label209->Text = L"Scan Area:";
						// 
						// label210
						// 
						this->label210->AutoSize = true;
						this->label210->Location = System::Drawing::Point(6, 16);
						this->label210->Name = L"label210";
						this->label210->Size = System::Drawing::Size(82, 13);
						this->label210->TabIndex = 0;
						this->label210->Text = L"Sample [index]: ";
						// 
						// label211
						// 
						this->label211->AutoSize = true;
						this->label211->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label211->Location = System::Drawing::Point(3, 5);
						this->label211->Name = L"label211";
						this->label211->Size = System::Drawing::Size(76, 13);
						this->label211->TabIndex = 15;
						this->label211->Text = L"Position List";
						// 
						// tabControl2
						// 
						this->tabControl2->Controls->Add(this->tabPage3);
						this->tabControl2->Controls->Add(this->tabPage4);
						this->tabControl2->Dock = System::Windows::Forms::DockStyle::Fill;
						this->tabControl2->Location = System::Drawing::Point(3, 29);
						this->tabControl2->Name = L"tabControl2";
						this->tabControl2->SelectedIndex = 0;
						this->tabControl2->Size = System::Drawing::Size(1150, 868);
						this->tabControl2->TabIndex = 4;
						// 
						// tabPage3
						// 
						this->tabPage3->Controls->Add(this->pictureBox1);
						this->tabPage3->Location = System::Drawing::Point(4, 22);
						this->tabPage3->Name = L"tabPage3";
						this->tabPage3->Padding = System::Windows::Forms::Padding(3);
						this->tabPage3->Size = System::Drawing::Size(1142, 842);
						this->tabPage3->TabIndex = 0;
						this->tabPage3->Text = L"Map of Environment";
						this->tabPage3->UseVisualStyleBackColor = true;
						// 
						// pictureBox1
						// 
						this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
						this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
						this->pictureBox1->Location = System::Drawing::Point(3, 3);
						this->pictureBox1->Name = L"pictureBox1";
						this->pictureBox1->Size = System::Drawing::Size(1136, 836);
						this->pictureBox1->TabIndex = 0;
						this->pictureBox1->TabStop = false;
						this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MapBuilding_LM104::pictureBox1_MouseMove);
						// 
						// tabPage4
						// 
						this->tabPage4->Controls->Add(this->panel13);
						this->tabPage4->Location = System::Drawing::Point(4, 22);
						this->tabPage4->Name = L"tabPage4";
						this->tabPage4->Padding = System::Windows::Forms::Padding(3);
						this->tabPage4->Size = System::Drawing::Size(1142, 842);
						this->tabPage4->TabIndex = 1;
						this->tabPage4->Text = L"Running Results";
						this->tabPage4->UseVisualStyleBackColor = true;
						// 
						// panel13
						// 
						this->panel13->AutoScroll = true;
						this->panel13->BackColor = System::Drawing::Color::WhiteSmoke;
						this->panel13->Controls->Add(this->groupBox70);
						this->panel13->Controls->Add(this->groupBox69);
						this->panel13->Dock = System::Windows::Forms::DockStyle::Fill;
						this->panel13->Location = System::Drawing::Point(3, 3);
						this->panel13->Name = L"panel13";
						this->panel13->Size = System::Drawing::Size(1136, 836);
						this->panel13->TabIndex = 0;
						// 
						// groupBox70
						// 
						this->groupBox70->Controls->Add(this->label236);
						this->groupBox70->Controls->Add(this->label235);
						this->groupBox70->Controls->Add(this->label234);
						this->groupBox70->Controls->Add(this->label233);
						this->groupBox70->Controls->Add(this->label232);
						this->groupBox70->Controls->Add(this->label231);
						this->groupBox70->Controls->Add(this->label230);
						this->groupBox70->Controls->Add(this->label229);
						this->groupBox70->Controls->Add(this->label228);
						this->groupBox70->Controls->Add(this->panel10);
						this->groupBox70->Location = System::Drawing::Point(3, 220);
						this->groupBox70->Name = L"groupBox70";
						this->groupBox70->Size = System::Drawing::Size(1113, 236);
						this->groupBox70->TabIndex = 2;
						this->groupBox70->TabStop = false;
						this->groupBox70->Text = L"Running Messages";
						// 
						// label236
						// 
						this->label236->AutoSize = true;
						this->label236->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label236->Location = System::Drawing::Point(808, 16);
						this->label236->Name = L"label236";
						this->label236->Size = System::Drawing::Size(38, 13);
						this->label236->TabIndex = 1;
						this->label236->Text = L"Beam";
						// 
						// label235
						// 
						this->label235->AutoSize = true;
						this->label235->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label235->Location = System::Drawing::Point(717, 16);
						this->label235->Name = L"label235";
						this->label235->Size = System::Drawing::Size(55, 13);
						this->label235->TabIndex = 1;
						this->label235->Text = L"Optimum";
						// 
						// label234
						// 
						this->label234->AutoSize = true;
						this->label234->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label234->Location = System::Drawing::Point(575, 16);
						this->label234->Name = L"label234";
						this->label234->Size = System::Drawing::Size(42, 13);
						this->label234->TabIndex = 1;
						this->label234->Text = L"CL1/2";
						// 
						// label233
						// 
						this->label233->AutoSize = true;
						this->label233->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label233->Location = System::Drawing::Point(503, 16);
						this->label233->Name = L"label233";
						this->label233->Size = System::Drawing::Size(36, 13);
						this->label233->TabIndex = 1;
						this->label233->Text = L"EpsT";
						// 
						// label232
						// 
						this->label232->AutoSize = true;
						this->label232->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label232->Location = System::Drawing::Point(389, 14);
						this->label232->Name = L"label232";
						this->label232->Size = System::Drawing::Size(39, 13);
						this->label232->TabIndex = 1;
						this->label232->Text = L"Angle";
						// 
						// label231
						// 
						this->label231->AutoSize = true;
						this->label231->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label231->Location = System::Drawing::Point(328, 14);
						this->label231->Name = L"label231";
						this->label231->Size = System::Drawing::Size(15, 13);
						this->label231->TabIndex = 1;
						this->label231->Text = L"Y";
						// 
						// label230
						// 
						this->label230->AutoSize = true;
						this->label230->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label230->Location = System::Drawing::Point(250, 16);
						this->label230->Name = L"label230";
						this->label230->Size = System::Drawing::Size(15, 13);
						this->label230->TabIndex = 1;
						this->label230->Text = L"X";
						// 
						// label229
						// 
						this->label229->AutoSize = true;
						this->label229->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label229->Location = System::Drawing::Point(118, 16);
						this->label229->Name = L"label229";
						this->label229->Size = System::Drawing::Size(47, 13);
						this->label229->TabIndex = 1;
						this->label229->Text = L"Sender";
						// 
						// label228
						// 
						this->label228->AutoSize = true;
						this->label228->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->label228->Location = System::Drawing::Point(20, 16);
						this->label228->Name = L"label228";
						this->label228->Size = System::Drawing::Size(40, 13);
						this->label228->TabIndex = 1;
						this->label228->Text = L"SCAN";
						// 
						// panel10
						// 
						this->panel10->AutoScroll = true;
						this->panel10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->panel10->Controls->Add(this->groupBox63);
						this->panel10->Controls->Add(this->richTextBox1);
						this->panel10->Location = System::Drawing::Point(6, 32);
						this->panel10->Name = L"panel10";
						this->panel10->Size = System::Drawing::Size(1101, 186);
						this->panel10->TabIndex = 0;
						// 
						// groupBox63
						// 
						this->groupBox63->Location = System::Drawing::Point(3, 180);
						this->groupBox63->Name = L"groupBox63";
						this->groupBox63->Size = System::Drawing::Size(1078, 95);
						this->groupBox63->TabIndex = 1;
						this->groupBox63->TabStop = false;
						this->groupBox63->Text = L"Info";
						// 
						// richTextBox1
						// 
						this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
						this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->richTextBox1->Location = System::Drawing::Point(3, 3);
						this->richTextBox1->Name = L"richTextBox1";
						this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
						this->richTextBox1->Size = System::Drawing::Size(1078, 171);
						this->richTextBox1->TabIndex = 0;
						this->richTextBox1->Text = L"";
						this->richTextBox1->WordWrap = false;
						// 
						// groupBox69
						// 
						this->groupBox69->Controls->Add(this->panel11);
						this->groupBox69->Location = System::Drawing::Point(3, 3);
						this->groupBox69->Name = L"groupBox69";
						this->groupBox69->Size = System::Drawing::Size(1113, 211);
						this->groupBox69->TabIndex = 1;
						this->groupBox69->TabStop = false;
						this->groupBox69->Text = L"List of Active Beam  ( sequence of Active beams * - Active, . - Inactive )";
						// 
						// panel11
						// 
						this->panel11->AutoScroll = true;
						this->panel11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
										static_cast<System::Int32>(static_cast<System::Byte>(192)));
						this->panel11->Controls->Add(this->groupBox66);
						this->panel11->Controls->Add(this->richTextBox2);
						this->panel11->Location = System::Drawing::Point(6, 19);
						this->panel11->Name = L"panel11";
						this->panel11->Size = System::Drawing::Size(1101, 189);
						this->panel11->TabIndex = 0;
						// 
						// groupBox66
						// 
						this->groupBox66->Location = System::Drawing::Point(3, 186);
						this->groupBox66->Name = L"groupBox66";
						this->groupBox66->Size = System::Drawing::Size(1078, 42);
						this->groupBox66->TabIndex = 1;
						this->groupBox66->TabStop = false;
						this->groupBox66->Text = L"Info";
						// 
						// richTextBox2
						// 
						this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
						this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
										static_cast<System::Byte>(238)));
						this->richTextBox2->Location = System::Drawing::Point(3, 3);
						this->richTextBox2->Name = L"richTextBox2";
						this->richTextBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
						this->richTextBox2->Size = System::Drawing::Size(1078, 177);
						this->richTextBox2->TabIndex = 0;
						this->richTextBox2->Text = L"";
						this->richTextBox2->WordWrap = false;
						// 
						// MapBuilding_LM104
						// 
						this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
						this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
						this->Controls->Add(this->tableLayoutPanel1);
						this->Name = L"MapBuilding_LM104";
						this->Size = System::Drawing::Size(1672, 930);
						this->Load += gcnew System::EventHandler(this, &MapBuilding_LM104::MapBuilding_LM104_Load);
						this->tableLayoutPanel1->ResumeLayout(false);
						this->tableLayoutPanel1->PerformLayout();
						this->toolStrip1->ResumeLayout(false);
						this->toolStrip1->PerformLayout();
						this->panel1->ResumeLayout(false);
						this->panel1->PerformLayout();
						this->statusStrip1->ResumeLayout(false);
						this->statusStrip1->PerformLayout();
						this->tabControl1->ResumeLayout(false);
						this->tabPage1->ResumeLayout(false);
						this->groupBox2->ResumeLayout(false);
						this->groupBox2->PerformLayout();
						this->groupBox1->ResumeLayout(false);
						this->groupBox1->PerformLayout();
						this->tabPage2->ResumeLayout(false);
						this->tabPage2->PerformLayout();
						this->tabControl6->ResumeLayout(false);
						this->tabPage21->ResumeLayout(false);
						this->tabPage21->PerformLayout();
						this->tabControl5->ResumeLayout(false);
						this->tabPage15->ResumeLayout(false);
						this->panel15->ResumeLayout(false);
						this->panel15->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown59))->EndInit();
						this->tabPage17->ResumeLayout(false);
						this->panel3->ResumeLayout(false);
						this->panel3->PerformLayout();
						this->groupBox42->ResumeLayout(false);
						this->groupBox42->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar5))->EndInit();
						this->tabPage18->ResumeLayout(false);
						this->tabPage18->PerformLayout();
						this->tabPage19->ResumeLayout(false);
						this->groupBox3->ResumeLayout(false);
						this->groupBox3->PerformLayout();
						this->tabPage20->ResumeLayout(false);
						this->tabPage20->PerformLayout();
						this->tabControl4->ResumeLayout(false);
						this->tabPage8->ResumeLayout(false);
						this->panel4->ResumeLayout(false);
						this->groupBox19->ResumeLayout(false);
						this->groupBox20->ResumeLayout(false);
						this->groupBox20->PerformLayout();
						this->groupBox21->ResumeLayout(false);
						this->groupBox21->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown22))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown23))->EndInit();
						this->groupBox22->ResumeLayout(false);
						this->groupBox22->PerformLayout();
						this->groupBox23->ResumeLayout(false);
						this->groupBox23->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown24))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown25))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown26))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown27))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown28))->EndInit();
						this->groupBox24->ResumeLayout(false);
						this->groupBox24->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown29))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown30))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown31))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown32))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown33))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown34))->EndInit();
						this->groupBox18->ResumeLayout(false);
						this->groupBox18->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown19))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown20))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown21))->EndInit();
						this->groupBox17->ResumeLayout(false);
						this->groupBox17->PerformLayout();
						this->tabPage25->ResumeLayout(false);
						this->panel12->ResumeLayout(false);
						this->groupBox74->ResumeLayout(false);
						this->groupBox74->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown82))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown83))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown84))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown85))->EndInit();
						this->groupBox76->ResumeLayout(false);
						this->groupBox76->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown86))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown87))->EndInit();
						this->groupBox72->ResumeLayout(false);
						this->groupBox72->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown81))->EndInit();
						this->groupBox73->ResumeLayout(false);
						this->groupBox73->PerformLayout();
						this->groupBox71->ResumeLayout(false);
						this->groupBox71->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown79))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown80))->EndInit();
						this->groupBox68->ResumeLayout(false);
						this->groupBox68->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown77))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown78))->EndInit();
						this->groupBox67->ResumeLayout(false);
						this->groupBox67->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown76))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown75))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown74))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown73))->EndInit();
						this->tabControl3->ResumeLayout(false);
						this->tabPage9->ResumeLayout(false);
						this->tabPage9->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown69))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown35))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
						this->tabPage16->ResumeLayout(false);
						this->tabPage16->PerformLayout();
						this->tabPage5->ResumeLayout(false);
						this->tabPage5->PerformLayout();
						this->tabControl7->ResumeLayout(false);
						this->tabPage26->ResumeLayout(false);
						this->groupBox32->ResumeLayout(false);
						this->groupBox32->PerformLayout();
						this->groupBox31->ResumeLayout(false);
						this->groupBox31->PerformLayout();
						this->groupBox33->ResumeLayout(false);
						this->groupBox33->PerformLayout();
						this->tabPage27->ResumeLayout(false);
						this->panel14->ResumeLayout(false);
						this->panel14->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown88))->EndInit();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
						this->tabPage6->ResumeLayout(false);
						this->tabPage6->PerformLayout();
						this->groupBox58->ResumeLayout(false);
						this->groupBox58->PerformLayout();
						this->groupBox59->ResumeLayout(false);
						this->groupBox59->PerformLayout();
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown72))->EndInit();
						this->groupBox60->ResumeLayout(false);
						this->groupBox60->PerformLayout();
						this->groupBox61->ResumeLayout(false);
						this->groupBox61->PerformLayout();
						this->groupBox62->ResumeLayout(false);
						this->groupBox62->PerformLayout();
						this->tabControl2->ResumeLayout(false);
						this->tabPage3->ResumeLayout(false);
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
						this->tabPage4->ResumeLayout(false);
						this->panel13->ResumeLayout(false);
						this->groupBox70->ResumeLayout(false);
						this->groupBox70->PerformLayout();
						this->panel10->ResumeLayout(false);
						this->groupBox69->ResumeLayout(false);
						this->panel11->ResumeLayout(false);
						this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void MapBuilding_LM104_Load(System::Object^  sender, System::EventArgs^  e) {

}// private: System::Void MapBuilding_LM104_Load(System::Object^  sender, System::EventArgs^  e) {


private: System::Void DrawLines( )
{
	double R1=0;
	double R2=0;
	double R3=0;
	double R4=0;
	double R5=0;
	double R6=0;

 double coefX=0;
	double coefY=0;

	double doublePI = ( 2 * Math::PI );

//*****************************************************


	// DRAW Map matrix ? 
	if ( this->checkBox44->Checked == false ){
		  return;
	}// if 


					if ( g_PLBBitmap == nullptr ){
	   
				  		g_PLBBitmap = gcnew Bitmap(g_CFG_RobomapDirectory+"\\RES\\1136x836x24.bmp");
							
								g_G_PLB=Graphics::FromImage(g_PLBBitmap);
								g_G_PLB->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceOver;

								coefX = Convert::ToDouble( g_PLBBitmap->Width  - 1 ) / (g_globalPLBMaxX_XY-g_globalPLBMinX_XY);	
    	   coefY = Convert::ToDouble( g_PLBBitmap->Height - 1 ) / (g_globalPLBMaxY_XY-g_globalPLBMinY_XY);

        for each(c100LineItem^ i in g_LinesArray ){
 
            R1 = coefX * ( g_PLBMagnifierX * ( (safe_cast<c100LineItem^>(i)->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);

            R2 = coefY * ( g_PLBMagnifierY * ( (safe_cast<c100LineItem^>(i)->Y1-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2);

            R3 = coefX * ( g_PLBMagnifierX * ( (safe_cast<c100LineItem^>(i)->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);
   				   		
												R4 = coefY * ( g_PLBMagnifierY * ( (safe_cast<c100LineItem^>(i)->Y2-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2);

												R2 = (g_PLBBitmap->Height-1) - R2;
												R4 = (g_PLBBitmap->Height-1) - R4;

					   	   g_G_PLB->DrawLine( gs_Pen.RedPen2,   (float)( R1 ),
								  		                                     (float)( R2 ),
 									   					 									    			              (float)(	R3 ),
	 											    		 												                 (float)(	R4 ) ) ;

   					}//for each(cLineItem^ i in LinesArray ) 

						  if ( g_PLBBitmapDummy != nullptr ){
							    delete(g_PLBBitmapDummy);
											g_PLBBitmapDummy = nullptr;
						  }// if
						  if ( g_G_PLB != nullptr ){
 							  	delete(g_G_PLB);
           g_G_PLB = nullptr; 
					   }// if

								g_PLBBitmapDummy = dynamic_cast<System::Drawing::Bitmap^>(g_PLBBitmap->Clone());

 							g_G_PLB=Graphics::FromImage(g_PLBBitmapDummy);
								g_G_PLB->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceOver;

								this->pictureBox1->Image = dynamic_cast<Image^>(g_PLBBitmapDummy); 

        return;

					} else
				 {

								this->pictureBox1->Image = nullptr;

					   if ( g_PLBBitmapDummy != nullptr ){
							    delete(g_PLBBitmapDummy);
						  }// if
						  if ( g_G_PLB != nullptr ){
 							  	delete(g_G_PLB);
					   }// if

			   		g_PLBBitmapDummy = dynamic_cast<System::Drawing::Bitmap^>(g_PLBBitmap->Clone());

				    g_G_PLB=Graphics::FromImage(g_PLBBitmapDummy);
  	   	 g_G_PLB->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceOver;
   
		      this->pictureBox1->Image = dynamic_cast<Image^>(g_PLBBitmapDummy); 

					}// 	if (LSBitmap != nullptr )

	    this->pictureBox1->Refresh(); 

}// private: System::Void void DrawLines


private: System::Void DrawDsSample(UInt32 Item)
{

	Byte SwitchStatus = 0;

	double R1=0;
	double R2=0;
	double R3=0;
	double R4=0;
	double R5=0;

 double DsMinX_XY = 0;
 double DsMaxX_XY = 0;
 double DsMinY_XY = 0;
 double DsMaxY_XY = 0;

	double MinX_Polar = 0;
	double MaxX_Polar = 0;
	double MinY_Polar = 0;
	double MaxY_Polar = 0;

	double MinX_XY = 0;
	double MaxX_XY = 0;
	double MinY_XY = 0;
	double MaxY_XY = 0;

	UInt32 RI1 = 0;

 double coefX=0;
	double coefY=0;

	double coefLS=0;
	double coef2PIBeams = 0;
 
	double doublePI = ( 2 * Math::PI );

 //*****************************************

	
	    if (g_DsBitmap == nullptr ){

 							g_DsBitmap = gcnew Bitmap(g_CFG_RobomapDirectory+"\\RES\\490x297x24.bmp");
      		g_DsBitmapDummy = dynamic_cast<System::Drawing::Bitmap^>(g_DsBitmap->Clone());

						  g_G_Ds = Graphics::FromImage(g_DsBitmapDummy);
								g_G_Ds->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceOver;

 					  this->pictureBox2->Image = dynamic_cast<Image^>(g_DsBitmapDummy); 

					} else
					{

	  					this->pictureBox2->Image = nullptr;
 				 
						  if ( g_DsBitmapDummy != nullptr ){
							    delete(g_DsBitmapDummy);
						  }// if
						  if ( g_G_Ds != nullptr ){
 							  	delete(g_G_Ds);
					   }// if

								g_DsBitmapDummy = dynamic_cast<System::Drawing::Bitmap^>(g_DsBitmap->Clone());

				    g_G_Ds = Graphics::FromImage(g_DsBitmapDummy);
  	   	 g_G_Ds->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceOver;
   
		      this->pictureBox2->Image = dynamic_cast<Image^>(g_DsBitmapDummy); 
				 
					}// if (g_DsBitmap == nullptr )

			
					if ( this->radioButton8->Checked == true ){
						  SwitchStatus = 1;  // polar local
					} else if ( this->radioButton7->Checked == true ){
						  SwitchStatus = 2;  // Cartesian local 
					} else if ( this->radioButton6->Checked == true ){
						  SwitchStatus = 3;  // polar Y mirror
					} else
					{
						  SwitchStatus = 0;
					}// if

				
					switch ( SwitchStatus ) {
			      case 1: // polar local
										{

	         	coefX = Convert::ToDouble( g_DsBitmap->Width  - 1 ) / 
												       ( safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MaxX_Polar - safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinX_Polar );	
     	     coefY = Convert::ToDouble( g_DsBitmap->Height - 1 ) / 
												       ( safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MaxY_Polar - safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinY_Polar );	

           R3 = 0;
											for (UInt32 i=0;i<=Convert::ToUInt32( g_Ds_NumberOfBeams - 1 );i++){

      			   			R1 = ( coefX * ( g_DsMagnifier * (( R3 - safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinX_Polar ) - 
																    ((safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MaxX_Polar - safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinX_Polar)/2))) ) +
																    ( Convert::ToDouble( g_DsBitmap->Width  - 1 )/2);

   		      				R2 = (g_DsBitmap->Height - 1) - (
																    ( coefY * ( g_DsMagnifier * (( safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[i]->PolarLength - 
																			 safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinY_Polar ) -
																				((safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MaxY_Polar - safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinY_Polar)/2))) ) + 
																				( Convert::ToDouble( g_DsBitmap->Height - 1 )/2) );

															g_G_Ds->DrawEllipse(gs_Pen.GreenPen1, (float)( R1 ), (float)( R2 ), (float)3, (float)3);

							      		R3 = R3 + 1;

      				 }// for

											break;

									 }
		   	   case 2: // cartesian local
		       	{

           DsMinX_XY = safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinX_XY;
           DsMaxX_XY = safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MaxX_XY;
           DsMinY_XY = safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinY_XY;
           DsMaxY_XY = safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MaxY_XY;

    	      MinX_XY = +9999999;
	          MaxX_XY = -9999999;
	          MinY_XY = +9999999;
	          MaxY_XY = -9999999;

											for ( Int32 i=0; i < Convert::ToInt32( g_Ds_NumberOfBeams); i++ ){

										     if ( MinX_XY >	safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemXY[i]->X ){
   				           MinX_XY = safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemXY[i]->X;
			   		     	 }// if			 
						   					 if ( MaxX_XY <	safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemXY[i]->X ){
				              MaxX_XY = safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemXY[i]->X;
					     	    }// if		
											    if ( MinY_XY >	safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemXY[i]->Y ){
				              MinY_XY = safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemXY[i]->Y;
					     	    }// if			 
											    if ( MaxY_XY <	safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemXY[i]->Y ){
				              MaxY_XY = safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemXY[i]->Y;
					     	    }// if														   
												   
											}// for 

           DsMinX_XY = MinX_XY;
           DsMaxX_XY = MaxX_XY;
           DsMinY_XY = MinY_XY;
           DsMaxY_XY = MaxY_XY;

					      coefX = (Convert::ToDouble( g_DsBitmap->Width  - 1 ) ) / 
                   Math::Abs(DsMaxX_XY - DsMinX_XY);
      					coefY = (Convert::ToDouble( g_DsBitmap->Height - 1 ) ) / 
                    Math::Abs(DsMaxY_XY - DsMinY_XY);

           R3 = Convert::ToDouble( g_DsBitmapDummy->Width )/2;
           R4 = Convert::ToDouble( g_DsBitmapDummy->Height )/2;

											coefLS = ( g_Ds_DetectionAngle / ( g_Ds_NumberOfBeams - 1 ) );
        			coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );         // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
		
											for (UInt32 i=0;i<=Convert::ToUInt32( g_Ds_NumberOfBeams - 1 );i++){

												   R1 = safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemXY[i]->X;
															R2 = safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemXY[i]->Y - (Math::Abs(DsMaxY_XY - DsMinY_XY)/2);

 														R1 = g_DsMagnifier * (( R1 * coefX ) + R3 ); 
                  
   		      				R2 = (g_DsBitmap->Height - 1) - ( g_DsMagnifier * (( R2 * coefY ) + R4 ) );

															g_G_Ds->DrawEllipse(gs_Pen.GreenPen1, (float)( R1 ), (float)( R2 ), (float)(3), (float)(3) );

      				 }// for

           break;
			       } 
         case 3: // polar local Y mirror
										{

	         	coefX = Convert::ToDouble( g_DsBitmap->Width  - 1 ) / 
												       ( safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MaxX_Polar - safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinX_Polar );	
     	     coefY = Convert::ToDouble( g_DsBitmap->Height - 1 ) / 
												       ( safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MaxY_Polar - safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinY_Polar );	
					                
           R3 = 0;
											for (UInt32 i=0;i<=Convert::ToUInt32( g_Ds_NumberOfBeams - 1 );i++){

      			   			R1 = Convert::ToDouble( g_DsBitmap->Width  - 1 ) - ( 
																    ( coefX * ( g_DsMagnifier * (( R3 - safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinX_Polar ) - 
																    ((safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MaxX_Polar - safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinX_Polar)/2))) ) +
																    ( Convert::ToDouble( g_DsBitmap->Width  - 1 )/2) );

   		      				R2 = (g_DsBitmap->Height - 1) - (
																    ( coefY * ( g_DsMagnifier * (( safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[i]->PolarLength - 
																			 safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinY_Polar ) -
																				((safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MaxY_Polar - safe_cast<c104LSScan^>( g_DsLSArray[Item] )->MinY_Polar)/2))) ) + 
																				( Convert::ToDouble( g_DsBitmap->Height - 1 )/2) );

															g_G_Ds->DrawEllipse(gs_Pen.GreenPen1, (float)( R1 ), (float)( R2 ), (float)3, (float)3);

							      		R3 = R3 + 1;

      				 }// for

											break;

									 }										
			      default:
				      {
											MessageBox::Show( this, "ERROR in: [ private: System::Void DrawDsSample(...) ] ","LSB Drawing...", MessageBoxButtons::OK );
				       break;
					     }// default

					}// 	switch ( Status )

					this->pictureBox2->Refresh();

}// private: System::Void void DrawLSBSample


private: System::Void DrawState(UInt32 Item){
// Draw actual state at searching proces

	double doublePI = ( 2 * Math::PI );

	Byte SwitchStatus = 0;

	double R1=0;
	double R2=0;
	double R3=0;
	double R4=0;
	double R5=0;
 double R6=0;
 double R7=0;

	UInt32 RI1 = 0;

 double coefX=0;
	double coefY=0;

 double coefLS = 0;
	UInt32 coef2PIBeams = 0;
	UInt32	coefDmCount = 0;
 

//***************************************************


			   if ( Math::Abs( g_Ds_DetectionAngle - doublePI ) < 0.00001 ){

   			   coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
			      coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
			      coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081

			   } else
			   {
      			coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
			      coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
   			   coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081
   			}// if else

  	   coefX = Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 ) / Math::Abs(g_globalPLBMaxX_XY - g_globalPLBMinX_XY);	
      coefY = Convert::ToDouble( g_PLBBitmapDummy->Height - 1 ) / Math::Abs(g_globalPLBMaxY_XY - g_globalPLBMinY_XY);


						// Draw local scan over the map 
					 if ( this->checkBox26->Checked == true ){

			      for (UInt32 i=0;i<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );i++){
 
										   R7 = gs_RPose.Angle_RAD - (g_Ds_DetectionAngle/2);

				         R1 = gs_RPose.posX + ( 
						            ( ( safe_cast<c104LSScan^>(g_DsLSArray[Item])->LSItemXY[i]->X ) * Math::Cos( R7 )) - 
							           ( ( safe_cast<c104LSScan^>(g_DsLSArray[Item])->LSItemXY[i]->Y ) * Math::Sin( R7 )) );

   				      R2 = gs_RPose.posY + (  
			   		          ( ( safe_cast<c104LSScan^>(g_DsLSArray[Item])->LSItemXY[i]->X ) * Math::Sin( R7 )) + 
						  	         ( ( safe_cast<c104LSScan^>(g_DsLSArray[Item])->LSItemXY[i]->Y ) * Math::Cos( R7 )) );

			          R1 = coefX * ( g_PLBMagnifierX * ( (R1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
			 				          ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);
  
             R2 = ( g_PLBBitmap->Height-1) - ( coefY * ( g_PLBMagnifierY * ( (R2-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
	 			   			       ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2) );

													if ( g_RBeams[i] == true ){ // NO obstacle
						          if ( this->checkBox30->Checked == true ){
     			           g_G_PLB->DrawEllipse(gs_Pen.RedPen1, Convert::ToInt32( R1 ),
			   	                                                 Convert::ToInt32(	R2 ), 2,2);
																}// if 
													} else
													{
						          if ( this->checkBox34->Checked == true ){ // MOVING objects
     			           g_G_PLB->DrawEllipse(gs_Pen.BluePen2, Convert::ToInt32( R1 ),
			   	                                                  Convert::ToInt32(	R2 ), 2,2);
																}// if 
													}// if else

		       }// for
   

						}// if 

						// Obelize robot pose
						if ( this->checkBox32->Checked == true ){

         R1 = coefX * ( g_PLBMagnifierX * ( (gs_RPose.posX-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
 			          ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);

         R2 = ( g_PLBBitmap->Height-1) - ( coefY * ( g_PLBMagnifierY * ( (gs_RPose.posY-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
			   	       ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2) );

         g_G_PLB->DrawEllipse(gs_Pen.RedPen1, Convert::ToInt32( R1 ),
	                                        Convert::ToInt32(	R2 ), 4,4);

						}// if 



			        // Robot heading and triangle 
		         if ( this->checkBox31->Checked == true ){

	            	R1=0;
			 		        R2=0;

				          g_Triangle[0]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
 					        g_Triangle[0]->Y1 = R2 + (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
              g_Triangle[0]->X2 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					         g_Triangle[0]->Y2 = R2 - (g_PLBBitmapDummy->Height/g_vRobotMagnifier);

					         g_Triangle[1]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					         g_Triangle[1]->Y1 = R2 - (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
              g_Triangle[1]->X2 = R1 + (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					         g_Triangle[1]->Y2 = R2;

 					        g_Triangle[2]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					         g_Triangle[2]->Y1 = R2 + (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
              g_Triangle[2]->X2 = R1 + (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					         g_Triangle[2]->Y2 = R2;

              g_Triangle[3]->X1 = R1;
 					        g_Triangle[3]->Y1 = R2;
              g_Triangle[3]->X2 = R1 + (2*(g_PLBBitmapDummy->Width/g_vRobotMagnifier));
					         g_Triangle[3]->Y2 = R2;
		 
														R7 = gs_RPose.Angle_RAD; // 
					         for (int i=0;i<=3;i++){
 
                  R3 = g_Triangle[i]->X1;
		  					         R4 = g_Triangle[i]->Y1;
				  			         R5 = g_Triangle[i]->X2;
							           R6 = g_Triangle[i]->Y2;

							           g_Triangle[i]->X1 = ( (R3 * Math::Cos( R7 )) - 
																			                     (R4 * Math::Sin( R7 )));
							           g_Triangle[i]->Y1 = ( (R3 * Math::Sin( R7 )) + 
																			                     (R4 * Math::Cos( R7 )));
    
							           g_Triangle[i]->X2 = ( (R5 * Math::Cos( R7 )) - 
																			                     (R6 * Math::Sin( R7 )));
     		           g_Triangle[i]->Y2 = ( (R5 * Math::Sin( R7 )) + 
																			                     (R6 * Math::Cos( R7 )));
				
								        	 g_Triangle[i]->X1 =  g_Triangle[i]->X1 + gs_RPose.posX;  
 						           g_Triangle[i]->Y1 =  g_Triangle[i]->Y1 + gs_RPose.posY;
	 					           g_Triangle[i]->X2 =  g_Triangle[i]->X2 + gs_RPose.posX;
							           g_Triangle[i]->Y2 =  g_Triangle[i]->Y2 + gs_RPose.posY;

       			 	  }// for

  		        	 for (UInt32 i=0;i<=2;i++){
           
                  R1 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[i]->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
		   				 	            ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);

                  R2 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[i]->Y1-g_globalPLBMinY_XY) -
								        		     ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

                  R3 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[i]->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
								        	      ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);
    				   	 	
	  	     	        R4 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[i]->Y2-g_globalPLBMinY_XY) - 
										             ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );


										        //Console::WriteLine("R1 2 3 4 {0} {1} {2} {3}",R1,R2,R3,R4);

		   	            g_G_PLB->DrawLine( gs_Pen.BluePen1, (float)( R1 ),
 		                                              (float)( R2 ),
																														 									 	       (float)( R3 ),
 			    		 												                          (float)(	R4 ) ) ;
      
 		           }// for

		            R1 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[3]->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
					              ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);

              R2 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[3]->Y1-g_globalPLBMinY_XY) - 
						             ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

              R3 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[3]->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
				               ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);
   			   		
         					R4 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[3]->Y2-g_globalPLBMinY_XY) - 
						             ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

              g_G_PLB->DrawLine( gs_Pen.RedPen1, (float)( R1 ),
                                            (float)( R2 ),
				  																	          										 (float)( R3 ),
  		 	 											                          (float)(	R4 ) ) ;

											}// if 

											this->pictureBox1->Refresh();
											Application::DoEvents();

}// pprivate: System::Void DrawState(UInt32 Item){

private: System::Void DrawState_AllPoses(){
// Draw actual state at searching proces

	double doublePI = ( 2 * Math::PI );

	Byte SwitchStatus = 0;

	double R1=0;
	double R2=0;
	double R3=0;
	double R4=0;
	double R5=0;
 double R6=0;
 double R7=0;

	UInt32 RI1 = 0;

 double coefX=0;
	double coefY=0;

 double coefLS = 0;
	UInt32 coef2PIBeams = 0;
	UInt32	coefDmCount = 0;
 

//***************************************************


      //Console::WriteLine("Kresleni DrawState {0}",Item); 
			   if ( Math::Abs( g_Ds_DetectionAngle - doublePI ) < 0.00001 ){

   			   coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
			      coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
			      coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081

			   } else
			   {
      			coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
			      coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
   			   coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081
   			}// if else

  	   coefX = Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 ) / Math::Abs(g_globalPLBMaxX_XY - g_globalPLBMinX_XY);	
      coefY = Convert::ToDouble( g_PLBBitmapDummy->Height - 1 ) / Math::Abs(g_globalPLBMaxY_XY - g_globalPLBMinY_XY);

						for ( Int32 k=0;k < g_FoundedPositions->Count; k++ ){ 

			       // Draw local scan over the map 
						    if ( this->checkBox26->Checked == true ){

		           coefX = Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 ) / (g_globalPLBMaxX_XY - g_globalPLBMinX_XY);	
             coefY = Convert::ToDouble( g_PLBBitmapDummy->Height - 1 ) / (g_globalPLBMaxY_XY - g_globalPLBMinY_XY);

			          for (UInt32 i=0;i<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );i++){
 

																	R1 = safe_cast<c104FoundPosition^>(g_FoundedPositions[k])->LSItemDfXY[i]->X;
																	R2 = safe_cast<c104FoundPosition^>(g_FoundedPositions[k])->LSItemDfXY[i]->Y;

			              R1 = coefX * ( g_PLBMagnifierX * ( (R1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
			 				              ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);
  
                 R2 = ( g_PLBBitmap->Height-1) - ( coefY * ( g_PLBMagnifierY * ( (R2-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
	 		    	   			       ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2) );


													if ( safe_cast<c104FoundPosition^>(g_FoundedPositions[k])->Obstacle[i]->Obstacle == false ){ // NO obstacle
						          if ( this->checkBox30->Checked == true ){
     			           g_G_PLB->DrawEllipse(gs_Pen.RedPen1, Convert::ToInt32( R1 ),
			   	                                                 Convert::ToInt32(	R2 ), 2,2);
																}// if 
													} else
													{
						          if ( this->checkBox34->Checked == true ){ // MOVING objects
     			           g_G_PLB->DrawEllipse(gs_Pen.BluePen1, Convert::ToInt32( R1 ),
			   	                                                  Convert::ToInt32(	R2 ), 2,2);
																}// if 
													}// if else


		           }// for

						    }// if 

						    // Obelize robot pose
						    if ( this->checkBox32->Checked == true ){

											  R1 = safe_cast<c104FoundPosition^>(g_FoundedPositions[k])->PosX; 
											  R2 = safe_cast<c104FoundPosition^>(g_FoundedPositions[k])->PosY;

             R1 = coefX * ( g_PLBMagnifierX * ( (R1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
 			              ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);

             R2 = ( g_PLBBitmap->Height-1) - ( coefY * ( g_PLBMagnifierY * ( (R2-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
			   	           ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2) );

             g_G_PLB->DrawEllipse(gs_Pen.RedPen1, Convert::ToInt32( R1 ),
	                                                 Convert::ToInt32(	R2 ), 4,4);

						    }// if 



			        // Robot heading and triangle 
		         if ( this->checkBox31->Checked == true ){

	            	R1=0;
			 		        R2=0;

				          g_Triangle[0]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
 					        g_Triangle[0]->Y1 = R2 + (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
              g_Triangle[0]->X2 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					         g_Triangle[0]->Y2 = R2 - (g_PLBBitmapDummy->Height/g_vRobotMagnifier);

					         g_Triangle[1]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					         g_Triangle[1]->Y1 = R2 - (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
              g_Triangle[1]->X2 = R1 + (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					         g_Triangle[1]->Y2 = R2;

 					        g_Triangle[2]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					         g_Triangle[2]->Y1 = R2 + (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
              g_Triangle[2]->X2 = R1 + (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					         g_Triangle[2]->Y2 = R2;

              g_Triangle[3]->X1 = R1;
 					        g_Triangle[3]->Y1 = R2;
              g_Triangle[3]->X2 = R1 + (2*(g_PLBBitmapDummy->Width/g_vRobotMagnifier));
					         g_Triangle[3]->Y2 = R2;
		 
														R7 = safe_cast<c104FoundPosition^>(g_FoundedPositions[k])->Angle; // >PosX; gs_RPose.Angle_RAD; // - (g_Ds_DetectionAngle/2);
					         for (int i=0;i<=3;i++){
 
                  R3 = g_Triangle[i]->X1;
		  					         R4 = g_Triangle[i]->Y1;
				  			         R5 = g_Triangle[i]->X2;
							           R6 = g_Triangle[i]->Y2;

							           g_Triangle[i]->X1 = ( (R3 * Math::Cos( R7 )) - 
																			                     (R4 * Math::Sin( R7 )));
							           g_Triangle[i]->Y1 = ( (R3 * Math::Sin( R7 )) + 
																			                     (R4 * Math::Cos( R7 )));
    
							           g_Triangle[i]->X2 = ( (R5 * Math::Cos( R7 )) - 
																			                     (R6 * Math::Sin( R7 )));
     		           g_Triangle[i]->Y2 = ( (R5 * Math::Sin( R7 )) + 
																			                     (R6 * Math::Cos( R7 )));
				
								        	 g_Triangle[i]->X1 =  g_Triangle[i]->X1 + safe_cast<c104FoundPosition^>(g_FoundedPositions[k])->PosX; 
 						           g_Triangle[i]->Y1 =  g_Triangle[i]->Y1 + safe_cast<c104FoundPosition^>(g_FoundedPositions[k])->PosY; 
	 					           g_Triangle[i]->X2 =  g_Triangle[i]->X2 + safe_cast<c104FoundPosition^>(g_FoundedPositions[k])->PosX; 
							           g_Triangle[i]->Y2 =  g_Triangle[i]->Y2 + safe_cast<c104FoundPosition^>(g_FoundedPositions[k])->PosY; 

       			 	  }// for

  		        	 for (UInt32 i=0;i<=2;i++){
           
                  R1 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[i]->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
		   				 	            ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);

                  R2 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[i]->Y1-g_globalPLBMinY_XY) -
								        		     ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

                  R3 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[i]->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
								        	      ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);
    				   	 	
	  	     	        R4 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[i]->Y2-g_globalPLBMinY_XY) - 
										             ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );


		   	            g_G_PLB->DrawLine( gs_Pen.BluePen1, (float)( R1 ),
 		                                                   (float)( R2 ),
																														 									 	            (float)( R3 ),
 			    		 												                               (float)(	R4 ) ) ;
      
 		           }// for

		            R1 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[3]->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
					              ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);

              R2 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[3]->Y1-g_globalPLBMinY_XY) - 
						             ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

              R3 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[3]->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
				               ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);
   			   		
         					R4 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[3]->Y2-g_globalPLBMinY_XY) - 
						             ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

              g_G_PLB->DrawLine( gs_Pen.RedPen1, (float)( R1 ),
                                                 (float)( R2 ),
				  																	          									     	 (float)( R3 ),
  		 	 											                               (float)(	R4 ) ) ;

											}// if 

						}// for 

						this->pictureBox1->Refresh();

}// private: System::Void DrawState_AllPoses(){


private: System::Void DrawPopulation(){
// Draws actual state at searching proces

	double doublePI = ( 2 * Math::PI );

	Byte SwitchStatus = 0;

	double R1=0;
	double R2=0;
	double R3=0;
	double R4=0;
	double R5=0;
 double R6=0;
 double R7=0;

	UInt32 RI1 = 0;

 double coefX=0;
	double coefY=0;

 double coefLS = 0;
	UInt32 coef2PIBeams = 0;
	UInt32	coefDmCount = 0;


	//************************************

	          if ( Math::Abs( g_Ds_DetectionAngle - doublePI ) < 0.00001 ){

   	 				     coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
	  	    	     coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
  			         coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081

											} else
											{
      	 				  coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
	     	    	  coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
  			         coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081
											}// if else

  	        coefX = Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 ) / Math::Abs(g_globalPLBMaxX_XY - g_globalPLBMinX_XY);	
           coefY = Convert::ToDouble( g_PLBBitmapDummy->Height - 1 ) / Math::Abs(g_globalPLBMaxY_XY - g_globalPLBMinY_XY);

			        // draw every population

														this->pictureBox1->Image = nullptr;

      					   if ( g_PLBBitmapDummy != nullptr ){
						           delete(g_PLBBitmapDummy);
						        }// if
						        if ( g_G_PLB != nullptr ){
 							  	      delete(g_G_PLB);
					         }// if

      			   		g_PLBBitmapDummy = dynamic_cast<System::Drawing::Bitmap^>(g_PLBBitmap->Clone());
   
			      	    g_G_PLB = Graphics::FromImage(g_PLBBitmapDummy);
  	   	       g_G_PLB->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceOver;
   
		            this->pictureBox1->Image = dynamic_cast<Image^>(g_PLBBitmapDummy); 

			           for ( UInt32 i=0;i<Convert::ToUInt32(g_Population->Count);i++){

					             R1 = safe_cast<c104PopItem^>(g_Population[i])->Xdec - (0.5*g_GA_AreaWidth)  + gs_RPose.posX;
					             R2 = safe_cast<c104PopItem^>(g_Population[i])->Ydec - (0.5*g_GA_AreaHeight) + gs_RPose.posY;

                  R1 = ( coefX * ( g_PLBMagnifierX * ( (R1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
											            ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2) );

                  R2 = ( coefY * ( g_PLBMagnifierY * ( (R2-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
											            ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2) );

																		R2 = (g_PLBBitmap->Height-1) - R2;

																		g_G_PLB->DrawEllipse(gs_Pen.BlackPen2, (float)( R1 ), (float)(	R2 ), (float)( 3 ), (float)( 3 ));

		            }// for

												this->pictureBox1->Refresh();

}// private: System::Void DrawPopulation(){


private: System::Void DrawGlobalMap( )
{
	double R1=0;
	double R2=0;
	double R3=0;
	double R4=0;
	double R5=0;
	double R6=0;

 double coefX=0;
	double coefY=0;

	double doublePI = ( 2 * Math::PI );

//*****************************************************


					if ( g_PLBBitmap == nullptr ){
						  return;
					}// if

								this->pictureBox1->Image = nullptr;

					   if ( g_PLBBitmapDummy != nullptr ){
							    delete(g_PLBBitmapDummy);
						  }// if
						  if ( g_G_PLB != nullptr ){
 							  	delete(g_G_PLB);
					   }// if

			   		g_PLBBitmapDummy = dynamic_cast<System::Drawing::Bitmap^>(g_PLBBitmap->Clone());

				    g_G_PLB=Graphics::FromImage(g_PLBBitmapDummy);
								g_G_PLB->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceCopy; // ::SourceOver;
   
		      this->pictureBox1->Image = dynamic_cast<Image^>(g_PLBBitmapDummy); 

	   
				   	coefX = Convert::ToDouble( g_PLBBitmap->Width  - 1 ) / (g_globalPLBMaxX_XY-g_globalPLBMinX_XY);	
    	   coefY = Convert::ToDouble( g_PLBBitmap->Height - 1 ) / (g_globalPLBMaxY_XY-g_globalPLBMinY_XY);


        for each(c100LineItem^ i in g_GlobalMap ){
 
            R1 = coefX * ( g_PLBMagnifierX * ( (safe_cast<c100LineItem^>(i)->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);

            R2 = coefY * ( g_PLBMagnifierY * ( (safe_cast<c100LineItem^>(i)->Y1-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2);

            R3 = coefX * ( g_PLBMagnifierX * ( (safe_cast<c100LineItem^>(i)->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);
   				   		
												R4 = coefY * ( g_PLBMagnifierY * ( (safe_cast<c100LineItem^>(i)->Y2-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2);

												R2 = (g_PLBBitmap->Height-1) - R2;
												R4 = (g_PLBBitmap->Height-1) - R4;



												g_G_PLB->DrawLine( gs_Pen.BlackPen3, (float)( R1 ),
								  		                                     (float)( R2 ),
 									   					 									    			              (float)(	R3 ),
																																																	(float)(	R4 ) );  

												// show small circles at begina and End of line of GM
												if ( this->checkBox33->Checked == true ){
												   g_G_PLB->DrawEllipse( gs_Pen.GrayPen1,(float)( R1 ), (float)( R2 ),(float)3,(float)3); 
												   g_G_PLB->DrawEllipse( gs_Pen.GrayPen1,(float)( R3 ), (float)( R4 ),(float)3,(float)3); 
												}// if 



   					}//for each(cLineItem^ i in g_LocalMap ) 


	    this->pictureBox1->Refresh(); 

}// private: System::Void void DrawGlobalMap

private: System::Void DrawLocalMap( )
{
	double R1=0;
	double R2=0;
	double R3=0;
	double R4=0;
	double R5=0;
	double R6=0;

 double coefX=0;
	double coefY=0;

	double doublePI = ( 2 * Math::PI );

//*****************************************************

	
    
					if ( g_PLBBitmap == nullptr ){
						  return;
					}// if
	   
				   	coefX = Convert::ToDouble( g_PLBBitmap->Width  - 1 ) / (g_globalPLBMaxX_XY-g_globalPLBMinX_XY);	
    	   coefY = Convert::ToDouble( g_PLBBitmap->Height - 1 ) / (g_globalPLBMaxY_XY-g_globalPLBMinY_XY);


        for each(c100LineItem^ i in g_LocalMap ){
 
            R1 = coefX * ( g_PLBMagnifierX * ( (safe_cast<c100LineItem^>(i)->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);

            R2 = coefY * ( g_PLBMagnifierY * ( (safe_cast<c100LineItem^>(i)->Y1-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2);

            R3 = coefX * ( g_PLBMagnifierX * ( (safe_cast<c100LineItem^>(i)->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);
   				   		
												R4 = coefY * ( g_PLBMagnifierY * ( (safe_cast<c100LineItem^>(i)->Y2-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2);

												R2 = (g_PLBBitmap->Height-1) - R2;
												R4 = (g_PLBBitmap->Height-1) - R4;


												if ( safe_cast<c100LineItem^>(i)->Tag == 1 ){

					   	      g_G_PLB->DrawLine( gs_Pen.RedPen2 , (float)( R1 ),
								  		                                       (float)( R2 ),
 									   					    									    			             (float)(	R3 ),
	 											    		 	   											                (float)(	R4 ) ) ;
												} else if ( safe_cast<c100LineItem^>(i)->Tag == 2 )
												{

					   	      g_G_PLB->DrawLine( gs_Pen.DarkOrangePen2, (float)( R1 ),
								  		                                            (float)( R2 ),
 									   					    									    			                  (float)(	R3 ),
	 											    		 	   											                     (float)(	R4 ) ) ;
												} else if ( safe_cast<c100LineItem^>(i)->Tag == 3 )
												{
					   	      g_G_PLB->DrawLine( gs_Pen.BluePen2, (float)( R1 ),
								  		                                            (float)( R2 ),
 									   					    									    			                  (float)(	R3 ),
	 											    		 	   											                     (float)(	R4 ) ) ;
												} else if ( safe_cast<c100LineItem^>(i)->Tag == 4 )
												{
					   	      g_G_PLB->DrawLine( gs_Pen.FuchsiaPen2, (float)( R1 ),
								  		                                            (float)( R2 ),
 									   					    									    			                  (float)(	R3 ),
	 											    		 	   											                     (float)(	R4 ) ) ;
												}// if else


   					}//for each(cLineItem^ i in g_LocalMap ) 


	    this->pictureBox1->Refresh(); 

}// private: System::Void void DrawLocalMap


private: System::Void DrawTemporaryMap( )
{
	double R1=0;
	double R2=0;
	double R3=0;
	double R4=0;
	double R5=0;
	double R6=0;

 double coefX=0;
	double coefY=0;

	double doublePI = ( 2 * Math::PI );

//*****************************************************

    
					if ( g_PLBBitmap == nullptr ){
						  return;
					}// if
	   
				   	coefX = Convert::ToDouble( g_PLBBitmap->Width  - 1 ) / (g_globalPLBMaxX_XY-g_globalPLBMinX_XY);	
    	   coefY = Convert::ToDouble( g_PLBBitmap->Height - 1 ) / (g_globalPLBMaxY_XY-g_globalPLBMinY_XY);

        for each(c100LineItem^ i in g_TemporaryMap ){
 
            R1 = coefX * ( g_PLBMagnifierX * ( (safe_cast<c100LineItem^>(i)->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);

            R2 = coefY * ( g_PLBMagnifierY * ( (safe_cast<c100LineItem^>(i)->Y1-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2);

            R3 = coefX * ( g_PLBMagnifierX * ( (safe_cast<c100LineItem^>(i)->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);
   				   		
												R4 = coefY * ( g_PLBMagnifierY * ( (safe_cast<c100LineItem^>(i)->Y2-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
													    ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2);

												R2 = (g_PLBBitmap->Height-1) - R2;
												R4 = (g_PLBBitmap->Height-1) - R4;

					   	   g_G_PLB->DrawLine( gs_Pen.DarkOrangePen2, (float)( R1 ),
								  		                                          (float)( R2 ),
 									  			    									    			                   (float)(	R3 ),
	 										  		 	   											                      (float)(	R4 ) ) ;

   					}//for each(c100LineItem^ i in g_TemporaryMap ) 

        this->pictureBox1->Refresh(); 

}// private: System::Void DrawTemporaryMap( )


private: System::Void button25_Click(System::Object^  sender, System::EventArgs^  e) {
// DRAW ALL SCANS 

	 const double doublePI = Math::PI * 2;

   double R1 = 0;
   double R2 = 0;
   double R3 = 0;
   double R4 = 0;
   double R5 = 0;
   double R6 = 0;
   double R7 = 0;

			UInt32 RI1 = 0;

   double coefX = 0;
   double coefY = 0;

			double coefLS = 0;
			double coef2PIBeams = 0;

//**********************************************


			  if ( g_FoundedPositions->Count == 0 ){
						  return;
					}//


						this->pictureBox1->Image = nullptr;

				  if ( g_PLBBitmapDummy != nullptr ){
					    delete(g_PLBBitmapDummy);
									g_PLBBitmapDummy = nullptr;
				  }// if
						if ( g_G_PLB != nullptr ){
 							 delete(g_G_PLB);
									g_G_PLB = nullptr;
					 }// if

	     g_PLBBitmapDummy = dynamic_cast<System::Drawing::Bitmap^>(g_PLBBitmap->Clone());

		    g_G_PLB = Graphics::FromImage(g_PLBBitmapDummy);
	   	 g_G_PLB->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceOver;

		    this->pictureBox1->Image = dynamic_cast<Image^>(g_PLBBitmapDummy); 


						if ( Math::Abs( g_Ds_DetectionAngle - doublePI ) < 0.00001 ){
   						coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
			   			coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    
						} else
						{
   						coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
			   			coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    
						}// if else


		  	 coefX = Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 ) / (g_globalPLBMaxX_XY-g_globalPLBMinX_XY);	
    	 coefY = Convert::ToDouble( g_PLBBitmapDummy->Height - 1 ) / (g_globalPLBMaxY_XY-g_globalPLBMinY_XY);

				 
					for (UInt32 h=0;h<Convert::ToUInt32( g_FoundedPositions->Count );h++){

         // draw scan points
         R7 = safe_cast<c104FoundPosition^>(g_FoundedPositions[ h ])->Angle; 
			      for (Int32 i=0;i<Convert::ToInt32( safe_cast<c104FoundPosition^>(g_FoundedPositions[ h ])->LSItemDfXY->Length);i++){

					        R1 = safe_cast<c104FoundPosition^>(g_FoundedPositions[ h ])->LSItemDfXY[i]->X; 
		 			       R2 = safe_cast<c104FoundPosition^>(g_FoundedPositions[ h ])->LSItemDfXY[i]->Y; 

			          R1 = coefX * ( g_PLBMagnifierX * ( (R1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
			 				          ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);

             R2 = (g_PLBBitmap->Height-1) - ( coefY * ( g_PLBMagnifierY * ( (R2-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
	 	   					       ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2) );

										   // draw obstacle
							      if ( this->checkBox37->Checked == true ){ 
											     if ( safe_cast<c104FoundPosition^>(g_FoundedPositions[ h ])->Obstacle[i]->Obstacle == true ){ 
  			              g_G_PLB->DrawEllipse(gs_Pen.RedPen2, Convert::ToInt32( R1 ),
				                                               Convert::ToInt32(	R2 ), 3,3);
										      }// if 
										   }// if  

										   // draw beam
										   if ( this->checkBox38->Checked == true ){ 
	               if ( safe_cast<c104FoundPosition^>(g_FoundedPositions[ h ])->Obstacle[i]->Obstacle == false ){ 
     			           g_G_PLB->DrawEllipse(gs_Pen.BluePen1, Convert::ToInt32( R1 ),
			   	                                             Convert::ToInt32(	R2 ), 2,2);
										      }// if 
										   }// if 

   		   }// for i

 
      // DRAW ROBOT
      if ( this->checkBox50->Checked == true ){ 

   	 			R1=0;
			   		R2=0;

				    g_Triangle[0]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
 					  g_Triangle[0]->Y1 = R2 + (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
        g_Triangle[0]->X2 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					   g_Triangle[0]->Y2 = R2 - (g_PLBBitmapDummy->Height/g_vRobotMagnifier);

					   g_Triangle[1]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					   g_Triangle[1]->Y1 = R2 - (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
        g_Triangle[1]->X2 = R1 + (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					   g_Triangle[1]->Y2 = R2;

 					  g_Triangle[2]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					   g_Triangle[2]->Y1 = R2 + (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
        g_Triangle[2]->X2 = R1 + (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					   g_Triangle[2]->Y2 = R2;

        g_Triangle[3]->X1 = R1;
 					  g_Triangle[3]->Y1 = R2;
        g_Triangle[3]->X2 = R1 + (2*(g_PLBBitmapDummy->Width/g_vRobotMagnifier));
					   g_Triangle[3]->Y2 = R2;
		 
        R7 = safe_cast<c104FoundPosition^>(g_FoundedPositions[ h ])->Angle; //- (g_Ds_DetectionAngle/2); 
					   for (int i=0;i<=3;i++){

            R3 = g_Triangle[i]->X1;
  		  					 R4 = g_Triangle[i]->Y1;
				  			   R5 = g_Triangle[i]->X2;
							     R6 = g_Triangle[i]->Y2;

							     g_Triangle[i]->X1 = ((R3 * Math::Cos( R7 )) - (R4 * Math::Sin( R7 )));
							     g_Triangle[i]->Y1 = ((R3 * Math::Sin( R7 )) + (R4 * Math::Cos( R7 )));
    
							     g_Triangle[i]->X2 = ((R5 * Math::Cos( R7 )) - (R6 * Math::Sin( R7 )));
     		     g_Triangle[i]->Y2 = ((R5 * Math::Sin( R7 )) + (R6 * Math::Cos( R7 )));
				
									   g_Triangle[i]->X1 =  g_Triangle[i]->X1 + safe_cast<c104FoundPosition^>(g_FoundedPositions[ h ])->PosX;  
 						     g_Triangle[i]->Y1 =  g_Triangle[i]->Y1 + safe_cast<c104FoundPosition^>(g_FoundedPositions[ h ])->PosY;  
	 					     g_Triangle[i]->X2 =  g_Triangle[i]->X2 + safe_cast<c104FoundPosition^>(g_FoundedPositions[ h ])->PosX;    
							     g_Triangle[i]->Y2 =  g_Triangle[i]->Y2 + safe_cast<c104FoundPosition^>(g_FoundedPositions[ h ])->PosY;    

 			 	  }// for

  			   for (UInt32 i=0;i<=2;i++){
          
            R1 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[i]->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
		   				   	    ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);

            R2 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[i]->Y1-g_globalPLBMinY_XY) -
										       ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

            R3 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[i]->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
									        ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);
    				   	 	
  	  	     	R4 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[i]->Y2-g_globalPLBMinY_XY) - 
		  								     ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

		   	      g_G_PLB->DrawLine( gs_Pen.BluePen1, (float)( R1 ),
 		                                        (float)( R2 ),
														  																 								 	(float)( R3 ),
 			    		 					  							                  (float)(	R4 ) ) ;
 		    }// for

		     R1 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[3]->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
					       ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);

       R2 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[3]->Y1-g_globalPLBMinY_XY) - 
						      ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

       R3 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[3]->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
				        ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);
   			   		
					  R4 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[3]->Y2-g_globalPLBMinY_XY) - 
						      ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

       g_G_PLB->DrawLine( gs_Pen.RedPen1, (float)( R1 ),
                                     (float)( R2 ),
				  			  																									 (float)( R3 ),
  		 	 				  							                 (float)(	R4 ) ) ;


					}// for h

      }// if kresli robot

     this->pictureBox1->Refresh(); 

}// private: System::Void button25_Click



private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
// Open PLB file

BinaryReader^ binReader = nullptr;
OpenFileDialog^ openFileDialog1 = nullptr;

double R1 = 0;
double R2 = 0;
double R3 = 0;
double R4 = 0;
double R5 = 0;
double R6 = 0;

//********************************

 	    openFileDialog1 = gcnew OpenFileDialog;

      openFileDialog1->InitialDirectory = "c:\\";
      openFileDialog1->Filter = "plb files (*.PLB;*.plb)|*.PLB;*.plb|All files (*.*)|*.*";
      openFileDialog1->FilterIndex = 1;
      openFileDialog1->RestoreDirectory = true;

      if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
      {
						  	this->textBox1->Text = openFileDialog1->FileName;
									gs_PLBFile.FileName = openFileDialog1->FileName;
         gs_PLBFile.Opened = true;

      } else
						{
						  	delete( openFileDialog1 );
							  return;
						}// if

			
      {

							 try
        {

           binReader = gcnew BinaryReader( File::Open( openFileDialog1->FileName , FileMode::Open ) );

									  g_PLBNumberOfLines = binReader->ReadUInt32();

           g_globalPLBMinX_XY = binReader->ReadDouble();
           g_globalPLBMaxX_XY = binReader->ReadDouble();
           g_globalPLBMinY_XY = binReader->ReadDouble();
           g_globalPLBMaxY_XY = binReader->ReadDouble();

											for (UInt32 i=0;i<=Convert::ToUInt32(g_PLBNumberOfLines-1);i++){
 
												  ROBOMAP::c100LineItem^ LineItem = gcnew c100LineItem();

														LineItem->X1 = binReader->ReadDouble();
			           LineItem->Y1 = binReader->ReadDouble();
			           LineItem->X2 = binReader->ReadDouble();
			           LineItem->Y2 = binReader->ReadDouble();

														LineItem->diffX  = ( LineItem->X2 - LineItem->X1 );
														LineItem->diffY  = ( LineItem->Y1 - LineItem->Y2 );
														LineItem->LengthSQR = Math::Pow( (LineItem->X2 - LineItem->X1),2 ) +  Math::Pow( (LineItem->Y2 - LineItem->Y1),2 );
														LineItem->Length = Math::Sqrt( LineItem->LengthSQR ); 

														LineItem->u1 = ( LineItem->X2 - LineItem->X1 );
														LineItem->u2 = ( LineItem->Y2 - LineItem->Y1 );

              if (	LineItem->X1 > LineItem->X2 ){
															  LineItem->Wx1 = LineItem->X2; 
                 LineItem->Wx2 = LineItem->X1; 
																	LineItem->Wx1 = LineItem->Wx1 - g_WindowTolerance; 
                 LineItem->Wx2 = LineItem->Wx2 + g_WindowTolerance; 
														} else
												 	{
															  LineItem->Wx1 = LineItem->X1; 
                 LineItem->Wx2 = LineItem->X2; 
																	LineItem->Wx1 = LineItem->Wx1 - g_WindowTolerance; 
                 LineItem->Wx2 = LineItem->Wx2 + g_WindowTolerance; 
              }// if else
														if (	LineItem->Y1 > LineItem->Y2 ){
																	LineItem->Wy1 = LineItem->Y2; 
                 LineItem->Wy2 = LineItem->Y1;
																	LineItem->Wy1 = LineItem->Wy1 - g_WindowTolerance; 
                 LineItem->Wy2 = LineItem->Wy2 + g_WindowTolerance;
									    	} else
														{
																	LineItem->Wy1 = LineItem->Y1; 
                 LineItem->Wy2 = LineItem->Y2;
																	LineItem->Wy1 = LineItem->Wy1 - g_WindowTolerance; 
                 LineItem->Wy2 = LineItem->Wy2 + g_WindowTolerance;
														}// if else

														LineItem->a2 = LineItem->Y1 - LineItem->Y2; 
														LineItem->b2 = LineItem->X2 - LineItem->X1;
														LineItem->c2 = (LineItem->X1*LineItem->Y2)-(LineItem->X2*LineItem->Y1); 

														LineItem->a1 = LineItem->Y1 - LineItem->Y2; 
														LineItem->b1 = LineItem->X2 - LineItem->X1;
														LineItem->c1 = (LineItem->X1*LineItem->Y2)-(LineItem->X2*LineItem->Y1); 

														g_LinesArray->Add(LineItem);

											}// for
									  
        }
								catch( Exception^ err )
								{
						   MessageBox::Show( this, "Error at PLB file reading: "+err->Message,"Error in PLF file...", MessageBoxButtons::OK ); 
								}
        finally
        {
           binReader->Close();
        }
        
      }// if


						if ( ( g_globalPLBMinX_XY != Math::Abs( g_globalPLBMinX_XY ) ) ||
							    ( g_globalPLBMaxX_XY != Math::Abs( g_globalPLBMaxX_XY ) ) ||
											( g_globalPLBMinY_XY != Math::Abs( g_globalPLBMinY_XY ) ) ||
											( g_globalPLBMaxY_XY != Math::Abs( g_globalPLBMaxY_XY ) ) ){

          MessageBox::Show( this, "Map must be in first quadrant for EA computation.","Error in data file...", MessageBoxButtons::OK ); 
						}//

			   //g_vRobotMagnifier = (g_PLBBitmap->Width/13);

						if ( (g_globalPLBMaxX_XY-g_globalPLBMinX_XY) >= (g_globalPLBMaxY_XY-g_globalPLBMinY_XY) ){
         g_PLBMagnifierX = g_PLBMagnifierZoom * 1;
         g_PLBMagnifierY = g_PLBMagnifierZoom * ( (g_globalPLBMaxY_XY-g_globalPLBMinY_XY) / (g_globalPLBMaxX_XY-g_globalPLBMinX_XY) );
						} else
						{
							  g_PLBMagnifierX = g_PLBMagnifierZoom * ( (g_globalPLBMaxX_XY-g_globalPLBMinX_XY) / (g_globalPLBMaxY_XY-g_globalPLBMinY_XY) );
									g_PLBMagnifierY = g_PLBMagnifierZoom * 1;
						} // if else 

						this->textBox11->Text = Convert::ToString( Math::Round( g_globalPLBMinX_XY ) ); 
						this->textBox12->Text = Convert::ToString( Math::Round( g_globalPLBMinY_XY ) ); 
						this->textBox13->Text = Convert::ToString( Math::Round( g_globalPLBMaxX_XY ) ); 
						this->textBox14->Text = Convert::ToString( Math::Round( g_globalPLBMaxY_XY ) ); 

						Application::DoEvents();

						this->button1->Enabled = false;
						this->button2->Enabled = true;

					 DrawLines();

					 //g_PLBOpened = true;

						delete( openFileDialog1 );
						delete( binReader );
				
}// private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
// Open LSB file

									
	double MinX_Polar = 0;
	double MaxX_Polar = 0;
	double MinY_Polar = 0;
	double MaxY_Polar = 0;

	double MinX_XY = 0;
	double MaxX_XY = 0;
	double MinY_XY = 0;
	double MaxY_XY = 0;
 
	double R1=0;
	double R2=0;
	double R3=0;
	double R4=0;
	double R5=0;

	double coefLS = 0;

	BinaryReader^ binReader = nullptr;

//************************************************


      OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

      openFileDialog1->InitialDirectory = "c:\\";
      openFileDialog1->Filter = "lsb files (*.LSB;*.lsb)|*.LSB;*.lsb|All files (*.*)|*.*";
      openFileDialog1->FilterIndex = 1;
      openFileDialog1->RestoreDirectory = true;

      if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
      {
						  	this->textBox2->Text = openFileDialog1->FileName;
									gs_LSBFile.FileName = openFileDialog1->FileName;
									gs_LSBFile.Opened = true;

         this->label2->Text = Path::GetFileName( gs_LSBFile.FileName ); 
									delete( openFileDialog1 );
      } else
						{
  							delete( openFileDialog1 );
		  					return;
						}// if



    try
			 {

      binReader = gcnew BinaryReader( File::Open( gs_LSBFile.FileName, FileMode::Open ) );

						this->toolStripProgressBar1->Maximum = Convert::ToInt32( binReader->BaseStream->Length ); 
						this->toolStripProgressBar1->Minimum = 0;

      g_Ds_NumberOfScans  = binReader->ReadUInt32();
      g_Ds_NumberOfBeams  = binReader->ReadUInt16();
						g_Ds_DetectionAngle = binReader->ReadDouble();

	     g_DsMinX_Polar = binReader->ReadDouble();
						g_DsMaxX_Polar = binReader->ReadDouble();
      g_DsMinY_Polar = binReader->ReadDouble();
						g_DsMaxY_Polar = binReader->ReadDouble();

      g_DsMinX_XY = binReader->ReadDouble();
						g_DsMaxX_XY = binReader->ReadDouble();
						g_DsMinY_XY = binReader->ReadDouble();
						g_DsMaxY_XY = binReader->ReadDouble();

 		
						for (UInt32 i=0;i<=Convert::ToUInt32( g_Ds_NumberOfScans - 1 );i++){

										this->toolStripProgressBar1->Value = Convert::ToInt32( binReader->BaseStream->Position );

						   	ROBOMAP::c104LSScan^ LSScan = gcnew c104LSScan( Convert::ToUInt16( g_Ds_NumberOfBeams ) );

									 MinX_Polar = +9999999;
    	     MaxX_Polar = -9999999;
	         MinY_Polar = +9999999;
	         MaxY_Polar = -9999999;

    	     MinX_XY = +9999999;
	         MaxX_XY = -9999999;
	         MinY_XY = +9999999;
	         MaxY_XY = -9999999;

										coefLS = ( g_Ds_DetectionAngle ) / Convert::ToDouble( g_Ds_NumberOfBeams-1 );
         	
          for (UInt32 j=0;j<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );j++){

            	 LSScan->LSItemPolar[j] = gcnew c104LSItemPolar();

											   LSScan->LSItemPolar[j]->PolarLength = binReader->ReadDouble();

												  if ( MinX_Polar >	j ){
				             MinX_Polar =	j;
					     	   }// if			
											   if ( MaxX_Polar <	j ){
				             MaxX_Polar =	j;
					     	   }// if	
    							   if ( MinY_Polar >	LSScan->LSItemPolar[j]->PolarLength  ){
   				          MinY_Polar =	LSScan->LSItemPolar[j]->PolarLength;
			   		     	}// if			
						   					if ( MaxY_Polar <	LSScan->LSItemPolar[j]->PolarLength ){
				             MaxY_Polar =	LSScan->LSItemPolar[j]->PolarLength;
					     	   }// if	

		           	LSScan->LSItemXY[j] = gcnew c104LSItemXY();
		           	LSScan->LSItemXYrot[j] = gcnew c104LSItemXY();


											   LSScan->LSItemXY[j]->X = Math::Cos(coefLS*Convert::ToDouble(j)) * LSScan->LSItemPolar[j]->PolarLength;
											   LSScan->LSItemXY[j]->Y = Math::Sin(coefLS*Convert::ToDouble(j)) * LSScan->LSItemPolar[j]->PolarLength;

		
										    if ( MinX_XY >	LSScan->LSItemXY[j]->X ){
   				          MinX_XY = LSScan->LSItemXY[j]->X;
			   		     	}// if			 
						   					if ( MaxX_XY <	LSScan->LSItemXY[j]->X ){
				             MaxX_XY = LSScan->LSItemXY[j]->X;
					     	   }// if		
											   if ( MinY_XY >	LSScan->LSItemXY[j]->Y ){
				             MinY_XY = LSScan->LSItemXY[j]->Y;
					     	   }// if			 
											   if ( MaxY_XY <	LSScan->LSItemXY[j]->Y ){
				             MaxY_XY = LSScan->LSItemXY[j]->Y;
					     	   }// if		
                     
          }//  for (UInt32 j=0;j<=Convert::ToUInt32( g_NumberOfBeams-1 );j++)


										LSScan->RHeadX = Math::Abs( MinX_XY );
          LSScan->RHeadY = Math::Abs( MinY_XY );


          LSScan->MinX_XY = MinX_XY;
							   LSScan->MaxX_XY = MaxX_XY;
							   LSScan->MinY_XY = MinY_XY;
							   LSScan->MaxY_XY = MaxY_XY;
							
	         LSScan->MinX_Polar = MinX_Polar;
	         LSScan->MaxX_Polar = MaxX_Polar;
							   LSScan->MinY_Polar = MinY_Polar;
	         LSScan->MaxY_Polar = MaxY_Polar;
	   
						    g_DsLSArray->Add(LSScan); //*****************************************

			       this->listBox1->SelectedIndexChanged -= gcnew System::EventHandler(this, &MapBuilding_LM104::listBox1_SelectedIndexChanged);

   							this->listBox1->Items->Add("LS: " + Convert::ToString(i)+
		    					                          "  C minXY[" + Convert::ToInt32(MinX_XY).ToString() + 
			 		  			                          "," + Convert::ToInt32(MinY_XY).ToString() +
				 			   																										"],maxXY[" + Convert::ToInt32(MaxX_XY).ToString() +
					 					   																							"," + Convert::ToInt32(MaxY_XY).ToString() + "] " +
						 							   																				"P minXY[" + Convert::ToInt32(MinX_Polar).ToString() +
							 									   																	"," + Convert::ToInt32(MinY_Polar).ToString() +
								 											   														"],maxXY[" + Convert::ToUInt32(MaxX_Polar).ToString() +
									 													   											"," + Convert::ToInt32(MaxY_Polar).ToString() + "] " );
	
			       this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MapBuilding_LM104::listBox1_SelectedIndexChanged);

      }// 	for (UInt32 i=1;i<=Convert::ToUInt32( g_NumberOfScans - 1 );i++){


				  this->label188->Text = "[ Number of samples: " + Convert::ToString(g_Ds_NumberOfScans) + " ] ";

			 		this->textBox22->Text = Convert::ToString( Math::Round( g_DsMinX_Polar ));
						this->textBox21->Text = Convert::ToString( Math::Round( g_DsMinY_Polar ));
						this->textBox20->Text = Convert::ToString( Math::Round( g_DsMaxX_Polar ));
						this->textBox19->Text = Convert::ToString( Math::Round( g_DsMaxY_Polar ));

     	this->textBox16->Text = Convert::ToString( Math::Round( g_DsMinX_XY ));
						this->textBox18->Text = Convert::ToString( Math::Round( g_DsMinY_XY ));
						this->textBox17->Text = Convert::ToString( Math::Round( g_DsMaxX_XY ));
						this->textBox15->Text = Convert::ToString( Math::Round( g_DsMaxY_XY ));


     }
     catch( Exception^ err )
					{
					 	MessageBox::Show( this, "Error at LSB file reading: "+err->Message,"Error in LSB file...", MessageBoxButtons::OK ); 
					}
     finally
     {
        binReader->Close();
     }

					this->toolStripProgressBar1->Maximum = 100;
					this->toolStripProgressBar1->Minimum = 0;
					this->toolStripProgressBar1->Value = 0;
					
 				if ( gs_PLBFile.Opened == true ){
        this->tabPage2->Enabled = true; 
        this->tabPage5->Enabled = true; 
        this->tabPage6->Enabled = true; 
					}// if 

			  this->button2->Enabled = false;  // LSB open button

					this->listBox1->SelectedIndex = (0); 

					this->label81->Text = "Start sample: 0";

					DrawDsSample( this->listBox1->SelectedIndex );

  	  delete(binReader);

}// private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
// Define PTH file


cLSTechInfo^ LSTechInfo = nullptr;

//********************************

       if ( gs_PLBFile.Opened == false || gs_PLBFile.FileName == "" ){
          MessageBox::Show( this, "PLB file name must be defined first.","Error in order.", MessageBoxButtons::OK ); 
          return;
       }// if 

						SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

						saveFileDialog1->CreatePrompt = true;
      saveFileDialog1->OverwritePrompt = true;
				  saveFileDialog1->FileName = Path::GetFileNameWithoutExtension(gs_PLBFile.FileName)+"_dsmae3";
      saveFileDialog1->DefaultExt = "pth";
						saveFileDialog1->FilterIndex = 1;
      saveFileDialog1->Filter = "pth files (*.PTH;*.pth)|*PTH;*.pth|All files (*.*)|*.*";   
      saveFileDialog1->InitialDirectory = "c:\\";

      System::Windows::Forms::DialogResult result = saveFileDialog1->ShowDialog();


      if ( result == ::DialogResult::OK )
      {

							LSTechInfo = gcnew cLSTechInfo();

							gs_PTHFile.FileName = saveFileDialog1->FileName;
							gs_PTHFile.Opened = true;

							this->textBox3->Text = saveFileDialog1->FileName; 

      }// if

						delete ( saveFileDialog1 );

						this->checkBox36->Checked = true; // write data to PTH file 

						delete( LSTechInfo );

}// private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
// Define TXT file

BinaryWriter^ binWriter;

//*********************************************

					if ( gs_PTHFile.Opened == false ){
							  MessageBox::Show( this, "PTH file name must be defined first.", "TXT file saving.", MessageBoxButtons::OK ); 
									return; 
						}// if

						SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

						saveFileDialog1->CreatePrompt = true;
      saveFileDialog1->OverwritePrompt = true;
     
				  saveFileDialog1->FileName = Path::GetFileNameWithoutExtension(gs_LSBFile.FileName)+"_dsmae3";

      saveFileDialog1->DefaultExt = "txt";
						saveFileDialog1->FilterIndex = 1;
      saveFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";   
      saveFileDialog1->InitialDirectory = "c:\\";

      System::Windows::Forms::DialogResult result = saveFileDialog1->ShowDialog();


      if ( result == ::DialogResult::OK )
      {
							cLSTechInfo^ LSTechInfo = gcnew cLSTechInfo();

							gs_TXTFile.FileName = saveFileDialog1->FileName;
							gs_TXTFile.Opened = true;
							this->textBox4->Text = saveFileDialog1->FileName; 

							try
        {

									 binWriter = gcnew BinaryWriter( File::Open( saveFileDialog1->FileName , FileMode::Create ) );

        }
								catch(...)
								{
									MessageBox::Show( this, "Error at TXT file opening: ","TXT file opening.", MessageBoxButtons::OK ); 
								}
        finally
        {
           binWriter->Close();
											
        }
								delete ( LSTechInfo );

        
      }// if
						delete ( saveFileDialog1 );


}// private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
// Define other autosave files directory

						SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

						saveFileDialog1->CreatePrompt = true;
      saveFileDialog1->OverwritePrompt = true;
     
				  saveFileDialog1->FileName = "scrn";

      saveFileDialog1->DefaultExt = "jpg";
		  		saveFileDialog1->FilterIndex = 1;
      saveFileDialog1->Filter = "jpg files (*.jpg)|*.jpg|All files (*.*)|*.*";   
      saveFileDialog1->InitialDirectory = "c:\\";

      System::Windows::Forms::DialogResult result = saveFileDialog1->ShowDialog();

      if ( result == ::DialogResult::OK )
      {

							gs_AutoSave.DirectoryOrFileName = saveFileDialog1->FileName;
 						gs_AutoSave.Opened = true;
							this->textBox5->Text = saveFileDialog1->FileName; 
							
      }// if

						delete ( saveFileDialog1 );

}// private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {


private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
// Define VRX file

}// private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {

private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
// Auto fill up all
// FILL UP ALL Info BUTTON

       if ( gs_PTHFile.Opened == false || gs_PTHFile.FileName == "" ){
          MessageBox::Show( this, "Points file name must be defined first.","Error in order.", MessageBoxButtons::OK ); 
          return;
       }// if 
           
       // but22
							gs_TXTFile.FileName = Path::GetDirectoryName( gs_PTHFile.FileName ) + "\\" + Path::GetFileNameWithoutExtension(gs_PLBFile.FileName)+"_dsmae3.txt";
							gs_TXTFile.Opened = true;
							this->textBox4->Text = gs_TXTFile.FileName; 

       // but29
							gs_AutoSave.DirectoryOrFileName = Path::GetDirectoryName( gs_PTHFile.FileName ) + "\\" + Path::GetFileNameWithoutExtension(gs_PLBFile.FileName)+"scrn.jpg";
							gs_AutoSave.Opened = true;
							this->textBox5->Text = gs_AutoSave.DirectoryOrFileName; 

}// private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
// RESET FILES


									this->label2->Text = "-";
									this->label188->Text = "[ Number of samples: ]"; 

         this->textBox1->Text = ""; 
         this->textBox2->Text = "";
         this->textBox3->Text = "";
         this->textBox4->Text = "";
         this->textBox5->Text = "";

         this->label84->Text = "Position: ";
         this->label84->Refresh(); 

					    this->label87->Text = "Generation:";
							  this->label87->Refresh(); 

	        this->label86->Text = "Algorithm:";
							  this->label86->Refresh(); 

	        this->label85->Text = "Optimum:";
							  this->label85->Refresh(); 

         this->button9->Text = "START SEARCHING"; 

   					 this->label88->Text = "Start / StopTime: ";

									this->label83->Text = "Actual sample: ";
							  this->label83->Refresh(); 

		       this->button1->Enabled = true;           // PLB
			      this->button2->Enabled = false;          // LSB

        this->tabPage2->Enabled = false; 
        this->tabPage5->Enabled = false; 
        this->tabPage6->Enabled = false; 

			 	this->richTextBox1->Text = "";

					this->button3->Enabled = true;   // reset file ON


					if ( g_FoundedPositions->Count != 0 ){ 

										   for (UInt32 i=0;i<=Convert::ToUInt32( g_FoundedPositions->Count - 1 );i++){

													   	for (UInt32 j=0;j<=Convert::ToUInt32( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDsPolar->Length-1 );j++){
															      delete( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDsPolar[j] );
														   }//for 
										       for (UInt32 j=0;j<=Convert::ToUInt32( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDsXY->Length-1 );j++){
															      delete( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDsXY[j] );
														   }// for

										       for (UInt32 j=0;j<=Convert::ToUInt32( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDfXY->Length-1 );j++){
															      delete( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDfXY[j] );
														   }// for

										       for (UInt32 j=0;j<Convert::ToUInt32( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->Obstacle->Length );j++){
															      delete( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->Obstacle[j] );
														   }// for

														   delete( safe_cast<c104FoundPosition^>(g_FoundedPositions[i]) );

										   }// for

										   g_FoundedPositions->Clear(); 

						}// if 

        if ( gs_PLBFile.Opened == true ){

  								for each(c100LineItem^ i in g_LinesArray ){
              delete( safe_cast<c100LineItem^>(i) );
										}// for
										g_LinesArray->Clear(); 

							}// if 
							gs_PLBFile.Opened = false;

       if ( gs_LSBFile.Opened == true ){     
								  for (UInt32 i=0;i<=(g_Ds_NumberOfScans-1);i++){
	               
                 for (UInt16 j=0;j<=(g_Ds_NumberOfBeams-1);j++){

                     delete( safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]  );
																					delete( safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemXY[j]  );

																	}// for
																	delete( safe_cast<c104LSScan^>( g_DsLSArray[i] )  );
										}// for 
	
										g_Ds_NumberOfScans  = 0;
          g_Ds_NumberOfBeams  = 0;
						    g_Ds_DetectionAngle = 0;

										g_DsLSArray->Clear();

							}// if
							gs_LSBFile.Opened = false;


      this->pictureBox1->Image = nullptr;
			   this->pictureBox2->Image = nullptr;
			
			   Application::DoEvents(); 

			   if ( g_PLBBitmap != nullptr ){
 			     delete( g_PLBBitmap );
		 			   g_PLBBitmap = nullptr;
		    }// if
	     if ( g_PLBBitmapDummy != nullptr ){
		       delete( g_PLBBitmapDummy );
				     g_PLBBitmapDummy = nullptr;
		    }// if
			   if ( g_G_PLB != nullptr ){
		       delete( g_G_PLB );
				     g_G_PLB = nullptr;
		    }// if

   			if ( g_DsBitmap != nullptr ){
 		   	  delete( g_DsBitmap );
   		 			g_DsBitmap = nullptr;
   		 }// if
   	  if ( g_DsBitmapDummy != nullptr ){
		       delete( g_DsBitmapDummy );
   						g_DsBitmapDummy = nullptr;
   		 }// if
			   if ( g_G_Ds != nullptr ){
   		    delete( g_G_Ds );
				     g_G_Ds = nullptr;
		    }// if

     	this->tabPage2->Enabled = false; 
      this->tabPage5->Enabled = false; 
   			this->tabPage6->Enabled = false; 

							gs_PTHFile.Opened = false;
							gs_PLBFile.Opened = false;
							gs_LSBFile.Opened = false;
							gs_TXTFile.Opened = false;
							gs_AutoSave.Opened = false;
								
    			gs_PLBFile.FileName = "";
			    gs_LSBFile.FileName = "";
			    gs_PTHFile.FileName = "";
			    gs_TXTFile.FileName = "";			
			    gs_AutoSave.DirectoryOrFileName = "";		

							this->textBox11->Text = ""; 
							this->textBox12->Text = "";
							this->textBox13->Text = "";
							this->textBox14->Text = "";

							this->textBox18->Text = ""; 
							this->textBox17->Text = "";
							this->textBox16->Text = "";
							this->textBox15->Text = "";

							this->textBox22->Text = ""; 
							this->textBox21->Text = "";
							this->textBox20->Text = "";
							this->textBox19->Text = "";

							this->numericUpDown1->Value = 0; 
							this->numericUpDown2->Value = 0;
							this->numericUpDown69->Value = 0;

       this->comboBox13->SelectedIndex = 0; 

      this->listBox1->Items->Clear(); // clear list of found positions 
      this->listBox2->Items->Clear(); // clear list of found positions 

      this->pictureBox1->Image = nullptr;

   			Application::DoEvents(); 

						//DrawLines();


}// private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
// LSB list of scans 

										if ( gs_LSBFile.Opened == false ){
											  return;
										}// if
										DrawDsSample( Convert::ToUInt32( this->listBox1->SelectedIndex ) );
										this->label81->Text = "Start sample: "+Convert::ToString(this->listBox1->SelectedIndex);   

}// private: System::Void listBox1_SelectedIndexChanged


private: System::Double rad2deg_rounded(double value){

const double doublePI = Math::PI * 2;

	   value = value - ( doublePI * Math::Truncate( value / doublePI ) );
    value = Math::Round( ( 360 / doublePI ) * value ); 

				return value;
									
}// private: System::double rad2deg(double value)

private: System::Double rad2deg(double value){

const double doublePI = Math::PI * 2;

	   value = value - ( doublePI * Math::Truncate( value / doublePI ) );
    value = ( ( 360 / doublePI ) * value ); 

				return value;
									
}// private: System::double deg2rad(double value)

private: System::Double deg2rad_double(double value){

const double doublePI = Math::PI * 2;

    if ( value > 360 ){
				 	 value = value - ( Math::Truncate( value/360 )*360 );
    }// if 
	   value = ( doublePI/360 ) * value; 
    
				return value;
									
}// private: System::double deg2rad(double value

private: System::Void SetPriority(ProcessPriorityClass p) {
//  Process.GetCurrentProcess().PriorityClass 

										switch( p ){
											case ProcessPriorityClass::Idle:
												{
													g_Process->PriorityClass = ProcessPriorityClass::Idle; 
													this->label168->Text = "Priority Idle"; 
													this->trackBar5->Value = 1; 
													break;
    								}
											case ProcessPriorityClass::BelowNormal:
												{
													g_Process->PriorityClass = ProcessPriorityClass::BelowNormal; 
													this->label168->Text = "Priority BelowNormal";  
													this->trackBar5->Value = 2; 
													break;
												}
											case ProcessPriorityClass::Normal:
												{
													g_Process->PriorityClass = ProcessPriorityClass::Normal; 
													this->label168->Text = "Priority Normal";  
													this->trackBar5->Value = 3; 
													break;
												}
           case ProcessPriorityClass::AboveNormal:
												{
													g_Process->PriorityClass = ProcessPriorityClass::AboveNormal; 
													this->label168->Text = "Priority AboveNormal";  
													this->trackBar5->Value = 4; 
													break;
												}
											case ProcessPriorityClass::High:
												{
													g_Process->PriorityClass = ProcessPriorityClass::High; 
													this->label168->Text = "Priority High";  
													this->trackBar5->Value = 5; 
													break;
												}
											case ProcessPriorityClass::RealTime:
												{
													g_Process->PriorityClass = ProcessPriorityClass::RealTime; 
													this->label168->Text = "Priority RealTime";  
													this->trackBar5->Value = 6; 
													break;
												}
											default:
												{
													break;
												}
										}// switch

          this->label168->Refresh(); 
		
}// private: System::Void SetPriority(ProcessPriorityClass p)


private: System::Void trackBar5_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
//  Process.GetCurrentProcess().PriorityClass 

System::Windows::Forms::DialogResult result;

//******************************************

								switch( this->trackBar5->Value ){
											case 1:
												{
													this->label168->Text = "Priority Idle";  
													break;
    								}
											case 2:
												{
													this->label168->Text = "Priority BelowNormal";  
													break;
												}
											case 3:
												{
													this->label168->Text = "Priority Normal";  
													break;
												}
           case 4:
												{
													this->label168->Text = "Priority AboveNormal";  
													break;
												}
											case 5:
												{
													this->label168->Text = "Priority High";  
													break;
												}
											case 6:
												{
										   this->label168->Text = "Priority RealTime";  
													break;
												}
											default:
												{
													break;
												}
										}// switch


          this->label168->Refresh(); 

										switch( this->trackBar5->Value ){
											case 1:
												{
													g_Process->PriorityClass = ProcessPriorityClass::Idle; 
													this->label168->Text = "Priority Idle";  
													break;
    								}
											case 2:
												{
													g_Process->PriorityClass = ProcessPriorityClass::BelowNormal; 
													this->label168->Text = "Priority BelowNormal";  
													break;
												}
											case 3:
												{
													g_Process->PriorityClass = ProcessPriorityClass::Normal; 
													this->label168->Text = "Priority Normal";  
													break;
												}
           case 4:
												{
													g_Process->PriorityClass = ProcessPriorityClass::AboveNormal; 
													this->label168->Text = "Priority AboveNormal";  
													break;
												}
											case 5:
												{
													g_Process->PriorityClass = ProcessPriorityClass::High; 
													this->label168->Text = "Priority High";  
													break;
												}
											case 6:
												{
					     			result = MessageBox::Show( this, "Do you really want RealTime priority ?", "Process...", MessageBoxButtons::YesNo );
			     		 		if ( result == ::DialogResult::Yes ){
                Application::DoEvents(); 
													   g_Process->PriorityClass = ProcessPriorityClass::RealTime; 
													   this->label168->Text = "Priority RealTime";  
     								} else
					     			{
													   g_Process->PriorityClass = ProcessPriorityClass::Normal; 
													   this->label168->Text = "Priority Normal";  
													   this->trackBar5->Value = 3;  
								     }// if
													break;
												}
											default:
												{
													break;
												}
										}// switch

          this->label168->Refresh(); 

}// private: System::Void trackBar5_ValueChanged





private: System::Void GA_1stCreatePopulation(){

 double R1=0;
	double R2=0;
 double R3=0;
	double R4=0;
	double R5=0;
	double R6=0;
 double R7=0;
	double R8=0;

	Byte RB1 = 0;
	Byte RB2 = 0;

	Int32 RI1=0;
	Int32 RI2=0;
	Int32 RI3=0;
	Int32 RI4=0;

	Random^ random = nullptr;

	//***********************************************


	// way of creation
	switch ( g_WayOfCreation ){
			case 0: // random generator c++ .NET
				{
	
 						random = gcnew Random();

						 // number of individuals in population
							for ( Int32 i = 0;i < Convert::ToInt32( g_GA_NumberOfIndividuals );i++){

   								c104PopItem^ PItem = gcnew c104PopItem();
				
											Monitor::Enter(random);
											PItem->Xdec = random->Next( Convert::ToInt32( 0 ), Convert::ToInt32( g_GA_AreaWidth   ) );
											PItem->Ydec = random->Next( Convert::ToInt32( 0 ), Convert::ToInt32( g_GA_AreaHeight  ) );
											Monitor::Exit(random);

											PItem->Fitness = g_paramFitnessLimit;
           g_Population->Add(PItem);
 			
							}// for i 

			   	// Create only ONE individuum with N-dimensional vector
							c104PopItem^ PItem = gcnew c104PopItem();
							g_paramLastBestDecVec->Add( PItem ); 

				   safe_cast<c104PopItem^>(g_paramLastBestDecVec[0])->Xdec =  safe_cast<c104PopItem^>(g_Population[0])->Xdec;
 			   safe_cast<c104PopItem^>(g_paramLastBestDecVec[0])->Ydec =  safe_cast<c104PopItem^>(g_Population[0])->Ydec;
							
							g_paramLastBestFitness = g_paramFitnessLimit; 

							delete( random );

 				  break;
				}
   
			default:
				{
					MessageBox::Show( this, "Unexpected Event. PopulationCreation.", "Suspicious ...", MessageBoxButtons::OK );
					break;
				}
	}// switch 

}// private: System::Void GA_CreatePopulation()


private: System::Void GA_1stCrossoverAndMutation(){

 double R1=0;
	double R2=0;
		
	Int32 RI1 = 0;
	Int32 RI2 = 0;
	Int32 RI3 = 0;
	Int32 RI4 = 0;
	Int32 RI5 = 0;

 Random^ random = nullptr;

 //	1:1,2 2:1,2,3 3:1,2 4:1,2,3,4 5:1,2,3,4,5 6:1,2 7:1,2,3 8:1,2 9: 1,2,3,4 10:1,2,3,4,5

//***********************************************

      random = gcnew Random();

						// for all N(POPsel) do
						for ( Int32 i=0;i<Convert::ToInt32( g_GA_NumberOfIndividuals );i++){

			       do 
   							{
			   			   Monitor::Enter(random); 
						 		   RI1 = random->Next(0, g_GA_NumberOfIndividuals );
											 Monitor::Exit(random); 
							   } while ( RI1 == i ); 
          do 
			   				{
						 			  Monitor::Enter(random); 
							  	  RI2 = random->Next(0, g_GA_NumberOfIndividuals );
							     Monitor::Exit(random); 
							   } while ( ( RI2 == i ) || ( RI2 == RI1 ) );
										if ( ( g_GA_SelectedAlgorithm == 2 ) || 
											    ( g_GA_SelectedAlgorithm == 4 ) || 
															( g_GA_SelectedAlgorithm == 5 ) || 
															( g_GA_SelectedAlgorithm == 7 ) ||
										     ( g_GA_SelectedAlgorithm == 9 ) ||
										     ( g_GA_SelectedAlgorithm == 10 ) ){
             do 
 			  							{
						   				  Monitor::Enter(random); 
									   	  RI3 = random->Next(0, g_GA_NumberOfIndividuals );
   										  Monitor::Exit(random); 
			   							} while ( ( RI3 == i ) || ( RI3 == RI2 ) || ( RI3 == RI1 ) );
										}// if 
										if ( ( g_GA_SelectedAlgorithm == 4 ) || 
											    ( g_GA_SelectedAlgorithm == 5 ) || 
															( g_GA_SelectedAlgorithm == 9 ) || 
															( g_GA_SelectedAlgorithm == 10 ) ){
             do 
										   {
										     Monitor::Enter(random); 
										     RI4 = random->Next(0, g_GA_NumberOfIndividuals );
										     Monitor::Exit(random); 
										   } while ( ( RI4 == i ) || ( RI4 == RI3 ) || ( RI4 == RI3 ) || ( RI4 == RI1 ));
										}// if 
										if ( ( g_GA_SelectedAlgorithm == 5 ) || 
											    ( g_GA_SelectedAlgorithm == 10 ) ){ 
             do 
			   							{
						   				  Monitor::Enter(random); 
									   	  RI5 = random->Next(0, g_GA_NumberOfIndividuals );
   										  Monitor::Exit(random); 
			   							} while ( ( RI5 == i ) && ( RI5 == RI4 ) || ( RI5 == RI3 ) || ( RI5 == RI2 ) || ( RI5 == RI1 ) );
										}// if 
          

          // Create only ONE individuum with N-dimensional vector
							   c104PopItem^ PItem = gcnew c104PopItem();
							   PItem->Xdec = safe_cast<c104PopItem^>(g_Population[i])->Xdec;
							   PItem->Ydec = safe_cast<c104PopItem^>(g_Population[i])->Ydec;
          g_trialSolutionInd->Add( PItem ); 

          //*************************************************************
										// DE Rand1Exp  perturbation vector

					    	Monitor::Enter(random); 
			       R1 = random->NextDouble(); 
		        Monitor::Exit(random); 

										if ( R1 < g_paramCrossProbability ){

    						   safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Xdec = safe_cast<c104PopItem^>(g_Population[RI1])->Xdec + 
   				    			                                                      g_paramF * ( safe_cast<c104PopItem^>(g_Population[RI2])->Xdec - 
			   					  																																																							             safe_cast<c104PopItem^>(g_Population[RI3])->Xdec );
									 }// if 

 					   	Monitor::Enter(random); 
	 				    R1 = random->NextDouble(); 
						    Monitor::Exit(random); 

										if ( R1 < g_paramCrossProbability ){

				  				   safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Ydec = safe_cast<c104PopItem^>(g_Population[RI1])->Ydec + 
						     			                                                      g_paramF * ( safe_cast<c104PopItem^>(g_Population[RI2])->Ydec - 
											  																																																							             safe_cast<c104PopItem^>(g_Population[RI3])->Ydec );
									 }// if
          //*************************************************************


          // Evaluate trial Individuum, Fitness ulozi do [ safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Fitness ]
          //**********************************************************
				      EvaluatePopulationTrial( g_ActualLSScan );
          //**********************************************************
          R1 = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Fitness;

										// Find BEST IND and FIT due tue Searching Alg.
										if ( g_SearchingAlgorithm == 0 ){ // SMALLEST DS/MAE, 
             
			   							if ( R1 < g_paramLastBestFitness ){

                g_paramLastBestFitness = R1;

						   				   safe_cast<c104PopItem^>(g_paramLastBestDecVec[0])->Xdec = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Xdec;
										      safe_cast<c104PopItem^>(g_paramLastBestDecVec[0])->Ydec = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Ydec;
										  
             }// if

										   if ( R1 <= safe_cast<c104PopItem^>(g_Population[i])->Fitness ){

   													safe_cast<c104PopItem^>(g_Population[i])->Xdec = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Xdec;
			   										safe_cast<c104PopItem^>(g_Population[i])->Ydec = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Ydec;

						   							safe_cast<c104PopItem^>(g_Population[i])->Fitness = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Fitness;
						   							//safe_cast<c104PopItem^>(g_Population[i])->Fitness2nd = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Fitness2nd;
 												   safe_cast<c104PopItem^>(g_Population[i])->Angle = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Angle;

													} //else

										} else
										{

			   							if ( R1 > g_paramLastBestFitness ){

                g_paramLastBestFitness = R1;

									   				safe_cast<c104PopItem^>(g_paramLastBestDecVec[0])->Xdec = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Xdec;
													   safe_cast<c104PopItem^>(g_paramLastBestDecVec[0])->Ydec = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Ydec;
										  
										   }// if

										   if ( R1 >= safe_cast<c104PopItem^>(g_Population[i])->Fitness ){ // BIGGEST 

   													safe_cast<c104PopItem^>(g_Population[i])->Xdec = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Xdec;
			   										safe_cast<c104PopItem^>(g_Population[i])->Ydec = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Ydec;

						   							safe_cast<c104PopItem^>(g_Population[i])->Fitness = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Fitness;
						   							//safe_cast<c104PopItem^>(g_Population[i])->Fitness2nd = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Fitness2nd;
 												   safe_cast<c104PopItem^>(g_Population[i])->Angle = safe_cast<c104PopItem^>(g_trialSolutionInd[0])->Angle;
													} //else

										}// if else

          delete( safe_cast<c104PopItem^>(g_trialSolutionInd[0]) );
										g_trialSolutionInd->Clear(); 

 					}// for i

  				delete( random );

}// private: System::Void GA_Crossover()

private: System::Void GA_1stPostprocessing(){

 double R1=0;

	Random^ random = nullptr;

	//***********************************************


		   // Automatic 1st Postprocessing - Check for outer region
	    random = gcnew Random();

					// Check for OUTER regions
  			for (Int32 i=0;i<Convert::ToInt32( g_Population->Count );i++){

						   if ( safe_cast<c104PopItem^>(g_Population[i])->Xdec < 0 ||
		   					    safe_cast<c104PopItem^>(g_Population[i])->Xdec > g_GA_AreaWidth ||
					   						safe_cast<c104PopItem^>(g_Population[i])->Ydec < 0 ||
								   			safe_cast<c104PopItem^>(g_Population[i])->Ydec > g_GA_AreaHeight ){

				          Monitor::Enter(random);
											   safe_cast<c104PopItem^>(g_Population[i])->Xdec = random->Next( Convert::ToInt32( 0 ), Convert::ToInt32( g_GA_AreaWidth ) );
				          safe_cast<c104PopItem^>(g_Population[i])->Ydec = random->Next( Convert::ToInt32( 0 ), Convert::ToInt32( g_GA_AreaHeight ) );
														safe_cast<c104PopItem^>(g_Population[i])->Angle = (gs_RPose.Angle_RAD); // predtim bylo 0
				          Monitor::Exit(random);

              safe_cast<c104PopItem^>(g_Population[i])->Fitness = g_paramFitnessLimit;


									}// if 

					}//	for (Int32 i=0;i<Convert::ToInt32( g_Population->Count );i++)

	    delete(random);

}// private: System::Void GA_Postprocessing()


private: System::Void GA_1stDeletePopulation(){
// delete used populaton

	      for ( UInt32 i=0;i<Convert::ToUInt32(g_Population->Count);i++){
 	         delete( safe_cast<c104PopItem^>(g_Population[i]) );
	      }// for 
       g_Population->Clear(); 								

       delete( safe_cast<c104PopItem^>(g_paramLastBestDecVec[0]) );							
							g_paramLastBestDecVec->Clear(); 

}// private: System::Void GA_1stDeletePopulation() 

private: System::Byte EvaluatePopulation(UInt32 Item) {
// compute starting position

  	const double doublePI = Math::PI * 2;

   double coefLS = 0;
			UInt32 coef2PIBeams = 0;
			UInt32	coefDmCount = 0;

			double R1=0;
  	double R2=0;
	  double R3=0;
	  double R4=0;
	  double R5=0;
		 double R6=0;
			double R7=0;
			double R8=0;
			double R9=0;
			double R10=0;
			double R11=0;
			double R12=0;
			double R13=0;

			UInt32 RI1=0;
			UInt32 RI2=0;

			double xp=0;
			double yp=0;

			double Lsmin=0;
			double Ls=0;
			double ABDet;
			double t=0;

   double coefX=0;
	  double coefY=0;
			
			double minX=0;
			double minY=0;
			double maxX=0;
			double maxY=0;

			double scanLocalOptimum=0;
			double scanLocalOptimum2nd=0;
 		double scanLocalX=0;
			double scanLocalY=0;
			double scanLocalAngle=0; 

			//********************************************************************************
			// CONTINUAL
			//********************************************************************************
		
			cLSTechInfo^ LSTechInfo = gcnew cLSTechInfo(); // vola staticky konstruktor mel by to nacist ze souboru

			scanLocalOptimum = 0;

  
			    if ( Math::Abs( g_Ds_DetectionAngle - doublePI ) < 0.00001 ){

    				  coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
       	  coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
	         coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081

							} else
							{
    				  coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
       	  coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
	         coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081
							}// if else 

   
			R1 = (gs_RPose.Angle_RAD-(g_Ds_DetectionAngle/2)-(g_ScanAngleNumber*coefLS) );
			R2 = (gs_RPose.Angle_RAD+(g_Ds_DetectionAngle/2)+(g_ScanAngleNumber*coefLS) );
   for (double i=R1;i<=R2;i=i+coefLS){ 

				   c104LSBeamItem^ LSBeamItem = gcnew c104LSBeamItem();

							LSBeamItem->PolarLength = LSTechInfo->LSRange;
       LSBeamItem->CalculatedLength = 0;
							LSBeamItem->cosX = ( Math::Cos( i )* LSBeamItem->PolarLength );
							LSBeamItem->sinY = ( Math::Sin( i )* LSBeamItem->PolarLength );
							LSBeamItem->BeamAngle = i;

							g_DmLSArray->Add( LSBeamItem ); 
																   
			}// for
        			
			// for ALL INDs
			for (UInt32 g=0;g<Convert::ToUInt32( g_Population->Count );g++){

        			for (UInt32 i = 0; i < Convert::ToUInt32(g_DmLSArray->Count); i = i + 1){  //create all beams, base index is 0
			
							   			  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 = ( safe_cast<c104PopItem^>(g_Population[g])->Xdec - (0.5*g_GA_AreaWidth)  + gs_RPose.posX );
	 				         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 = ( safe_cast<c104PopItem^>(g_Population[g])->Ydec - (0.5*g_GA_AreaHeight) + gs_RPose.posY );
							
															safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 = ( ( safe_cast<c104PopItem^>(g_Population[g])->Xdec - (0.5*g_GA_AreaWidth) ) +
																                                                  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->cosX + gs_RPose.posX );
							        safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2 = ( ( safe_cast<c104PopItem^>(g_Population[g])->Ydec - (0.5*g_GA_AreaHeight) ) +
																                                                  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->sinY + gs_RPose.posY );

         				  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 - safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2;
							        safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 - safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1;
               safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->c1 = (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2) -
        								                                               (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1);

		             if (	safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 > safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 ){
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 - g_WindowTolerance; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 + g_WindowTolerance; 
 						        } else
							        {
							             safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1; 
							 		          safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 - g_WindowTolerance; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 + g_WindowTolerance;
								       }// if else
               if (	safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 > safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2 ){
									           safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 - g_WindowTolerance; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 + g_WindowTolerance; 
								       } else
								       {
									           safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 - g_WindowTolerance; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 + g_WindowTolerance; 
								       }// if else

			        }// for (int i=0;i<=Convert::ToUInt32(paramNumberOfBeams-1)
         
											for (UInt32 i=0; i < Convert::ToUInt32(g_DmLSArray->Count); i++){ // for all beams

											   	Lsmin = Convert::ToDouble( LSTechInfo->LSRange );

															for (UInt32 j=0; j <= Convert::ToUInt32(g_TemporaryMap->Count-1); j++){ // for all walls
											
											        //  vypocet ABDet
                   if ( 	( ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u1 ) +
             												  ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u2 ) ) == 0 ){
								        								ABDet = 0;
											        } else
											        {
																        ABDet = 1;
        											}// if
           

          									if ( ABDet != 0 ){

							               // do obecne rovnice paprsku dosadime parametricke rovnice steny a vypocteme parametr t
												          t = ( ( (-1) * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->c1) - 
																            ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->Y1) -
																			         ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->X1) ) /
																			       ( ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u1 ) +
																			         ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u2 ) );

                      // parametr t dosadime do parametricke rovnice steny a vypoceteme prusecik
															       xp = ( safe_cast<c100LineItem^>(g_TemporaryMap[j])->X1 + (safe_cast<c100LineItem^>(g_TemporaryMap[j])->u1 * t) );
															       yp = ( safe_cast<c100LineItem^>(g_TemporaryMap[j])->Y1 + (safe_cast<c100LineItem^>(g_TemporaryMap[j])->u2 * t) );
											
																						// test zda prusecik paprsku a steny lezi uvnitr usecky paprsku a steny zaroven +/- g_WindowTolerance
 														       if ( xp>=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1) && 
																           xp<=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2) && 
																				       xp>=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wx1) && 
																				       xp<=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wx2) && 
																				       yp>=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1) && 
																				       yp<=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2) && 
																				       yp>=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wy1) && 
																				       yp<=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wy2) ){
																									                       
 											  				         Ls = Math::Sqrt( Math::Pow( (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 - xp), 2) +
																					                       Math::Pow( (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 - yp), 2) );

														          			if ( Ls < Lsmin ){
  	    	 										             Lsmin = Ls;
			    	 						            }// if ( Ls < Lsmin )

											           }//if ( xp>=Bx1 && xp<=Bx2 && xp>=Wx1 && xp<=Wx2 && yp>=By1 && yp<=By2 && yp>=Wy1 && yp<=Wy2 )

											       }// if ( ABDet != 0 )

           	  }// for (int j=0;j<=(h_LinesArray->Count-1);j++)
														
              safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->CalculatedLength = Lsmin;

          }// for (int i=0; i <= (coef2PIBeams-1); i++)

          // choose clasifying algoritmus
										switch ( g_SearchingAlgorithm ){
		         	case 0: // argmin(Dm-Ds)
					        {
														scanLocalOptimum = +99999998;
              for (UInt32 i=0;i<Convert::ToUInt32( g_ScanAngleNumber * 2 );i=i+g_paramStepDs){  
												   
                  R1=0;
                  for (UInt32 j=0;j<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );j=j+g_paramStepDe){  

   												       RI1 = (i+j);

																			   if ( g_RBeams[j] == true ){

                         if ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength != Convert::ToDouble( LSTechInfo->LSRange ) ){

                             R1 = R1 + Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
																							                           safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
                         }// if 

																						}// if 
									 							   
									   	     }// for (UInt32 j=0;j<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );j=j+g_paramStepDs)

													   		if ( R1 < scanLocalOptimum ){
                    
																       scanLocalOptimum = R1;
	                      scanLocalAngle = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->BeamAngle+(g_Ds_DetectionAngle/2); 

															   }// if

										    }// for (UInt32 i=0;i<=(coef2PIBeams-1);i=i+1)  

														safe_cast<c104PopItem^>(g_Population[g])->Fitness = scanLocalOptimum;
														safe_cast<c104PopItem^>(g_Population[g])->Angle = scanLocalAngle;   //

	        					break;
					        }
				        case 1: // argmax(sum|0/1((Dm-Ds)<beta))
					        {
					        
															scanLocalOptimum = 0;
               for (UInt32 i=0;i<Convert::ToUInt32( g_ScanAngleNumber * 2 );i=i+g_paramStepDs){  
									 			   
                   R1=0;
														    	for (UInt32 j=0;j<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );j=j+g_paramStepDe){  

																			    if ( g_RBeams[j] == true ){

    																      RI1 = (i+j);

                          if ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength != Convert::ToDouble( LSTechInfo->LSRange ) ){

																								     // way of EpsT evaluation for DSMAE2 only
																								     switch ( g_EpsTSel ){
												                   case 0: // Ds only EpsT from DETECTOR
																													   {
																														   R4 = Math::Abs( g_EpsTdummy * safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength ); 
																							          R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
																								                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
																														   break;
																													   }
												                   case 1: // Ds+de EpsT from DETECTOR
																													   {
											    								          R4 = Math::Abs( g_EpsTdummy * ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength + 
																								                                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength ) );
																							          R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
																								                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
																														   break;
																													   }
												                   case 2: // Ds only EpsT local
																													   {
																														   R4 = Math::Abs( g_EpsTdummy * safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength ); 
																							          R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
																								                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
																												 	   break;
																													   }
												                   case 3: // Ds+De only EpsT local
																													   {
											    								           R4 = Math::Abs( g_EpsTdummy * ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength + 
																								                                          safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength ) );
																							           R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
 																							                          safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
	 																													   break;
																													   }
																												   default:
																													   {
                                 MessageBox::Show( this, "Unexpected Event. [EvaluatePopulation()].", "Suspicious behaviour...", MessageBoxButtons::OK );
																														   break;
																													   }
																								     }// switch

																			          if ( R5 < R4  ) {
   																             R1 = R1 + 1;
																			          }

                          }// if 

																							}// if ( g_RBeams[j] == true )
																   
											        }// for (UInt32 j=0;j<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );j=j+1){  

												    			if ( R1 >= scanLocalOptimum ){
                     
																      scanLocalOptimum = R1;
	                     scanLocalAngle = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->BeamAngle+(g_Ds_DetectionAngle/2); 
															       
															    }// if

								    		 }// for (UInt32 i=0;i<=(coef2PIBeams-1);i=i+1) 

															safe_cast<c104PopItem^>(g_Population[g])->Fitness = scanLocalOptimum;
														 safe_cast<c104PopItem^>(g_Population[g])->Angle = scanLocalAngle; //R1; //scanLocalAngle;
														
						         break;
					        }
				        default:
					        {
						         break;
					        }
			       }// switch

			}// for ALL INDs

  						
   delete( LSTechInfo );

		 for each(c104LSBeamItem^ i in g_DmLSArray ){
   			 delete( safe_cast<c104LSBeamItem^>(i) );
			}// for
			g_DmLSArray->Clear();

			return 0;
								
}// private: System::Byte EvaluatePopulation(UInt32 Item) {

private: System::Byte EvaluatePopulationTrial(UInt32 Item) {
// compute starting position

  	const double doublePI = Math::PI * 2;

   double coefLS = 0;
			UInt32 coef2PIBeams = 0;
			UInt32	coefDmCount = 0;

			double R1=0;
  	double R2=0;
	  double R3=0;
	  double R4=0;
	  double R5=0;
		 double R6=0;
			double R7=0;
			double R8=0;
			double R9=0;
			double R10=0;
			double R11=0;
			double R12=0;
			double R13=0;

			UInt32 RI1=0;
			UInt32 RI2=0;

			double xp=0;
			double yp=0;

			double Lsmin=0;
			double Ls=0;
			double ABDet;
			double t=0;

   double coefX = 0;
	  double coefY = 0;
			
			double minX = 0;
			double minY = 0;
			double maxX = 0;
			double maxY = 0;

			double scanLocalOptimum = 0;
			double scanLocalOptimum2nd = 0;
 		double scanLocalX = 0;
			double scanLocalY = 0;
			double scanLocalAngle = 0; 

			//********************************************************************************
			// CONTINUAL
			//********************************************************************************
		

			cLSTechInfo^ LSTechInfo = gcnew cLSTechInfo(); // vola staticky konstruktor mel by to nacist ze souboru

			if ( Math::Abs( g_Ds_DetectionAngle - doublePI ) < 0.00001 ){

				  coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
   	  coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
      coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081

			} else
			{
				  coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
   	  coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
      coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081
			}// if else 

		
			R1 = (gs_RPose.Angle_RAD-(g_Ds_DetectionAngle/2)-(g_ScanAngleNumber*coefLS) );
			R2 = (gs_RPose.Angle_RAD+(g_Ds_DetectionAngle/2)+(g_ScanAngleNumber*coefLS) );
   for (double i=R1;i<=R2;i=i+coefLS){ 

				   c104LSBeamItem^ LSBeamItem = gcnew c104LSBeamItem();

							LSBeamItem->PolarLength = LSTechInfo->LSRange;
       LSBeamItem->CalculatedLength = 0;
							LSBeamItem->cosX = ( Math::Cos( i )* LSBeamItem->PolarLength );
							LSBeamItem->sinY = ( Math::Sin( i )* LSBeamItem->PolarLength );
							LSBeamItem->BeamAngle = i;

							g_DmLSArray->Add( LSBeamItem ); 
																   
			}// for


			// only one IND
			for (UInt32 g=0;g<Convert::ToUInt32( g_trialSolutionInd->Count );g++){

        			for (UInt32 i = 0; i < Convert::ToUInt32(g_DmLSArray->Count); i = i + 1){  //create all beams, base index is 0
			
							   			  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 = ( safe_cast<c104PopItem^>(g_trialSolutionInd[g])->Xdec - (0.5*g_GA_AreaWidth)  + gs_RPose.posX );
	 				         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 = ( safe_cast<c104PopItem^>(g_trialSolutionInd[g])->Ydec - (0.5*g_GA_AreaHeight) + gs_RPose.posY );
							
															safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 = ( ( safe_cast<c104PopItem^>(g_trialSolutionInd[g])->Xdec - (0.5*g_GA_AreaWidth)  ) +
																                                                  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->cosX + gs_RPose.posX );
							        safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2 = ( ( safe_cast<c104PopItem^>(g_trialSolutionInd[g])->Ydec - (0.5*g_GA_AreaHeight) ) +
																                                                  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->sinY + gs_RPose.posY );

         				  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 - safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2;
							        safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 - safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1;
               safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->c1 = (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2) -
        								                                               (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1);

		             if (	safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 > safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 ){
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 - g_WindowTolerance; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 + g_WindowTolerance; 
 						        } else
							        {
							             safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1; 
							 		          safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 - g_WindowTolerance; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 + g_WindowTolerance;
								       }// if else
               if (	safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 > safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2 ){
									           safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 - g_WindowTolerance; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 + g_WindowTolerance; 
								       } else
								       {
									           safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 - g_WindowTolerance; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 + g_WindowTolerance; 
								       }// if else

			        }// for (int i=0;i<=Convert::ToUInt32(paramNumberOfBeams-1)
         
											// pro vsechny paprsky vypocitej vzdalenost ke zdi 
											for (UInt32 i=0; i < Convert::ToUInt32(g_DmLSArray->Count); i++){ // for all beams

											   	Lsmin = Convert::ToDouble( LSTechInfo->LSRange );

															for (UInt32 j=0; j <= Convert::ToUInt32(g_TemporaryMap->Count-1); j++){ // for all walls

											        //  vypocet ABDet
                   if ( 	( ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u1 ) +
             												  ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u2 ) ) == 0 ){
								        								ABDet = 0;
											        } else
											        {
																        ABDet = 1;
        											}// if
           

          									if ( ABDet != 0 ){

							               // do obecne rovnice paprsku dosadime parametricke rovnice steny a vypocteme parametr t
												          t = ( ( (-1) * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->c1) - 
																            ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->Y1) -
																			         ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->X1) ) /
																			       ( ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u1 ) +
																			         ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u2 ) );

                      // parametr t dosadime do parametricke rovnice steny a vypoceteme prusecik
															       xp = ( safe_cast<c100LineItem^>(g_TemporaryMap[j])->X1 + (safe_cast<c100LineItem^>(g_TemporaryMap[j])->u1 * t) );
															       yp = ( safe_cast<c100LineItem^>(g_TemporaryMap[j])->Y1 + (safe_cast<c100LineItem^>(g_TemporaryMap[j])->u2 * t) );
											
																						// test zda prusecik paprsku a steny lezi uvnitr usecky paprsku a steny zaroven +/- g_WindowTolerance
 														       if ( xp>=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1) && 
																           xp<=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2) && 
																				       xp>=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wx1) && 
																				       xp<=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wx2) && 
																				       yp>=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1) && 
																				       yp<=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2) && 
																				       yp>=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wy1) && 
																				       yp<=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wy2) ){
																									                       
 											  				         Ls = Math::Sqrt( Math::Pow( (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 - xp), 2) +
																					                       Math::Pow( (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 - yp), 2) );

														          			if ( Ls < Lsmin ){
  	    	 										             Lsmin = Ls;
			    	 						            }// if ( Ls < Lsmin )

											           }//if ( xp>=Bx1 && xp<=Bx2 && xp>=Wx1 && xp<=Wx2 && yp>=By1 && yp<=By2 && yp>=Wy1 && yp<=Wy2 )

											       }// if ( ABDet != 0 )

           	  }// for (int j=0;j<=(h_LinesArray->Count-1);j++)
														
              safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->CalculatedLength = Lsmin;


          }// for (int i=0; i <= (coef2PIBeams-1); i++)

          // choose clasifying algoritmus
										switch ( g_SearchingAlgorithm ){
		         	case 0: // argmin(Dm-Ds)
					        {
														scanLocalOptimum = double::MaxValue; // +99999998;
              for (UInt32 i=0;i<Convert::ToUInt32( g_ScanAngleNumber * 2 );i=i+g_paramStepDs){  
												   
                  R1=0;
   															for (UInt32 j=0;j<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );j=j+g_paramStepDe){  

			   													     RI1 = (i+j);

                        if ( g_RBeams[j] == true ){

                           if ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength != Convert::ToDouble( LSTechInfo->LSRange ) ){

   			   													        R1 = R1 + Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
																							                            safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );

                           }// if 

																								}// if 
									 							   
										   	    }// for (UInt32 j=0;j<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );j=j+g_paramStepDs)

													   		if ( R1 < scanLocalOptimum ){
                    
																       scanLocalOptimum = R1;
																			   	scanLocalX = safe_cast<c104PopItem^>(g_trialSolutionInd[g])->Xdec;
																				   scanLocalY = safe_cast<c104PopItem^>(g_trialSolutionInd[g])->Ydec;

	                      scanLocalAngle = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->BeamAngle+(g_Ds_DetectionAngle/2); 

															   }// if

										    }// for (UInt32 i=0;i<=(coef2PIBeams-1);i=i+1) 

														safe_cast<c104PopItem^>(g_trialSolutionInd[g])->Fitness = scanLocalOptimum;
														safe_cast<c104PopItem^>(g_trialSolutionInd[g])->Angle = scanLocalAngle;  //R1; //scanLocalAngle;

	        					break;
					        }
				        case 1: // argmax(sum|0/1((Dm-Ds)<beta))
					        {
					        
															scanLocalOptimum = 0;
               for (UInt32 i=0;i<Convert::ToUInt32( g_ScanAngleNumber * 2 );i=i+g_paramStepDs){  
									 			   
                   R1=0;
														    	for (UInt32 j=0;j<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );j=j+g_paramStepDe){  

                       if ( g_RBeams[j] == true ){

       																   RI1 = (i+j);

                          if ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength != Convert::ToDouble( LSTechInfo->LSRange ) ){
                       
                             // way of EpsT evaluation for DSMAE2 only
										   														  switch ( g_EpsTSel ){
												                   case 0: // Ds only EpsT from DETECTOR
																   													{
																			   											R4 = Math::Abs( g_EpsTdummy * safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength ); 
																						   	       R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
																								                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
																												   		break;
																													   }
												                   case 1: // Ds+de EpsT from DETECTOR
																													   {
											    								          R4 = Math::Abs( g_EpsTdummy * ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength + 
																								                                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength ) );
																							          R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
																								                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
																														   break;
																													   }
												                   case 2: // Ds only EpsT local
																													   {
																														   R4 = Math::Abs( g_EpsTdummy * safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength ); 
																							          R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
																								                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
																												 	   break;
																													   }
												                   case 3: // Ds+De only EpsT local
																													   {
											    								           R4 = Math::Abs( g_EpsTdummy * ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength + 
																								                                          safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength ) );
																							           R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
 																							                          safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
	 																													   break;
																													   }
																												   default:
																													   {
																														   MessageBox::Show( this, "Unexpected Event. [EvaluatePopulation()].", "Suspicious behaviour...", MessageBoxButtons::OK );
																														   break;
																													   }
																								     }// switch

																			          if ( R5 < R4  ) {
      																          R1 = R1 + 1;
																			          }// if

                          }// if 

																							}// if ( g_RBeams[j] == true )
																   
											        }// for (UInt32 j=0;j<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );j=j+1){  

												    			if ( R1 >= scanLocalOptimum ){

 															      scanLocalOptimum = R1;
	                     scanLocalAngle = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->BeamAngle+(g_Ds_DetectionAngle/2); 
 
															    }// if

								    		 }// for (UInt32 i=0;i<=(coef2PIBeams-1);i=i+1)  

															safe_cast<c104PopItem^>(g_trialSolutionInd[g])->Fitness = scanLocalOptimum;
														 safe_cast<c104PopItem^>(g_trialSolutionInd[g])->Angle = scanLocalAngle; //

						         break;
					        }
				        default:
					        {
						         break;
					        }
			       }// switch

			}// for g ONE IND only
	  						
   delete( LSTechInfo );

		 for each(c104LSBeamItem^ i in g_DmLSArray ){
   			 delete( safe_cast<c104LSBeamItem^>(i) );
			}// for
			g_DmLSArray->Clear();

			return 0;
								
}// private: System::Byte EvaluatePopulationTrial(UInt32 Item) {


private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
// Mouse move

 double R1;
	double R2;

 double PosX=0;
	double PosY=0;

 double coefX=0;
	double coefY=0;

	double doublePI = (2*Math::PI);

//*******************************************

	    if ( gs_PLBFile.Opened == false ){ 
   		   return;
	    }// if 

	    if ( g_PLBBitmap == nullptr ){ 
   		   return;
	    }// if 

	    coefX = Convert::ToDouble( g_PLBBitmap->Width - 1 ) / Math::Abs(g_globalPLBMaxX_XY-g_globalPLBMinX_XY);	
    	coefY = Convert::ToDouble( g_PLBBitmap->Height- 1 ) / Math::Abs(g_globalPLBMaxY_XY-g_globalPLBMinY_XY);

					R1=e->X;
					R2=e->Y;
	
     PosX = ( R1 + 
						        (coefX*g_PLBMagnifierX*g_globalPLBMinX_XY)+
						        (coefX*g_PLBMagnifierX*((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2))-
														(Convert::ToDouble( g_PLBBitmap->Width-1 )/2) 
													) / (coefX*g_PLBMagnifierX);
     PosY = ( R2 -
						        (Convert::ToDouble( g_PLBBitmap->Height-1 ))-
														(coefY*g_PLBMagnifierY*g_globalPLBMinY_XY)-
														(coefY*g_PLBMagnifierY*((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2))+
														(Convert::ToDouble( g_PLBBitmap->Height-1 )/2)
													) / ((-1)*(coefY*g_PLBMagnifierY));
   
		   this->label176->Text = "Mouse position  X: " + Convert::ToString( Convert::ToInt32( PosX ) )+ " : Y: " + Convert::ToString( Convert::ToInt32( PosY ) );
		   this->label176->Refresh();

}// private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {


private: System::Void maskedTextBox8_Leave(System::Object^  sender, System::EventArgs^  e) {
// StopValue Termination rules

double R1 = 0;

Boolean ErrStatus = false;

//****************************

      try
      {
							double number = double::Parse(this->maskedTextBox8->Text);
      }
      catch (...)
      {
							ErrStatus = true;
      }// try catch

						if ( ErrStatus == true ){
									MessageBox::Show( this, "Wrong number. MS IEE754(double) format only. ","Error in expression.", MessageBoxButtons::OK ); 
									this->maskedTextBox8->Text = "0,00983";
						} else
						{  
							  R1 = Convert::ToDouble(this->maskedTextBox8->Text);
							  if ( R1 > 10 || R1 < 0.0000001 ){
									   MessageBox::Show( this, "EpsT value exceeded min/max values [0.0000001 .. 10].","Error in expression.", MessageBoxButtons::OK ); 
									   this->maskedTextBox8->Text = "0,00983";
	  						}// if
  
						}// if 
     
}// private: System::Void maskedTextBox8_Leave

private: System::Void maskedTextBox9_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
// Ymin validace

      try
      {
							double number = double::Parse(this->maskedTextBox9->Text);
							e->Cancel = false; 
      }
      catch (...)
      {
							e->Cancel = true; 
      }// try catch

}// private: System::Void maskedTextBox9_Validating

private: System::Void maskedTextBox9_Leave(System::Object^  sender, System::EventArgs^  e) {
// StopValue Termination rules

double R1 = 0;

Boolean ErrStatus = false;

//****************************

      try
      {
							double number = double::Parse(this->maskedTextBox9->Text);
      }
      catch (...)
      {
							ErrStatus = true;
      }// try catch

						if ( ErrStatus == true ){
									MessageBox::Show( this, "Wrong number. MS IEE754(double) format only. ","Error in expression.", MessageBoxButtons::OK ); 
									this->maskedTextBox9->Text = "1";
						} else
						{  
							  R1 = Convert::ToDouble(this->maskedTextBox9->Text);
							  if ( R1 > 1 || R1 < 0.0000001 ){
									   MessageBox::Show( this, "EpsT value exceeded min/max values [0.0000001 .. 1].","Error in expression.", MessageBoxButtons::OK ); 
									   this->maskedTextBox9->Text = "1";
	  						}// if
  
						}// if 
     
}// private: System::Void maskedTextBox9_Leave

private: System::Void maskedTextBox10_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
// Ymin validace

      try
      {
							double number = double::Parse(this->maskedTextBox10->Text);
							e->Cancel = false; 
      }
      catch (...)
      {
							e->Cancel = true; 
      }// try catch

}// private: System::Void maskedTextBox10_Validating

private: System::Void maskedTextBox10_Leave(System::Object^  sender, System::EventArgs^  e) {
// StopValue Termination rules

double R1 = 0;

Boolean ErrStatus = false;

//****************************

      try
      {
							double number = double::Parse(this->maskedTextBox10->Text);
      }
      catch (...)
      {
							ErrStatus = true;
      }// try catch

						if ( ErrStatus == true ){
									MessageBox::Show( this, "Wrong number. MS IEE754(double) format only. ","Error in expression.", MessageBoxButtons::OK ); 
									this->maskedTextBox10->Text = "0,6";
						} else
						{  
							  R1 = Convert::ToDouble(this->maskedTextBox10->Text);
							  if ( R1 > 2 || R1 < 0.0000001 ){
									   MessageBox::Show( this, "EpsT value exceeded min/max values [0.0000001 .. 2].","Error in expression.", MessageBoxButtons::OK ); 
									   this->maskedTextBox10->Text = "0,6";
	  						}// if
  
						}// if 
     
}// private: System::Void maskedTextBox10_Leave



private: System::Void maskedTextBox44_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
// Ymin validace

      try
      {
							double number = double::Parse(this->maskedTextBox44->Text);
							e->Cancel = false; 
      }
      catch (...)
      {
							e->Cancel = true; 
      }// try catch

}// private: System::Void maskedTextBox44_Validating

private: System::Void maskedTextBox44_Leave(System::Object^  sender, System::EventArgs^  e) {
// StopValue Termination rules

double R1 = 0;

Boolean ErrStatus = false;

//****************************

      try
      {
							double number = double::Parse(this->maskedTextBox44->Text);
      }
      catch (...)
      {
							ErrStatus = true;
      }// try catch

						if ( ErrStatus == true ){
									MessageBox::Show( this, "Wrong number. MS IEE754(double) format only. ","Error in expression.", MessageBoxButtons::OK ); 
									this->maskedTextBox44->Text = "0,45";
						} else
						{  
							  R1 = Convert::ToDouble(this->maskedTextBox44->Text);
							  if ( R1 > 6.4 || R1 < 0.0000001 ){
									   MessageBox::Show( this, "Angle value exceeded min/max values [0.0000001 .. 6.283].","Error in expression.", MessageBoxButtons::OK ); 
									   this->maskedTextBox44->Text = "0,45";
	  						}// if
  
						}// if 
     
}// private: System::Void maskedTextBox44_Leave

private: System::Void maskedTextBox45_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
// Ymin validace

      try
      {
							double number = double::Parse(this->maskedTextBox45->Text);
							e->Cancel = false; 
      }
      catch (...)
      {
							e->Cancel = true; 
      }// try catch

}// private: System::Void maskedTextBox45_Validating

private: System::Void maskedTextBox45_Leave(System::Object^  sender, System::EventArgs^  e) {
// StopValue Termination rules

double R1 = 0;

Boolean ErrStatus = false;

//****************************

      try
      {
							double number = double::Parse(this->maskedTextBox45->Text);
      }
      catch (...)
      {
							ErrStatus = true;
      }// try catch

						if ( ErrStatus == true ){
									MessageBox::Show( this, "Wrong number. MS IEE754(double) format only. ","Error in expression.", MessageBoxButtons::OK ); 
									this->maskedTextBox45->Text = "0,0872";
						} else
						{  
							  R1 = Convert::ToDouble(this->maskedTextBox45->Text);
							  if ( R1 > 6.4 || R1 < 0.0000001 ){
									   MessageBox::Show( this, "Angle value exceeded min/max values [0.0000001 .. 6.283].","Error in expression.", MessageBoxButtons::OK ); 
									   this->maskedTextBox45->Text = "0,0872";
	  						}// if
  
						}// if 
     
}// private: System::Void maskedTextBox45_Leave

private: System::Void maskedTextBox46_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
// Ymin validace

      try
      {
							double number = double::Parse(this->maskedTextBox46->Text);
							e->Cancel = false; 
      }
      catch (...)
      {
							e->Cancel = true; 
      }// try catch

}// private: System::Void maskedTextBox46_Validating

private: System::Void maskedTextBox46_Leave(System::Object^  sender, System::EventArgs^  e) {
// StopValue Termination rules

double R1 = 0;

Boolean ErrStatus = false;

//****************************

      try
      {
							double number = double::Parse(this->maskedTextBox46->Text);
      }
      catch (...)
      {
							ErrStatus = true;
      }// try catch

						if ( ErrStatus == true ){
									MessageBox::Show( this, "Wrong number. MS IEE754(double) format only. ","Error in expression.", MessageBoxButtons::OK ); 
									this->maskedTextBox46->Text = "0,5";
						} else
						{  
							  R1 = Convert::ToDouble(this->maskedTextBox46->Text);
							  if ( R1 > 6.4 || R1 < 0.0000001 ){
									   MessageBox::Show( this, "Angle value exceeded min/max values [0.0000001 .. 6.283].","Error in expression.", MessageBoxButtons::OK ); 
									   this->maskedTextBox46->Text = "0,5";
	  						}// if
  
						}// if 
     
}// private: System::Void maskedTextBox46_Leave

private: System::Void maskedTextBox47_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
// Ymin validace

      try
      {
							double number = double::Parse(this->maskedTextBox47->Text);
							e->Cancel = false; 
      }
      catch (...)
      {
							e->Cancel = true; 
      }// try catch

}// private: System::Void maskedTextBox47_Validating

private: System::Void maskedTextBox47_Leave(System::Object^  sender, System::EventArgs^  e) {
// StopValue Termination rules

double R1 = 0;

Boolean ErrStatus = false;

//****************************

      try
      {
							double number = double::Parse(this->maskedTextBox47->Text);
      }
      catch (...)
      {
							ErrStatus = true;
      }// try catch

						if ( ErrStatus == true ){
									MessageBox::Show( this, "Wrong number. MS IEE754(double) format only. ","Error in expression.", MessageBoxButtons::OK ); 
									this->maskedTextBox47->Text = "0,5";
						} else
						{  
							  R1 = Convert::ToDouble(this->maskedTextBox47->Text);
							  if ( R1 > 6.4 || R1 < 0.0000001 ){
									   MessageBox::Show( this, "Angle value exceeded min/max values [0.0000001 .. 6.283].","Error in expression.", MessageBoxButtons::OK ); 
									   this->maskedTextBox47->Text = "0,5";
	  						}// if
  
						}// if 
     
}// private: System::Void maskedTextBox47_Leave

private: System::Void comboBox13_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
// set start pose 

										if ( g_StartPoses->Count == 0 ){
											  return;
										}// if 

										this->numericUpDown1->Value = Convert::ToDecimal( safe_cast<c104StartPoses^>(g_StartPoses[ Convert::ToInt32( this->comboBox13->SelectedIndex ) ])->X );
										this->numericUpDown2->Value = Convert::ToDecimal( safe_cast<c104StartPoses^>(g_StartPoses[ Convert::ToInt32( this->comboBox13->SelectedIndex ) ])->Y );
										this->numericUpDown69->Value = Convert::ToDecimal( safe_cast<c104StartPoses^>(g_StartPoses[ Convert::ToInt32( this->comboBox13->SelectedIndex ) ])->Angle );

}// private: System::Void comboBox13_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
// Founded positions list / selected index changed
									
 	 const double doublePI = Math::PI * 2;

   double R1 = 0;
   double R2 = 0;
   double R3 = 0;
   double R4 = 0;
   double R5 = 0;
   double R6 = 0;
   double R7 = 0;

			UInt32 RI1 = 0;

   double coefX = 0;
   double coefY = 0;

			double coefLS = 0;
			double coef2PIBeams = 0;

//**********************************************


			   if ( g_FoundedPositions->Count == 0 ){
							  return;
						}//
					 
						RI1 = Convert::ToUInt32(this->listBox2->SelectedIndex);

						this->pictureBox1->Image = nullptr;

				  if ( g_PLBBitmapDummy != nullptr ){
					    delete(g_PLBBitmapDummy);
									g_PLBBitmapDummy = nullptr;
				  }// if
						if ( g_G_PLB != nullptr ){
 							 delete(g_G_PLB);
									g_G_PLB = nullptr;
					 }// if

	     g_PLBBitmapDummy = dynamic_cast<System::Drawing::Bitmap^>(g_PLBBitmap->Clone());

		    g_G_PLB=Graphics::FromImage(g_PLBBitmapDummy);
	   	 g_G_PLB->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceOver;

		    this->pictureBox1->Image = dynamic_cast<Image^>(g_PLBBitmapDummy); 
					
						if ( Math::Abs( g_Ds_DetectionAngle - doublePI ) < 0.00001 ){
   						coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
			   			coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    
						} else
						{
   						coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
			   			coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    
						}// if else

		  	 coefX = Convert::ToDouble( g_PLBBitmapDummy->Width  -1 ) / (g_globalPLBMaxX_XY-g_globalPLBMinX_XY);	
    	 coefY = Convert::ToDouble( g_PLBBitmapDummy->Height -1 ) / (g_globalPLBMaxY_XY-g_globalPLBMinY_XY);

		 			R1=0;
			 		R2=0;

				  g_Triangle[0]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
 					g_Triangle[0]->Y1 = R2 + (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
      g_Triangle[0]->X2 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					 g_Triangle[0]->Y2 = R2 - (g_PLBBitmapDummy->Height/g_vRobotMagnifier);

					 g_Triangle[1]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					 g_Triangle[1]->Y1 = R2 - (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
      g_Triangle[1]->X2 = R1 + (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					 g_Triangle[1]->Y2 = R2;

 					g_Triangle[2]->X1 = R1 - (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					 g_Triangle[2]->Y1 = R2 + (g_PLBBitmapDummy->Height/g_vRobotMagnifier);
      g_Triangle[2]->X2 = R1 + (g_PLBBitmapDummy->Width/g_vRobotMagnifier);
					 g_Triangle[2]->Y2 = R2;

      g_Triangle[3]->X1 = R1;
 					g_Triangle[3]->Y1 = R2;
      g_Triangle[3]->X2 = R1 + (2*(g_PLBBitmapDummy->Width/g_vRobotMagnifier));
					 g_Triangle[3]->Y2 = R2;
		 
      R7 = safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->Angle; //- (g_Ds_DetectionAngle/2); 
					 for (int i=0;i<=3;i++){

          R3 = g_Triangle[i]->X1;
		  					 R4 = g_Triangle[i]->Y1;
				  			 R5 = g_Triangle[i]->X2;
							   R6 = g_Triangle[i]->Y2;

							   g_Triangle[i]->X1 = ((R3 * Math::Cos( R7 )) - (R4 * Math::Sin( R7 )));
							   g_Triangle[i]->Y1 = ((R3 * Math::Sin( R7 )) + (R4 * Math::Cos( R7 )));
    
							   g_Triangle[i]->X2 = ((R5 * Math::Cos( R7 )) - (R6 * Math::Sin( R7 )));
     		   g_Triangle[i]->Y2 = ((R5 * Math::Sin( R7 )) + (R6 * Math::Cos( R7 )));
				
									 g_Triangle[i]->X1 =  g_Triangle[i]->X1 + safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->PosX;  
 						   g_Triangle[i]->Y1 =  g_Triangle[i]->Y1 + safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->PosY;  
	 					   g_Triangle[i]->X2 =  g_Triangle[i]->X2 + safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->PosX;    
							   g_Triangle[i]->Y2 =  g_Triangle[i]->Y2 + safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->PosY;    

 			 	}// for

  			 for (UInt32 i=0;i<=2;i++){
          
          R1 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[i]->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
		   				 	    ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);

          R2 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[i]->Y1-g_globalPLBMinY_XY) -
										     ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

          R3 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[i]->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
									      ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);
    				   	 	
	  	     	R4 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[i]->Y2-g_globalPLBMinY_XY) - 
										     ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

										// draw robot
							   if ( this->checkBox50->Checked == true ){ 

		   	       g_G_PLB->DrawLine( gs_Pen.BluePen2,  (float)( R1 ),
 		                                               (float)( R2 ),
																				       	 									 									 	(float)( R3 ),
 			    		 												                           (float)(	R4 ) ) ;
										}// if 

 		  }// for

		   R1 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[3]->X1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
					     ( Convert::ToDouble( g_PLBBitmapDummy->Width  - 1 )/2);

     R2 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[3]->Y1-g_globalPLBMinY_XY) - 
						    ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

     R3 = coefX * ( g_PLBMagnifierX * ( (g_Triangle[3]->X2-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
				      ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);
   			   		
					R4 = ( g_PLBBitmapDummy->Height-1 ) - ( coefY * ( g_PLBMagnifierY * ( (g_Triangle[3]->Y2-g_globalPLBMinY_XY) - 
						    ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) + ( Convert::ToDouble( g_PLBBitmapDummy->Height - 1 )/2) );

					// draw robot 
					if ( this->checkBox50->Checked == true ){ 

        g_G_PLB->DrawLine( gs_Pen.BlackPen2, (float)( R1 ),
                                             (float)( R2 ),
				  							       	 																					  (float)( R3 ),
  		 	 											                           (float)(	R4 ) ) ;
					}// if 
		
					// draw scan points 
     R7 = safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->Angle; 
			  for (UInt32 i=0;i<=Convert::ToUInt32( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->LSItemDfXY->Length -1 );i++){

					     R1 = safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->LSItemDfXY[i]->X; 
		 			    R2 = safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->LSItemDfXY[i]->Y; 

			       R1 = coefX * ( g_PLBMagnifierX * ( (R1-g_globalPLBMinX_XY) - ((g_globalPLBMaxX_XY-g_globalPLBMinX_XY)/2) ) ) +
			 				       ( Convert::ToDouble( g_PLBBitmap->Width  - 1 )/2);

          R2 = (g_PLBBitmap->Height-1) - ( coefY * ( g_PLBMagnifierY * ( (R2-g_globalPLBMinY_XY) - ((g_globalPLBMaxY_XY-g_globalPLBMinY_XY)/2) ) ) +
	 	   					    ( Convert::ToDouble( g_PLBBitmap->Height - 1 )/2) );

										// kresli prekazku 
							   if ( this->checkBox37->Checked == true ){ 
											  if ( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->Obstacle[i]->Obstacle == true ){ 
  			           g_G_PLB->DrawEllipse(gs_Pen.RedPen2, Convert::ToInt32( R1 ),
				                                                 Convert::ToInt32(	R2 ), 3,3);
										   }// if 
										}// if  

										// kresli volny paprsek
										if ( this->checkBox38->Checked == true ){ 
	            if ( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->Obstacle[i]->Obstacle == false ){ 
  			           g_G_PLB->DrawEllipse(gs_Pen.BluePen1, Convert::ToInt32( R1 ),
				                                                  Convert::ToInt32(	R2 ), 2,2);
										   }// if 
										}// if 

		   }// for


				 this->label210->Text = "Sample[index]: "+Convert::ToString( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->Sample );  
					this->label208->Text = "Position: "+ Convert::ToString( Math::Round( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->PosX ) ) + 
			                         " Y: " + Convert::ToString( Math::Round( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->PosY ) ) + 
																								   	"  ["+ Convert::ToString( rad2deg_rounded( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->Angle) ) + "°]";  
					this->label207->Text = "Local optimum: "+Convert::ToString( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->Optimum );
     this->label209->Text = "Scan Area XY: minXY [ "+Convert::ToString( Math::Round( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->DsMinX_XY ) )+" ; "+  
					                       Convert::ToString( Math::Round( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->DsMinY_XY ) )+ " ]" +  
																					 						" ]  maxXY [ "+Convert::ToString( Math::Round( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->DsMaxX_XY ) )+ " ; " +  
																						 					Convert::ToString( Math::Round( safe_cast<c104FoundPosition^>(g_FoundedPositions[ RI1 ])->DsMaxY_XY ))+ " ] "; 

					this->pictureBox1->Refresh(); 

}// private: System::Void listBox2_SelectedIndexChanged

private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
// SAVE SCREEN TO BMP

Boolean ErrStatus = false;

//*******************************

	    if ( g_PLBBitmapDummy == nullptr ){ 
		      return;
	    }// if 




					   SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

					   saveFileDialog1->CreatePrompt = true;
        saveFileDialog1->OverwritePrompt = true;
     
			     saveFileDialog1->FileName = "picture_dsmae3";


       saveFileDialog1->DefaultExt = "jpg";
					  saveFileDialog1->FilterIndex = 1;
       saveFileDialog1->Filter = "jpg files (*.JPG;*.jpg)|*.JPG;*.jpg|All files (*.*)|*.*";   
       saveFileDialog1->InitialDirectory = "c:\\";

       System::Windows::Forms::DialogResult result = saveFileDialog1->ShowDialog();

					  if ( result == System::Windows::Forms::DialogResult::OK )
       {
					
          try
          {
      					 g_PLBBitmapDummy->Save( saveFileDialog1->FileName );
          }
								  catch(Exception^ err)
								  {
  									 MessageBox::Show("Error at saving picture:"+err->Message,"Saving...", MessageBoxButtons::OK );
										  ErrStatus = true;
								  }
          finally
          {
									   if ( ErrStatus == false ){
               MessageBox::Show( "Picture saved OK","Saving...", MessageBoxButtons::OK );
										  }// if 
          }

        }// if

						  delete ( saveFileDialog1 );

   
					
}// private: System::Void toolStripButton1_Click


private: System::Void button49_Click(System::Object^  sender, System::EventArgs^  e) {
// AUTO PROPERTIES SAVE, (of course serialization can be used)
// Serialization of Form1 is not possible because MS do not added EventHandler serialization yet.
// So... this way is old ... but gold :-) and simply enough :-).

String^ line = "";
Boolean ErrStatus = false;

StreamWriter^ sw = nullptr;

//*************************************
 
			
   try
   {

       sw = gcnew StreamWriter( g_CFG_RobomapDirectory + "\\settings\\" + "gslam.set" );

       // AutoReload at start ?
       line = Convert::ToString( this->checkBox57->Checked ); 
       sw->WriteLine( line );

							// RUN
       line = Convert::ToString( this->checkBox44->Checked ); 
       sw->WriteLine( line );
       line = Convert::ToString( this->comboBox13->SelectedIndex ); 
       sw->WriteLine( line );
       line = Convert::ToString( this->numericUpDown35->Value ); 
       sw->WriteLine( line );

							// draw
						 line = Convert::ToString( this->checkBox30->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox31->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox32->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox34->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox35->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox36->Checked ); 
       sw->WriteLine( line );
							line = Convert::ToString( this->checkBox25->Checked );
       sw->WriteLine( line );
							line = Convert::ToString( this->checkBox27->Checked );
       sw->WriteLine( line );
							line = Convert::ToString( this->checkBox26->Checked );
       sw->WriteLine( line );
							line = Convert::ToString( this->checkBox24->Checked );
       sw->WriteLine( line );
							line = Convert::ToString( this->checkBox23->Checked );
       sw->WriteLine( line );
							line = Convert::ToString( this->checkBox22->Checked );
       sw->WriteLine( line );
							line = Convert::ToString( this->checkBox33->Checked );
       sw->WriteLine( line );

						 line = Convert::ToString( this->numericUpDown59->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox29->Checked ); 
       sw->WriteLine( line );

						 line = Convert::ToString( this->checkBox48->Checked ); 
       sw->WriteLine( line );

						 line = Convert::ToString( this->trackBar5->Value ); 
       sw->WriteLine( line );

						 line = Convert::ToString( this->checkBox40->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox52->Checked ); 
       sw->WriteLine( line );

						

							// Scanner
						 line = Convert::ToString( this->radioButton4->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->radioButton5->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->maskedTextBox8->Text ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown21->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown20->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown19->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->comboBox8->SelectedIndex ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown29->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown31->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown33->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown34->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown30->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown32->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown28->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->comboBox6->SelectedIndex ); 
       sw->WriteLine( line );
							line = Convert::ToString( this->numericUpDown24->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown25->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown26->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown27->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->maskedTextBox10->Text ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->maskedTextBox9->Text ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown23->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown22->Value ); 
       sw->WriteLine( line );
						
       // LSB file
						 line = Convert::ToString( this->radioButton8->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->radioButton7->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->radioButton6->Checked ); 
       sw->WriteLine( line );

							// Founded pos
						 line = Convert::ToString( this->checkBox37->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox38->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox50->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox46->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox45->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->radioButton37->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->radioButton36->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->radioButton35->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->radioButton34->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown72->Value ); 
       sw->WriteLine( line );

							// Split merge
						 line = Convert::ToString( this->checkBox19->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox20->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->checkBox21->Checked ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown79->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->maskedTextBox44->Text ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->maskedTextBox46->Text ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown80->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->maskedTextBox45->Text ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown75->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown73->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown74->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown76->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown81->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown77->Value ); // line approx
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown78->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->comboBox23->SelectedIndex ); //TM
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown86->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown87->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->maskedTextBox47->Text ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown83->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown85->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown84->Value ); 
       sw->WriteLine( line );
						 line = Convert::ToString( this->numericUpDown82->Value ); 
       sw->WriteLine( line );


   }
			catch( Exception^ err )
			{
       MessageBox::Show( "Error in SET data file writing: "+err->Message,"SET data writing.", MessageBoxButtons::OK );
			}
   finally
   {
				  sw->Close();
      if ( sw )
         delete (IDisposable^)sw;
			}


}// private: System::Void button49_Click(System::Object^  sender, System::EventArgs^  e) {

private: System::Void button50_Click(System::Object^  sender, System::EventArgs^  e) {
// PROPERTIES Reload settings

String^ line = "";
Boolean ErrStatus = false;

StreamReader^ sr = nullptr;

//***************************************


   if ( File::Exists( g_CFG_RobomapDirectory + "\\settings\\" + "gslam.set" ) == false ){
				  return;
   }// if 
    
			
     try
     {
 		    sr = gcnew StreamReader( g_CFG_RobomapDirectory + "\\settings\\" + "gslam.set" );

       // AutoReload at start ?
							line = sr->ReadLine();
							this->checkBox57->Checked = Convert::ToBoolean( line ); 

							// RUN
							line = sr->ReadLine();
       this->checkBox44->Checked = Convert::ToBoolean( line ); 
							line = sr->ReadLine();
							this->comboBox13->SelectedIndex = Convert::ToInt32( line ); 
							line = sr->ReadLine();
							this->numericUpDown35->Value = Convert::ToDecimal( line ); 

							// draw
							line = sr->ReadLine();
							this->checkBox30->Checked = Convert::ToBoolean( line ); 
							line = sr->ReadLine();
							this->checkBox31->Checked = Convert::ToBoolean( line ); 
							line = sr->ReadLine();
							this->checkBox32->Checked = Convert::ToBoolean( line ); 
							line = sr->ReadLine();
							this->checkBox34->Checked = Convert::ToBoolean( line ); 
							line = sr->ReadLine();
							this->checkBox35->Checked = Convert::ToBoolean( line ); 
							line = sr->ReadLine();
							this->checkBox36->Checked = Convert::ToBoolean( line );
							line = sr->ReadLine();
							this->checkBox25->Checked = Convert::ToBoolean( line );
							line = sr->ReadLine();
							this->checkBox27->Checked = Convert::ToBoolean( line );
							line = sr->ReadLine();
							this->checkBox26->Checked = Convert::ToBoolean( line );
							line = sr->ReadLine();
       this->checkBox24->Checked = Convert::ToBoolean( line );
							line = sr->ReadLine();
       this->checkBox23->Checked = Convert::ToBoolean( line );
							line = sr->ReadLine();
							this->checkBox22->Checked = Convert::ToBoolean( line );
							line = sr->ReadLine();
							this->checkBox33->Checked = Convert::ToBoolean( line );
							line = sr->ReadLine();

						 this->numericUpDown59->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->checkBox29->Checked = Convert::ToBoolean( line );  
 
							line = sr->ReadLine();
						 this->checkBox48->Checked = Convert::ToBoolean( line );  
 
							line = sr->ReadLine();
						 this->trackBar5->Value = Convert::ToInt32( line );  
 
							line = sr->ReadLine();
						 this->checkBox40->Checked = Convert::ToBoolean( line );  
							line = sr->ReadLine();
						 this->checkBox52->Checked = Convert::ToBoolean( line );  

							// Scanner
							line = sr->ReadLine();
						 this->radioButton4->Checked = Convert::ToBoolean( line ); 
							line = sr->ReadLine();
						 this->radioButton5->Checked = Convert::ToBoolean( line ); 
							line = sr->ReadLine();
						 this->maskedTextBox8->Text = Convert::ToString( line );
							line = sr->ReadLine();
						 this->numericUpDown21->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->numericUpDown20->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->numericUpDown19->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->comboBox8->SelectedIndex = Convert::ToInt32( line ); 
							line = sr->ReadLine();
						 this->numericUpDown29->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->numericUpDown31->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->numericUpDown33->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->numericUpDown34->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->numericUpDown30->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->numericUpDown32->Value = Convert::ToDecimal( line ); 
 						line = sr->ReadLine();
						 this->numericUpDown28->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->comboBox6->SelectedIndex = Convert::ToInt32( line ); 
							line = sr->ReadLine();
							this->numericUpDown24->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->numericUpDown25->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->numericUpDown26->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->numericUpDown27->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->maskedTextBox10->Text = Convert::ToString( line );
							line = sr->ReadLine();
						 this->maskedTextBox9->Text = Convert::ToString( line );
							line = sr->ReadLine();
						 this->numericUpDown23->Value = Convert::ToDecimal( line ); 
							line = sr->ReadLine();
						 this->numericUpDown22->Value = Convert::ToDecimal( line ); 

       // LSB file
							line = sr->ReadLine();
							this->radioButton8->Checked = Convert::ToBoolean( line ); 
							line = sr->ReadLine();
						 this->radioButton7->Checked = Convert::ToBoolean( line );   
							line = sr->ReadLine();
						 this->radioButton6->Checked = Convert::ToBoolean( line );

							// Founded pos
							line = sr->ReadLine();
						 this->checkBox37->Checked = Convert::ToBoolean( line ); 
							line = sr->ReadLine();
						 this->checkBox38->Checked = Convert::ToBoolean( line );  
							line = sr->ReadLine();
						 this->checkBox50->Checked = Convert::ToBoolean( line );   
							line = sr->ReadLine();
						 this->checkBox46->Checked = Convert::ToBoolean( line );   
							line = sr->ReadLine();
						 this->checkBox45->Checked = Convert::ToBoolean( line );   
							line = sr->ReadLine();
						 this->radioButton37->Checked = Convert::ToBoolean( line );   
							line = sr->ReadLine();
						 this->radioButton36->Checked = Convert::ToBoolean( line );   
							line = sr->ReadLine();
						 this->radioButton35->Checked = Convert::ToBoolean( line );   
							line = sr->ReadLine();
						 this->radioButton34->Checked = Convert::ToBoolean( line );   
							line = sr->ReadLine();
							this->numericUpDown72->Value = Convert::ToDecimal( line );    


						 // Split merge
							line = sr->ReadLine();
						 this->checkBox19->Checked = Convert::ToBoolean( line );   
							line = sr->ReadLine();
						 this->checkBox20->Checked = Convert::ToBoolean( line );  
							line = sr->ReadLine();
						 this->checkBox21->Checked = Convert::ToBoolean( line );    
							line = sr->ReadLine();
						 this->numericUpDown79->Value = Convert::ToInt32( line );
							line = sr->ReadLine();
						 this->maskedTextBox44->Text = Convert::ToString( line );  
							line = sr->ReadLine();
						 this->maskedTextBox46->Text = Convert::ToString( line );  
							line = sr->ReadLine();
						 this->numericUpDown80->Value = Convert::ToInt32( line );  
							line = sr->ReadLine();
						 this->maskedTextBox45->Text = Convert::ToString( line ); 
							line = sr->ReadLine();
						 this->numericUpDown75->Value = Convert::ToInt32( line );
							line = sr->ReadLine();
						 this->numericUpDown73->Value = Convert::ToInt32( line );
							line = sr->ReadLine();
						 this->numericUpDown74->Value = Convert::ToInt32( line );
							line = sr->ReadLine();
						 this->numericUpDown76->Value = Convert::ToInt32( line );
							line = sr->ReadLine();
						 this->numericUpDown81->Value = Convert::ToInt32( line );
							line = sr->ReadLine();
						 this->numericUpDown77->Value = Convert::ToInt32( line );
							line = sr->ReadLine();
						 this->numericUpDown78->Value = Convert::ToInt32( line );
							line = sr->ReadLine();
						 this->comboBox23->SelectedIndex = Convert::ToInt32( line );  //TM
							line = sr->ReadLine();
						 this->numericUpDown86->Value = Convert::ToInt32( line );
							line = sr->ReadLine();
						 this->numericUpDown87->Value = Convert::ToInt32( line );
							line = sr->ReadLine();
						 this->maskedTextBox47->Text = Convert::ToString( line );  
							line = sr->ReadLine();
						 this->numericUpDown83->Value = Convert::ToInt32( line ); 
							line = sr->ReadLine();
						 this->numericUpDown85->Value = Convert::ToInt32( line ); 
							line = sr->ReadLine();
						 this->numericUpDown84->Value = Convert::ToInt32( line ); 
							line = sr->ReadLine();
						 this->numericUpDown82->Value = Convert::ToInt32( line ); 


   }
			catch( Exception^ err )
			{
       MessageBox::Show( "Error in SET data file reading: "+err->Message,"SET data reading.", MessageBoxButtons::OK );
			}
   finally
   {
				  sr->Close();
      if ( sr )
         delete (IDisposable^)sr;
			}


}// private: System::Void button50_Click(System::Object^  sender, System::EventArgs^  e) {

private: System::Void button48_Click(System::Object^  sender, System::EventArgs^  e) {
// PROPERTIES FACTORY settings

String^ line = "";
Boolean ErrStatus = false;

//***************************************

   try
   {

       // AutoReload at start ?
							this->checkBox57->Checked = false;

							// RUN
       this->checkBox44->Checked = true;     // draw map pattern
							this->comboBox13->SelectedIndex = -1;
							this->numericUpDown35->Value = 1;

							// draw
							this->checkBox30->Checked = false; 
							this->checkBox31->Checked = true;
							this->checkBox32->Checked = false;
							this->checkBox34->Checked = false;
							this->checkBox35->Checked = false;
							this->checkBox36->Checked = false;
							this->checkBox25->Checked = false;
							this->checkBox27->Checked = false;
							this->checkBox26->Checked = false;
							this->checkBox24->Checked = false;
							this->checkBox23->Checked = false;
							this->checkBox22->Checked = false;
							this->checkBox33->Checked = false;
						 this->numericUpDown59->Value = 70;
						 this->checkBox29->Checked = true;
						 this->checkBox48->Checked = false;
						 this->trackBar5->Value = 5;
						 this->checkBox40->Checked = false;
						 this->checkBox52->Checked = false;

							// Scanner
						 this->radioButton4->Checked = false;
						 this->radioButton5->Checked = true;
						 this->maskedTextBox8->Text = "0,00983";
						 this->numericUpDown21->Value = 1;
						 this->numericUpDown20->Value = 1;
						 this->numericUpDown19->Value = 80;
						 this->comboBox8->SelectedIndex = 2;
						 this->numericUpDown29->Value = 15;
						 this->numericUpDown31->Value = 15;
						 this->numericUpDown33->Value = 15;
						 this->numericUpDown34->Value = 15;
						 this->numericUpDown30->Value = 1;
						 this->numericUpDown32->Value = 1;
						 this->numericUpDown28->Value = 15;
						 this->comboBox6->SelectedIndex = 0;
							this->numericUpDown24->Value = 60;
						 this->numericUpDown25->Value = 60;
						 this->numericUpDown26->Value = 60;
						 this->numericUpDown27->Value = 60;
						 this->maskedTextBox10->Text = "0,6";
							this->maskedTextBox9->Text = "1";
						 this->numericUpDown23->Value = 15;
						 this->numericUpDown22->Value = 1500;
		
       // LSB file
							this->radioButton8->Checked = true;
						 this->radioButton7->Checked = false;
						 this->radioButton6->Checked = false;

							// Founded pos
						 this->checkBox37->Checked = false;
						 this->checkBox38->Checked = false;
						 this->checkBox50->Checked = true;
						 this->checkBox46->Checked = false;
						 this->checkBox45->Checked = true;
						 this->radioButton37->Checked = false;
						 this->radioButton36->Checked = true;
						 this->radioButton35->Checked = false;
						 this->radioButton34->Checked = false;
							this->numericUpDown72->Value = 9; 

					  // Split merge
						 this->checkBox19->Checked = true;
						 this->checkBox20->Checked = true;
						 this->checkBox21->Checked = true;  
						 this->numericUpDown79->Value = 15;
						 this->maskedTextBox44->Text = "0,45";
						 this->maskedTextBox46->Text = "0,5";
						 this->numericUpDown80->Value = 15;
						 this->maskedTextBox45->Text = "0,084";
						 this->numericUpDown75->Value = 15;
						 this->numericUpDown73->Value = 15;
						 this->numericUpDown74->Value = 15;
						 this->numericUpDown76->Value = 15;
						 this->numericUpDown81->Value = 15;
						 this->numericUpDown77->Value = 10;
						 this->numericUpDown78->Value = 10;
						 this->comboBox23->SelectedIndex = 0; //TM
						 this->numericUpDown86->Value = 10;
						 this->numericUpDown87->Value = 10;
						 this->maskedTextBox47->Text = "0,35";
						 this->numericUpDown83->Value = 15;
						 this->numericUpDown85->Value = 15;
						 this->numericUpDown84->Value = 15;
						 this->numericUpDown82->Value = 15;
      
   }
			catch( Exception^ err )
			{
       MessageBox::Show( "Internal error at SET data.: "+err->Message,"SET data.", MessageBoxButtons::OK );
			}
   finally
   {

			}

}// private: System::Void button48_Click(System::Object^  sender, System::EventArgs^  e) {


//*********************************************************************************************
//                                     ALGORITHMS 
//                 DETECTOR + SCANNER + BEAMSELECTOR + IMPROVER + CORRECTOR
//*********************************************************************************************

private: System::Byte createTemporaryMap_fromGlobalMap(Int32 Item){
//  Compute EpsT from actual point Ds

  	const double doublePI = Math::PI * 2;

   double coefLS = 0;
			UInt32 coef2PIBeams = 0;
			UInt32	coefDmCount = 0;

			double R1=0;
  	double R2=0;
	  double R3=0;
	  double R4=0;
	  double R5=0;
		 double R6=0;
			double R7=0;
			double R8=0;
			double R9=0;
			double R10=0;
			double R11=0;
			double R12=0;
			double R13=0;

			double EpsT = 0;

			Int32 RI1=0;
			Int32 RI2=0;

			double xp=0;
			double yp=0;

			double Lsmin=0;
			double Ls=0;
			double ABDet;
			double t=0;

   double coefX=0;
	  double coefY=0;
			
			double minX=0;
			double minY=0;
			double maxX=0;
			double maxY=0;

			double scanLocalOptimum=0;
 		double scanLocalX=0;
			double scanLocalY=0;
			double scanLocalAngle=0; 
			double scanLocalAngleUnits=0; 

			UInt32 ComparingAlgorithm=0;

 		UInt32 StartItem = 0;

   double SAminX = 0;
			double SAminY = 0;
			double SAmaxX = 0;
			double SAmaxY = 0;
			double SAstepX = 0;
			double SAstepY = 0;
			double SAstepPoints = 0;
			double SAstartAngle = 0;
			double SAstopAngle = 0;
   double SAstepAngle = 0;

			double EvaluationLimit = 0;
			UInt32 ProbablyPoseGroup = 0;
			double PoseCounter = 0;
			double GroupSumEvaluation = 0;

			Int32 StepDs = 0;
			Int32 StepDe = 0;

			Int32 g = 0;

			String^ line = "";

			List<Object^>^ ScannedPoints = gcnew List<Object^>();

	  List<Object^>^ BeamArray; 
	  List<Object^>^ ApproxLinesArray;

			//********************************************************************************
			// COMPUTE BEAMS
			//********************************************************************************

			cLSTechInfo^ LSTechInfo = gcnew cLSTechInfo(); // vola staticky konstruktor mel by to nacist ze souboru

			StepDs = 1;  //
		 StepDe = 1;  //


			if ( Math::Round( g_Ds_DetectionAngle, 5 ) == Math::Round( doublePI, 5 ) ){

   			coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
			   coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
			   coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081

			} else
			{
   			coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
			   coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
			   coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081
			}// if else


			// create BEAMS
			for (UInt32 i=0;i<=Convert::ToUInt32( coef2PIBeams-1 );i=i+1){ 

				   c104LSBeamItem^ LSBeamItem = gcnew c104LSBeamItem();

							LSBeamItem->PolarLength = LSTechInfo->LSRange;
       LSBeamItem->CalculatedLength = 0;
							LSBeamItem->cosX = ( Math::Cos( Convert::ToDouble(i)*coefLS )* LSBeamItem->PolarLength );
							LSBeamItem->sinY = ( Math::Sin( Convert::ToDouble(i)*coefLS )* LSBeamItem->PolarLength );
																                    
							g_DmLSArray->Add( LSBeamItem ); 
																   
			}// for


     		if ( g_DebugMode == true ){
							   Application::DoEvents(); 
							}// if 

       // searching points
       ROBOMAP::c104SimPosItem^ p = gcnew c104SimPosItem();
       p->X = gs_RPose.posX;
       p->Y = gs_RPose.posY;
 						p->Evaluation = double::MaxValue;  
	      ScannedPoints->Add(p);


				   // SCANNED AREA POINTS ONE POINT ONLY
							g=0;


											// bema bunch to correct pose in map
		         for (UInt32 i = 0; i < Convert::ToUInt32(g_DmLSArray->Count); i = i + 1){  //create all beams, base index is 0
			
							   			  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 = ( safe_cast<c104SimPosItem^>(ScannedPoints[g])->X );
	 				         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 = ( safe_cast<c104SimPosItem^>(ScannedPoints[g])->Y );
							
															safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 = ( safe_cast<c104SimPosItem^>(ScannedPoints[g])->X + safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->cosX );
							        safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2 = ( safe_cast<c104SimPosItem^>(ScannedPoints[g])->Y + safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->sinY );

         				  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 - safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2;
							        safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 - safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1;
               safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->c1 = (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2) -
        								                                               (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1);

		             if (	safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 > safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 ){
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 - g_WindowTolerance; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 + g_WindowTolerance; 
 						        } else
							        {
							             safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1; 
							 		          safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 - g_WindowTolerance; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 + g_WindowTolerance;
								       }// if else
               if (	safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 > safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2 ){
									           safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 - g_WindowTolerance; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 + g_WindowTolerance; 
								       } else
								       {
									           safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 - g_WindowTolerance; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 + g_WindowTolerance; 
								       }// if else

			        }// for (int i=0;i<=Convert::ToUInt32(paramNumberOfBeams-1)


											// pro vsechny paprsky vypocitej vzdalenost ke zdi 
											for (UInt32 i=0; i < Convert::ToUInt32(g_DmLSArray->Count); i++){ // for all beams

											   	Lsmin = Convert::ToDouble( LSTechInfo->LSRange );

															for (UInt32 j=0; j <= Convert::ToUInt32(g_GlobalMap->Count-1); j++){ // for all walls

											
											        //  vypocet ABDet
                   if ( 	( ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_GlobalMap[j])->u1 ) +
             												  ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_GlobalMap[j])->u2 ) ) == 0 ){
								        								ABDet = 0;
											        } else
											        {
																        ABDet = 1;
        											}// if
           

          									if ( ABDet != 0 ){

							               // do obecne rovnice paprsku dosadime parametricke rovnice steny a vypocteme parametr t
												          t = ( ( (-1) * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->c1) - 
																            ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_GlobalMap[j])->Y1) -
																			         ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_GlobalMap[j])->X1) ) /
																			       ( ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_GlobalMap[j])->u1 ) +
																			         ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_GlobalMap[j])->u2 ) );

                      // parametr t dosadime do parametricke rovnice steny a vypoceteme prusecik
															       xp = ( safe_cast<c100LineItem^>(g_GlobalMap[j])->X1 + (safe_cast<c100LineItem^>(g_GlobalMap[j])->u1 * t) );
															       yp = ( safe_cast<c100LineItem^>(g_GlobalMap[j])->Y1 + (safe_cast<c100LineItem^>(g_GlobalMap[j])->u2 * t) );
											
																						// test zda prusecik paprsku a steny lezi uvnitr usecky paprsku a steny zaroven +/- g_WindowTolerance
 														       if ( xp>=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1) && 
																           xp<=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2) && 
																				       xp>=(safe_cast<c100LineItem^>(g_GlobalMap[j])->Wx1) && 
																				       xp<=(safe_cast<c100LineItem^>(g_GlobalMap[j])->Wx2) && 
																				       yp>=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1) && 
																				       yp<=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2) && 
																				       yp>=(safe_cast<c100LineItem^>(g_GlobalMap[j])->Wy1) && 
																				       yp<=(safe_cast<c100LineItem^>(g_GlobalMap[j])->Wy2) ){
																									                       
 											  				         Ls = Math::Sqrt( Math::Pow( (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 - xp), 2) +
																					                       Math::Pow( (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 - yp), 2) );

														          			if ( Ls < Lsmin ){
  	    	 										             Lsmin = Ls;
			    	 						            }// if ( Ls < Lsmin )

											           }//if ( xp>=Bx1 && xp<=Bx2 && xp>=Wx1 && xp<=Wx2 && yp>=By1 && yp<=By2 && yp>=Wy1 && yp<=Wy2 )

											       }// if ( ABDet != 0 )

           	  }// for (int j=0;j<=(h_LinesArray->Count-1);j++)
														
              safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->CalculatedLength = Lsmin;

          }// for (int i=0; i <= (coef2PIBeams-1); i++)


												// vycisti Temporary map 
											 for (Int32 i=0;i<Convert::ToInt32( g_TemporaryMap->Count );i++){
													   delete( safe_cast<c100LineItem^>(g_TemporaryMap[i]) );
			         }// for 
			         g_TemporaryMap->Clear();


	 	  BeamArray = gcnew List<Object^>;
		   ApproxLinesArray = gcnew List<Object^>(); 


 		 	for ( Int32 i=0;i<Convert::ToInt32( g_DmLSArray->Count );i++){

		   		  ROBOMAP::c100LSRayBunchItem^ Beam = gcnew c100LSRayBunchItem();

				  			Beam->PolarLength =  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->CalculatedLength;
						  	Beam->X = Math::Cos(coefLS*Convert::ToDouble(i)) * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->CalculatedLength;
							  Beam->Y = Math::Sin(coefLS*Convert::ToDouble(i)) * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->CalculatedLength;
 						  Beam->Status = 0; 
							  Beam->PosIndex = i; 

							  BeamArray->Add(Beam); 

			  }// for

					// create submap for local orientaton
     c100MultiLineApproximationA^ R = gcnew c100MultiLineApproximationA(BeamArray, ApproxLinesArray, nullptr ); // nullptr = use all 361 beams 
					R->g_distanceLimit_pointTopoint = Convert::ToDouble( this->numericUpDown86->Value ); 
					R->g_distanceLimit_pointToLine  = Convert::ToDouble( this->numericUpDown87->Value ); 
					R->Run();
			 	delete( R );


		   for ( Int32 i=0;i < Convert::ToInt32( BeamArray->Count );i++){
         delete( safe_cast<c100LSRayBunchItem^>(BeamArray[i]) );
			  }// for
			  BeamArray->Clear();

				 //R7 = gs_RPose.Angle_RAD - (g_Ds_DetectionAngle/2);
		   for (Int32 i=0;i<Convert::ToInt32( ApproxLinesArray->Count );i++){

			      R1 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->X1; // 
		 			   R2 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->Y1;

							  R3 = R1 + gs_RPose.posX;
							  R4 = R2 + gs_RPose.posY;

						   R1 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->X2; //  
		 			   R2 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->Y2;

									R5 = R1 + gs_RPose.posX;
									R6 = R2 + gs_RPose.posY;

				     ROBOMAP::c100LineItem^ LineItem = gcnew c100LineItem();

							  LineItem->X1 = R3;
							  LineItem->Y1 = R4;
							  LineItem->X2 = R5;
							  LineItem->Y2 = R6; 

							  LineItem->diffX  = ( LineItem->X2 - LineItem->X1 );
							  LineItem->diffY  = ( LineItem->Y1 - LineItem->Y2 );
							  LineItem->LengthSQR = Math::Pow( (LineItem->X2 - LineItem->X1),2 ) +  Math::Pow( (LineItem->Y2 - LineItem->Y1),2 );
							  LineItem->Length = Math::Sqrt( LineItem->LengthSQR ); 

							  LineItem->u1 = ( LineItem->X2 - LineItem->X1 );
							  LineItem->u2 = ( LineItem->Y2 - LineItem->Y1 );

         if (	LineItem->X1 > LineItem->X2 ){
								    LineItem->Wx1 = LineItem->X2; 
            LineItem->Wx2 = LineItem->X1; 
										  LineItem->Wx1 = LineItem->Wx1 - g_WindowTolerance; 
            LineItem->Wx2 = LineItem->Wx2 + g_WindowTolerance; 
							  } else
						   {
			 				    LineItem->Wx1 = LineItem->X1; 
            LineItem->Wx2 = LineItem->X2; 
  										LineItem->Wx1 = LineItem->Wx1 - g_WindowTolerance; 
            LineItem->Wx2 = LineItem->Wx2 + g_WindowTolerance; 
         }// if else
							  if (	LineItem->Y1 > LineItem->Y2 ){
										  LineItem->Wy1 = LineItem->Y2; 
            LineItem->Wy2 = LineItem->Y1;
										  LineItem->Wy1 = LineItem->Wy1 - g_WindowTolerance; 
            LineItem->Wy2 = LineItem->Wy2 + g_WindowTolerance;
					    } else
							  {
									  	LineItem->Wy1 = LineItem->Y1; 
            LineItem->Wy2 = LineItem->Y2;
 									  LineItem->Wy1 = LineItem->Wy1 - g_WindowTolerance; 
            LineItem->Wy2 = LineItem->Wy2 + g_WindowTolerance;
							  }// if else

							  LineItem->a2 = LineItem->Y1 - LineItem->Y2; 
							  LineItem->b2 = LineItem->X2 - LineItem->X1;
							  LineItem->c2 = (LineItem->X1*LineItem->Y2)-(LineItem->X2*LineItem->Y1); 

							  LineItem->a1 = LineItem->a2;  // doplneno pro COXe tri radky
							  LineItem->b1 = LineItem->b2;  //
							  LineItem->c1 = LineItem->c2;  //

							  g_TemporaryMap->Add( LineItem ); //

   		}// for


					if ( g_TemporaryMap->Count == 0 ) {
						  MessageBox::Show( "Temporary map from GM has 0 lines","Error ...", MessageBoxButtons::OK ); 
					}// 


	  for (Int32 i=0;i<Convert::ToInt32( ApproxLinesArray->Count );i++){
		     delete( safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i]) );
		 }// for 
			ApproxLinesArray->Clear();

			for ( Int32 i=0;i<Convert::ToInt32(ScannedPoints->Count);i=i+1 ){
		     delete( safe_cast<c104SimPosItem^>( ScannedPoints[i] ) );
	  }//	for ( UInt32 i=0;i<Convert::ToUInt32(ScannedPoints->Count);i=i+1 )
		 ScannedPoints->Clear();

   delete( LSTechInfo );
			delete( BeamArray ); 
	  delete( ApproxLinesArray );

		 for each(c104LSBeamItem^ i in g_DmLSArray ){
   			 delete( safe_cast<c104LSBeamItem^>(i) );
			}// for
			g_DmLSArray->Clear();

			return 0;

}// private: System::Byte createTemporaryMap_fromGlobalMap(Int32 Item)

private: System::Byte createTemporaryMap_fromLastScan(Int32 Item){
// Compute EpsT from actual point Ds

  	const double doublePI = Math::PI * 2;

   double coefLS = 0;
			UInt32 coef2PIBeams = 0;
			UInt32	coefDmCount = 0;

			double R1=0;
  	double R2=0;
	  double R3=0;
	  double R4=0;
	  double R5=0;
		 double R6=0;
			double R7=0;
			double R8=0;
			double R9=0;
			double R10=0;
			double R11=0;
			double R12=0;
			double R13=0;

			double EpsT = 0;

			Int32 RI1=0;
			Int32 RI2=0;

			double xp=0;
			double yp=0;

			double Lsmin=0;
			double Ls=0;
			double t=0;

   double coefX=0;
	  double coefY=0;
			
			double minX=0;
			double minY=0;
			double maxX=0;
			double maxY=0;

			double scanLocalOptimum=0;
 		double scanLocalX=0;
			double scanLocalY=0;
			double scanLocalAngle=0; 
			double scanLocalAngleUnits=0; 

			UInt32 ComparingAlgorithm=0;

 		UInt32 StartItem = 0;

   double SAminX = 0;
			double SAminY = 0;
			double SAmaxX = 0;
			double SAmaxY = 0;
			double SAstepX = 0;
			double SAstepY = 0;
			double SAstepPoints = 0;
			double SAstartAngle = 0;
			double SAstopAngle = 0;
   double SAstepAngle = 0;

			double EvaluationLimit = 0;
			UInt32 ProbablyPoseGroup = 0;
			double PoseCounter = 0;
			double GroupSumEvaluation = 0;

			Int32 StepDs = 0;
			Int32 StepDe = 0;

			Int32 g = 0;

			String^ line = "";

			List<Object^>^ ScannedPoints = gcnew List<Object^>();

	  List<Object^>^ BeamArray; 
	  List<Object^>^ ApproxLinesArray;

			//********************************************************************************
			// 
			//********************************************************************************


			cLSTechInfo^ LSTechInfo = gcnew cLSTechInfo(); // vola staticky konstruktor mel by to nacist ze souboru


			if ( Math::Round( g_Ds_DetectionAngle, 5 ) == Math::Round( doublePI, 5 ) ){

   			coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
			   coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
			   coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081

			} else
			{
   			coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
			   coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
			   coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081
			}// if else


												// vycisti Temporary map 
											 for (Int32 i=0;i<Convert::ToInt32( g_TemporaryMap->Count );i++){
													   delete( safe_cast<c100LineItem^>(g_TemporaryMap[i]) );
			         }// for 
			         g_TemporaryMap->Clear();


	 	  BeamArray = gcnew List<Object^>;
		   ApproxLinesArray = gcnew List<Object^>(); 

					if ( Item == 0 ){
        RI1 = Item; 
					} else
					{
        RI1 = Item-1; 
					}// if else 

			  for ( Int32 i=0;i<g_RBeams->Length;i++){
						   if ( safe_cast<c104LSScan^>( g_DsLSArray[ RI1 ] )->LSItemPolar[i]->Correct == true ){
				        g_RBeams[i] = true;
									} else
					 			{
				        g_RBeams[i] = false;
									}// if 
     }// for i



 		 	for ( Int32 i=0; i < Convert::ToInt32( safe_cast<c104LSScan^>( g_DsLSArray[ RI1 ] )->LSItemXY->Length );i++){

		   		  ROBOMAP::c100LSRayBunchItem^ Beam = gcnew c100LSRayBunchItem();

				  			Beam->PolarLength = safe_cast<c104LSScan^>( g_DsLSArray[ RI1 ] )->LSItemPolar[i]->PolarLength ;
						  	Beam->X = safe_cast<c104LSScan^>( g_DsLSArray[ RI1 ] )->LSItemXY[i]->X;
							  Beam->Y = safe_cast<c104LSScan^>( g_DsLSArray[ RI1 ] )->LSItemXY[i]->Y;
 						  Beam->Status = 0; 
							  Beam->PosIndex = i; 

							  BeamArray->Add(Beam); 

			  }// for

					// create submap for local orientaton
     //c100MultiLineApproximationA^ R = gcnew c100MultiLineApproximationA(BeamArray, ApproxLinesArray, nullptr ); // nullptr = use all 361 beams 
     c100MultiLineApproximationA^ R = gcnew c100MultiLineApproximationA(BeamArray, ApproxLinesArray, g_RBeams ); // nullptr = use all 361 beams 
					R->g_distanceLimit_pointTopoint = Convert::ToDouble( this->numericUpDown86->Value ); 
					R->g_distanceLimit_pointToLine  = Convert::ToDouble( this->numericUpDown87->Value ); 
					R->Run();
			 	delete( R );

		   for ( Int32 i=0;i < Convert::ToInt32( BeamArray->Count );i++){
         delete( safe_cast<c100LSRayBunchItem^>(BeamArray[i]) );
			  }// for
			  BeamArray->Clear();

				 R7 = gs_RPose.Angle_RAD - (g_Ds_DetectionAngle/2);
		   for (Int32 i=0;i<Convert::ToInt32( ApproxLinesArray->Count );i++){

			      R1 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->X1; // 
		 			   R2 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->Y1;

							  R3 = ((R1 * Math::Cos( R7 )) - (R2 * Math::Sin( R7 ))) + gs_RPose.posX;
							  R4 = ((R1 * Math::Sin( R7 )) + (R2 * Math::Cos( R7 ))) + gs_RPose.posY;

							  //R3 = R1 + gs_RPose.posX;
							  //R4 = R2 + gs_RPose.posY;

						   R1 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->X2; //  
		 			   R2 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->Y2;

							  R5 = ((R1 * Math::Cos( R7 )) - (R2 * Math::Sin( R7 ))) + gs_RPose.posX;
						  	R6 = ((R1 * Math::Sin( R7 )) + (R2 * Math::Cos( R7 ))) + gs_RPose.posY;

				     ROBOMAP::c100LineItem^ LineItem = gcnew c100LineItem();

							  LineItem->X1 = R3;
							  LineItem->Y1 = R4;
							  LineItem->X2 = R5;
							  LineItem->Y2 = R6; 

							  LineItem->diffX  = ( LineItem->X2 - LineItem->X1 );
							  LineItem->diffY  = ( LineItem->Y1 - LineItem->Y2 );
							  LineItem->LengthSQR = Math::Pow( (LineItem->X2 - LineItem->X1),2 ) +  Math::Pow( (LineItem->Y2 - LineItem->Y1),2 );
							  LineItem->Length = Math::Sqrt( LineItem->LengthSQR ); 

							  LineItem->u1 = ( LineItem->X2 - LineItem->X1 );
							  LineItem->u2 = ( LineItem->Y2 - LineItem->Y1 );

         if (	LineItem->X1 > LineItem->X2 ){
								    LineItem->Wx1 = LineItem->X2; 
            LineItem->Wx2 = LineItem->X1; 
										  LineItem->Wx1 = LineItem->Wx1 - g_WindowTolerance; 
            LineItem->Wx2 = LineItem->Wx2 + g_WindowTolerance; 
							  } else
						   {
			 				    LineItem->Wx1 = LineItem->X1; 
            LineItem->Wx2 = LineItem->X2; 
  										LineItem->Wx1 = LineItem->Wx1 - g_WindowTolerance; 
            LineItem->Wx2 = LineItem->Wx2 + g_WindowTolerance; 
         }// if else
							  if (	LineItem->Y1 > LineItem->Y2 ){
										  LineItem->Wy1 = LineItem->Y2; 
            LineItem->Wy2 = LineItem->Y1;
										  LineItem->Wy1 = LineItem->Wy1 - g_WindowTolerance; 
            LineItem->Wy2 = LineItem->Wy2 + g_WindowTolerance;
					    } else
							  {
									  	LineItem->Wy1 = LineItem->Y1; 
            LineItem->Wy2 = LineItem->Y2;
 									  LineItem->Wy1 = LineItem->Wy1 - g_WindowTolerance; 
            LineItem->Wy2 = LineItem->Wy2 + g_WindowTolerance;
							  }// if else

							  LineItem->a2 = LineItem->Y1 - LineItem->Y2; 
							  LineItem->b2 = LineItem->X2 - LineItem->X1;
							  LineItem->c2 = (LineItem->X1*LineItem->Y2)-(LineItem->X2*LineItem->Y1); 

							  LineItem->a1 = LineItem->a2;  // doplneno pro COXe tri radky
							  LineItem->b1 = LineItem->b2;  //
							  LineItem->c1 = LineItem->c2;  //

							  g_TemporaryMap->Add( LineItem ); //

   		}// for


	  for (Int32 i=0;i<Convert::ToInt32( ApproxLinesArray->Count );i++){
		     delete( safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i]) );
		 }// for 
			ApproxLinesArray->Clear();

			for ( Int32 i=0;i<Convert::ToInt32(ScannedPoints->Count);i=i+1 ){
		     delete( safe_cast<c104SimPosItem^>( ScannedPoints[i] ) );
	  }//	for ( UInt32 i=0;i<Convert::ToUInt32(ScannedPoints->Count);i=i+1 )
		 ScannedPoints->Clear();

   delete( LSTechInfo );
			delete( BeamArray ); 
	  delete( ApproxLinesArray );

		 for each(c104LSBeamItem^ i in g_DmLSArray ){
   			 delete( safe_cast<c104LSBeamItem^>(i) );
			}// for
			g_DmLSArray->Clear();

		
			return 0;

}// private: System::Byte createTemporaryMap_fromLastScan(Int32 Item)


private: System::Byte A_02_01( Int32 Item ){
// SCANNER Brute Force DS/MAE-1,2

  	const double doublePI = Math::PI * 2;

   double coefLS = 0;
			UInt32 coef2PIBeams = 0;
			UInt32	coefDmCount = 0;

			double R1=0;
  	double R2=0;
	  double R3=0;
	  double R4=0;
	  double R5=0;
		 double R6=0;
			double R7=0;
			double R8=0;
			double R9=0;
			double R10=0;
			double R11=0;
			double R12=0;
			double R13=0;


			UInt32 RI1=0;
			UInt32 RI2=0;

			double xp=0;
			double yp=0;

			double Lsmin=0;
			double Ls=0;
			double ABDet;
			double t=0;

   double coefX=0;
	  double coefY=0;
			
			double minX=0;
			double minY=0;
			double maxX=0;
			double maxY=0;

			double scanLocalOptimum=0;
 		double scanLocalX=0;
			double scanLocalY=0;
			double scanLocalAngle=0; 

			UInt32 ComparingAlgorithm=0;
			UInt32 SearchingMethod_HC = 0;

 		Byte DebugMode = 0;

			UInt32 StartItem = 0;

			double EpsT = 0;
			Int32 ScanAngleNumber = 0;

			double LocalOptimum;

			double PosX = 0;
			double PosY = 0;
			double BestAngle = 0;

   double SAminX = 0;
			double SAminY = 0;
			double SAmaxX = 0;
			double SAmaxY = 0;
			double SAstepX = 0;
			double SAstepY = 0;
			double SAstepPoints = 0;
			double SAstartAngle = 0;
			double SAstopAngle = 0;
   double SAstepAngle = 0;

		 //	double EvaluationLimit = 0;
			UInt32 ProbablyPoseGroup = 0;
			double PoseCounter = 0;
			double GroupSumEvaluation = 0;

		 Boolean ExitStatus = false;

			Int32 StepDs = 0;
			Int32 StepDe = 0;

			String^ line = "";

			List<Object^>^ ScannedPoints = gcnew List<Object^>();

			//********************************************************************************
			// CONTINUAL LOCALIZATION 
			//********************************************************************************
		
	      this->label86->Text = "Algorithm: SCANNER - DS/MAE+BF";
							this->label86->Refresh(); 


			cLSTechInfo^ LSTechInfo = gcnew cLSTechInfo(); // vola staticky konstruktor mel by to nacist ze souboru

			scanLocalOptimum = 0;

			if ( this->comboBox8->SelectedIndex == 0 ){
			   ComparingAlgorithm = 0;   // DS-mae 1
			} else if ( this->comboBox8->SelectedIndex == 1 ){
      ComparingAlgorithm = 1;   // DS-mae 2
			} else
		 {
				  ComparingAlgorithm = 0;
      MessageBox::Show( this, "Suspicious behaviour [ A_02_01 ]","Parameters checker.", MessageBoxButtons::OK );
			}// if else


   // Way of EpsT evaluation
   if ( this->radioButton4->Checked == true ){
 					g_EpsTdummy = Convert::ToDouble( this->maskedTextBox8->Text );  
						g_EpsTSel = 2; // Ds only
			} else if ( this->radioButton5->Checked == true ){
				  g_EpsTdummy = Convert::ToDouble( this->maskedTextBox8->Text );  
      g_EpsTSel = 3; // De+Ds
			} else
			{
				  g_EpsT = Convert::ToDouble( this->maskedTextBox8->Text );  
      g_EpsTSel = 3; // De+Ds
			}// if else
			

			StepDs = Convert::ToInt32( this->numericUpDown21->Value ); // Dm = Ds
		 StepDe = Convert::ToInt32( this->numericUpDown20->Value ); // Ds = De

			ScanAngleNumber = Convert::ToInt32( this->numericUpDown19->Value );  

			if ( Math::Abs( g_Ds_DetectionAngle - doublePI ) < 0.00001 ){

   			coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
			   coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
			   coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081

			} else
			{
   			coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
			   coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
			   coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081
			}// if else

			// create BEAMS
			R1 = (gs_RPose.Angle_RAD-(g_Ds_DetectionAngle/2)-(ScanAngleNumber*coefLS) );
			R2 = (gs_RPose.Angle_RAD+(g_Ds_DetectionAngle/2)+(ScanAngleNumber*coefLS) );
   for (double i=R1;i<=R2;i=i+coefLS){ 

				   c104LSBeamItem^ LSBeamItem = gcnew c104LSBeamItem();

							LSBeamItem->PolarLength = LSTechInfo->LSRange;
       LSBeamItem->CalculatedLength = 0;
							LSBeamItem->cosX = ( Math::Cos( i )* LSBeamItem->PolarLength );
							LSBeamItem->sinY = ( Math::Sin( i )* LSBeamItem->PolarLength );
							LSBeamItem->BeamAngle = i;

							g_DmLSArray->Add( LSBeamItem ); 
																   
			}// for



			       SAminX = Convert::ToDouble( this->numericUpDown33->Value );    // hledaci oblast minX
		        SAminY = Convert::ToDouble( this->numericUpDown34->Value );    // hledaci oblast minY
			       SAmaxX = Convert::ToDouble( this->numericUpDown31->Value );    // hledaci oblast maxX
			       SAmaxY = Convert::ToDouble( this->numericUpDown29->Value );    // hledaci oblast maxY
          SAstepX = Convert::ToDouble( this->numericUpDown30->Value );   // hledaci oblast stepX
          SAstepY = Convert::ToDouble( this->numericUpDown32->Value );   // hledaci oblast stepY

			       SAminX = gs_RPose.posX - SAminX;
		        SAminY = gs_RPose.posY - SAminY;
			       SAmaxX = gs_RPose.posX + SAmaxX;
		       	SAmaxY = gs_RPose.posY + SAmaxY;

          // searching points
							   for ( Int32 i=Convert::ToInt32(SAminX);i<=Convert::ToInt32(SAmaxX);i=i+Convert::ToInt32( SAstepX )){
	             for ( Int32 j=Convert::ToInt32(SAminY);j<=Convert::ToInt32(SAmaxY);j=j+Convert::ToInt32( SAstepY )){

	                 ROBOMAP::c104SimPosItem^ p = gcnew c104SimPosItem();
								          p->X = i;
								          p->Y = j;
															   p->Evaluation = double::MaxValue;  
				              ScannedPoints->Add(p);

 							      }// for
          }// for


				   // SCANNED AREA POINTS
							PoseCounter = 0;
							GroupSumEvaluation = 0;
							for ( UInt32 g=0;g<Convert::ToUInt32(ScannedPoints->Count);g=g+1){

					      this->label87->Text = "Point: "+Convert::ToString(g)+"  [ "+Convert::ToString(ScannedPoints->Count)+" ]  ";
							    this->label87->Refresh(); 


     		    if ( g_DebugMode == true ){
							       Application::DoEvents(); 
							    }// if 


											// place oll noname beams to correct robot's pose in map
        			for (UInt32 i = 0; i < Convert::ToUInt32(g_DmLSArray->Count); i = i + 1){  //create all beams, base index is 0
			
							   			  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 = ( safe_cast<c104SimPosItem^>(ScannedPoints[g])->X );
	 				         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 = ( safe_cast<c104SimPosItem^>(ScannedPoints[g])->Y );
							
															safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 = ( safe_cast<c104SimPosItem^>(ScannedPoints[g])->X + safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->cosX );
							        safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2 = ( safe_cast<c104SimPosItem^>(ScannedPoints[g])->Y + safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->sinY );

         				  safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 - safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2;
							        safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 - safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1;
               safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->c1 = (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2) -
        								                                               (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1);

		             if (	safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 > safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2 ){
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 - g_WindowTolerance; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 + g_WindowTolerance; 
 						        } else
							        {
							             safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1; 
							 		          safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX2; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1 - g_WindowTolerance; 
								            safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2 + g_WindowTolerance;
								       }// if else
               if (	safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 > safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2 ){
									           safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 - g_WindowTolerance; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 + g_WindowTolerance; 
								       } else
								       {
									           safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY2; 
																				safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1 - g_WindowTolerance; 
											         safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2 + g_WindowTolerance; 
								       }// if else

			        }// for (int i=0;i<=Convert::ToUInt32(paramNumberOfBeams-1)

											// pro vsechny paprsky vypocitej vzdalenost ke zdi 
											for (UInt32 i=0; i < Convert::ToUInt32(g_DmLSArray->Count); i++){ // for all beams

											   	Lsmin = Convert::ToDouble( LSTechInfo->LSRange );

															for (UInt32 j=0; j < Convert::ToUInt32(g_TemporaryMap->Count); j++){ // for all walls

											        //  vypocet ABDet
                   if ( 	( ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u1 ) +
             												  ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u2 ) ) == 0 ){
								        								ABDet = 0;
											        } else
											        {
																        ABDet = 1;
        											}// if
           
          									if ( ABDet != 0 ){

							               // do obecne rovnice paprsku dosadime parametricke rovnice steny a vypocteme parametr t
												          t = ( ( (-1) * safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->c1) - 
																            ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->Y1) -
																			         ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->X1) ) /
																			       ( ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->a1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u1 ) +
																			         ( safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->b1 * safe_cast<c100LineItem^>(g_TemporaryMap[j])->u2 ) );

                      // parametr t dosadime do parametricke rovnice steny a vypoceteme prusecik
															       xp = ( safe_cast<c100LineItem^>(g_TemporaryMap[j])->X1 + (safe_cast<c100LineItem^>(g_TemporaryMap[j])->u1 * t) );
															       yp = ( safe_cast<c100LineItem^>(g_TemporaryMap[j])->Y1 + (safe_cast<c100LineItem^>(g_TemporaryMap[j])->u2 * t) );
											
																						// test zda prusecik paprsku a steny lezi uvnitr usecky paprsku a steny zaroven +/- g_WindowTolerance
 														       if ( xp>=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx1) && 
																           xp<=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->Bx2) && 
																				       xp>=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wx1) && 
																				       xp<=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wx2) && 
																				       yp>=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By1) && 
																				       yp<=(safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->By2) && 
																				       yp>=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wy1) && 
																				       yp<=(safe_cast<c100LineItem^>(g_TemporaryMap[j])->Wy2) ){
																									                       
 											  				         Ls = Math::Sqrt( Math::Pow( (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mX1 - xp), 2) +
																					                       Math::Pow( (safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->mY1 - yp), 2) );

														          			if ( Ls < Lsmin ){
  	    	 										             Lsmin = Ls;
			    	 						            }// if ( Ls < Lsmin )

											           }//if ( xp>=Bx1 && xp<=Bx2 && xp>=Wx1 && xp<=Wx2 && yp>=By1 && yp<=By2 && yp>=Wy1 && yp<=Wy2 )

											       }// if ( ABDet != 0 )

           	  }// for (int j=0;j<=(h_LinesArray->Count-1);j++)
														
              safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->CalculatedLength = Lsmin;

          }// for (int i=0; i <= (coef2PIBeams-1); i++)

          // choose clasifying algorithm
										switch ( ComparingAlgorithm ){
		         	case 0: // argmin(Dm-Ds)
					        {
														scanLocalOptimum = +99999998;
										    for (Int32 i=0;i<Convert::ToInt32( ScanAngleNumber * 2 );i=i+StepDs){                         
												   
                  R1=0;
   															for (Int32 j=0;j<=Convert::ToInt32( g_Ds_NumberOfBeams-1 );j=j+StepDe){  

	   													     RI1 = (i+j);

																			   if ( g_RBeams[j] == true ){

                         if ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength != Convert::ToDouble( LSTechInfo->LSRange ) ) {         

      			   													   R1 = R1 + Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
				   																			                       safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );

																									}// if

																						}// if beams
									 							   
										   	    }// 	for (UInt32 j=0;j<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );j=j+1)   

													   		if ( R1 < scanLocalOptimum ){
                    
																       scanLocalOptimum = R1;
																				   scanLocalAngle = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->BeamAngle+(g_Ds_DetectionAngle/2); 

															   }// if

										    }// for (UInt32 i=0;i<=(coef2PIBeams-1);i=i+1)  

         					break;
					        }
				        case 1: // argmax(sum|0/1((Dm-Ds)<beta))
					        {
															scanLocalOptimum = 0;
										     for (Int32 i=0;i<Convert::ToInt32( ScanAngleNumber * 2 );i=i+StepDs){     
									 			   
                   R1=0;
														    	for (Int32 j=0;j<=Convert::ToInt32( g_Ds_NumberOfBeams-1 );j=j+StepDe){  

																			   if ( g_RBeams[j] == true ){

	   													        RI1 = (i+j);
                         if ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength != Convert::ToDouble( LSTechInfo->LSRange ) ) {         

																								     // way of EpsT evaluation for DSMAE2 only
																								     switch ( g_EpsTSel ){
												                   case 0: // Ds only EpsT from DETECTOR
																													   {
																														   R4 = Math::Abs( g_EpsTdummy * safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength ); 
																							          R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
																								                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
																														   break;
																													   }
												                   case 1: // Ds+de EpsT from DETECTOR
																													   {
											    								          R4 = Math::Abs( g_EpsTdummy * ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength + 
																								                                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength ) );
																							          R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
																								                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
																														   break;
																													   }
												                   case 2: // Ds only EpsT local
																													   {
																														   R4 = Math::Abs( g_EpsTdummy * safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength ); 
																							          R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
																								                         safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
																												 	   break;
																													   }
												                   case 3: // Ds+De only EpsT local
																													   {
											    								           R4 = Math::Abs( g_EpsTdummy * ( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength + 
																								                                          safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength ) );
																							           R5 = Math::Abs( safe_cast<c104LSBeamItem^>(g_DmLSArray[RI1])->CalculatedLength - 
 																							                          safe_cast<c104LSScan^>( g_DsLSArray[Item] )->LSItemPolar[j]->PolarLength );
	 																													   break;
																													   }
																												   default:
																													   {
                                 MessageBox::Show( this, "Unexpected Event. [EvaluatePopulation()].", "Suspicious behaviour...", MessageBoxButtons::OK );
																														   break;
																													   }
																								     }// switch

																			          if ( R5 <= R4  ) {
   																             R1 = R1 + 1;
																			          }

																									}// if 

																						}// if beams
                           
															   
											        }// for (UInt32 j=0;j<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );j=j+1){    

												    			if ( R1 >= scanLocalOptimum ){
                     
																      scanLocalOptimum = R1;
																				  scanLocalAngle = safe_cast<c104LSBeamItem^>(g_DmLSArray[i])->BeamAngle+(g_Ds_DetectionAngle/2); 
   
															    }// if

								    		 }// for (UInt32 i=0;i<=(coef2PIBeams-1);i=i+1)  

						         break;
					        }
				        default:
					        {
						         break;
					        }
			       }// switch

					     safe_cast<c104SimPosItem^>(ScannedPoints[g])->Evaluation = scanLocalOptimum;
 					    safe_cast<c104SimPosItem^>(ScannedPoints[g])->Angle = (scanLocalAngle); // * coefLS);

       }// for ALL POINTS


       // choose clasifying algorithm
							switch ( ComparingAlgorithm ){
		       case 0: // argmin(Dm-Ds)
					     {
    				 		// najdi bod s nejmensim ohodnocenim 
			      		R1 = safe_cast<c104SimPosItem^>(ScannedPoints[0])->Evaluation;
				       for ( UInt32 i=0;i<Convert::ToUInt32(ScannedPoints->Count);i=i+1){

  						       if ( R1 >= safe_cast<c104SimPosItem^>(ScannedPoints[i])->Evaluation ){

    		  										R1 = safe_cast<c104SimPosItem^>(ScannedPoints[i])->Evaluation;
				      								PosX = safe_cast<c104SimPosItem^>(ScannedPoints[i])->X;
						      						PosY = safe_cast<c104SimPosItem^>(ScannedPoints[i])->Y;
																	 BestAngle = safe_cast<c104SimPosItem^>(ScannedPoints[i])->Angle;

    								  	}// if 
    
				    	  }// for
							    LocalOptimum = R1;
											break;
										}
									case 1: // Dm-Ds<beta
										{

			      		R1 = safe_cast<c104SimPosItem^>(ScannedPoints[0])->Evaluation;
				       for ( UInt32 i=0;i<Convert::ToUInt32(ScannedPoints->Count);i=i+1){

  						       if ( R1 <= safe_cast<c104SimPosItem^>(ScannedPoints[i])->Evaluation ){

    		  										R1 = safe_cast<c104SimPosItem^>(ScannedPoints[i])->Evaluation;
				      								PosX = safe_cast<c104SimPosItem^>(ScannedPoints[i])->X;
						      						PosY = safe_cast<c104SimPosItem^>(ScannedPoints[i])->Y;
																	 BestAngle = safe_cast<c104SimPosItem^>(ScannedPoints[i])->Angle;

    								  	}// if 
    
				    	  }// for
							    LocalOptimum = R1;
										 break;
										}
									default:
										{
											break;
										}
							}// switch


    			gs_RPose.posX = PosX;
			    gs_RPose.posY = PosY;
			    gs_RPose.Angle_RAD = BestAngle;


									if ( gs_RPose.Angle_RAD > doublePI ){
										  while ( gs_RPose.Angle_RAD > doublePI ){
													     gs_RPose.Angle_RAD = gs_RPose.Angle_RAD - doublePI; 
										  }// while 
									}// if 
									if ( gs_RPose.Angle_RAD < (0) ){
										  while ( gs_RPose.Angle_RAD < (0) ){
													     gs_RPose.Angle_RAD = gs_RPose.Angle_RAD + doublePI; 
												}// while 
									}// if 


     		    if ( g_DebugMode == true ){
							       Application::DoEvents(); 
							    }// if 

   for ( UInt32 i=0;i<Convert::ToUInt32(ScannedPoints->Count);i=i+1 ){
			    delete( safe_cast<c104SimPosItem^>( ScannedPoints[i] ) );
			}//	for ( UInt32 i=0;i<Convert::ToUInt32(ScannedPoints->Count);i=i+1 )
			ScannedPoints->Clear();
   delete( ScannedPoints );

   delete( LSTechInfo );

		 for each(c104LSBeamItem^ i in g_DmLSArray ){
   			 delete( safe_cast<c104LSBeamItem^>(i) );
			}// for
			g_DmLSArray->Clear();

									


   WriteMessageToRichTextBox( g_ActualLSScan, "D1 | Scanner,BF", gs_RPose.posX, gs_RPose.posY, gs_RPose.Angle_RAD, g_EpsTdummy, ComparingAlgorithm, LocalOptimum );
			g_ContinualOptimum = LocalOptimum;


									RI1 = 0;
									for ( Int32 i=0;i<g_RBeams->Length;i++){
										   if ( g_RBeams[i] == true ){
														  RI1 = RI1 + 1;
													}// if 
									}// for

									this->label85->Text = "Optimum: " + Convert::ToString( Math::Round(LocalOptimum,2) ) + " beam[ "+Convert::ToString(RI1) + " ]";
			      this->label85->Refresh(); 


			return 0;

}// private: System::Byte A_02_01( Int32 Item )

private: System::Byte A_02_02( Int32 Item ){
// SCANNER DE DS/MAE-1,2

 const double doublePI = Math::PI * 2;

 double R1 = 0;
	double R2 = 0;
 double R3 = 0;
	double R4 = 0;
	double R5 = 0;
	double R6 = 0;
 double R7 = 0;
	double R8 = 0;

	Byte RB1 = 0;
	Byte RB2 = 0;

	Boolean DebugMode = false;

 String^ lineItem_1 = "";
 String^ lineItem_2 = "";

	Int32 RI1=0;
	Int32 RI2=0;
	Int32 RI3=0;
	Int32 RI4=0;

	Int32 EminX=0;
	Int32 EminY=0;
	Int32 EmaxX=0;
	Int32 EmaxY=0;

	UInt32 TerminationRule_MaxGeneration = 0;
	double TerminationRule_ExpectedFitness = 0;

 double coefLS = 0;
	UInt32 coef2PIBeams = 0;
	UInt32	coefDmCount = 0;

 double coefX=0;
 double coefY=0;

	double Optimum = 0;

	double posX = 0;
	double posY = 0;
	double Angle_RAD = 0;

 String^ line = "";

	Boolean TerminationRule = false;

	Random^ random = nullptr;

//************************************************


	      this->label86->Text = "Algorithm: SCANNER - DS/MAE+EA";
							this->label86->Refresh(); 

	      // Way of EpsT evaluation
       if ( this->radioButton4->Checked == true ){
  								g_EpsTdummy = Convert::ToDouble( this->maskedTextBox8->Text );  
										g_EpsTSel = 2; // Ds only
							} else if ( this->radioButton5->Checked == true ){
								  g_EpsTdummy = Convert::ToDouble( this->maskedTextBox8->Text );  
          g_EpsTSel = 3; // De+Ds
							} else
							{
								  g_EpsT = Convert::ToDouble( this->maskedTextBox8->Text );  
          g_EpsTSel = 3; // De+Ds
							}// if else

							TerminationRule_MaxGeneration = Convert::ToUInt32( this->numericUpDown23->Value ); // max gen.
							TerminationRule_ExpectedFitness = Convert::ToDouble( this->numericUpDown22->Value );  // fitness limit

							// type DE algoritmu
	      g_GA_SelectedAlgorithm = (1); //this->comboBox7->SelectedIndex)+1;
							// zpusov vytvoreni prvni generace
							g_WayOfCreation = Convert::ToInt32( this->comboBox6->SelectedIndex );

	      // set correct Fitness according to the type of searching algorithm
       switch ( this->comboBox8->SelectedIndex ){
									case 2: // DSMAE 1 EA
										{
											g_SearchingAlgorithm = 0; // seeking for MIN
	 									g_paramFitnessLimit = double::MaxValue;
		 								break;
			  					}
									case 3: // DSMAE 2 EA
										{
											g_SearchingAlgorithm = 1; // seeking for MAX
	 									g_paramFitnessLimit = double::MinValue;
		 								break;
			  					}
					 			default:
						 			{
							 			break;
								 	}
							 }// switch

							 g_ScanAngleNumber = Convert::ToInt32( this->numericUpDown19->Value );  

							 g_paramF = Convert::ToDouble( this->maskedTextBox10->Text );  
        g_paramCrossProbability = Convert::ToDouble( this->maskedTextBox9->Text );  

        g_GA_NumberOfIndividuals = Convert::ToUInt32( this->numericUpDown28->Value ); 

								g_GA_minX = Convert::ToDouble( this->numericUpDown24->Value );  
							 g_GA_minY = Convert::ToDouble( this->numericUpDown25->Value );  
							 g_GA_maxX = Convert::ToDouble( this->numericUpDown27->Value );  
							 g_GA_maxY = Convert::ToDouble( this->numericUpDown26->Value );  

								g_GA_AreaWidth  = Math::Abs( g_GA_minX ) + Math::Abs( g_GA_maxX );
								g_GA_AreaHeight = Math::Abs( g_GA_minY ) + Math::Abs( g_GA_maxY );

								g_paramStepDs = Convert::ToInt32( this->numericUpDown21->Value );
								g_paramStepDe = Convert::ToInt32( this->numericUpDown20->Value );


								//***************** START COMPUTING *******************

								   g_Generation = 0;

					      this->label87->Text = "Generation: "+Convert::ToString(g_Generation)+"  [ "+Convert::ToString(TerminationRule_MaxGeneration)+" ]  ";
							    this->label87->Refresh(); 

           GA_1stCreatePopulation();

           EvaluatePopulation( Item );

											// draw every generation
											if ( this->checkBox35->Checked == true ){
											   DrawPopulation();
											}// if 

           //**********************************************************
											//************************ DE CYCLE ************************
						    	do 
							     {

														if ( g_DebugMode == true){
													    Application::DoEvents();
										    }// if
						       
											   //Console::WriteLine("jdu na Cross");
              GA_1stCrossoverAndMutation();

											   //Console::WriteLine("jdu na 1 postprc");
         		   GA_1stPostprocessing();
  
														// Find BEST IND and FIT due tue Searching Alg.
									     if ( g_SearchingAlgorithm == 0){ // SMALLEST DSMAE 

   						 		     Optimum = safe_cast<c104PopItem^>(g_Population[0])->Fitness;
                 for ( Int32 i=0;i<Convert::ToInt32(g_Population->Count);i++){
                     if ( safe_cast<c104PopItem^>(g_Population[i])->Fitness <= Optimum ){ 
			                     Optimum = safe_cast<c104PopItem^>(g_Population[i])->Fitness;
		                   }// if 
                 }// for

									     } else
									     {
   						 		     Optimum = safe_cast<c104PopItem^>(g_Population[0])->Fitness;
                 for ( Int32 i=0;i<Convert::ToInt32(g_Population->Count);i++){
                     if ( safe_cast<c104PopItem^>(g_Population[i])->Fitness >= Optimum ){ 
			                     Optimum = safe_cast<c104PopItem^>(g_Population[i])->Fitness;
		                   }// if 
                 }// for

									     }// if else

														if ( g_DebugMode == true){
													    Application::DoEvents();
										    }// if

												

					         this->label87->Text = "Generation: "+Convert::ToString(g_Generation)+"  [ "+Convert::ToString(TerminationRule_MaxGeneration)+" ]  ";
							       this->label87->Refresh(); 

							       // termination rule SCANNER
							       switch (this->comboBox5->SelectedIndex){
															 case 0: // [1] Maximum number of generations
																	{
																		if (g_Generation >= TerminationRule_MaxGeneration ){ // this->numericUpDown7->Value
																			  TerminationRule = true;
																		}// if 
																		break;
																	}
																case 1: // [2] If best individuum has fitness less then (X) -> STOP
																	{
 																	if ( Optimum <= TerminationRule_ExpectedFitness ){ // this->numericUpDown7->Value
																			  TerminationRule = true;
																		}// if 
																		break;
																	}
																case 2: // [3] If best individuum has fitness greater then (X) -> STOP
																	{
 																	if ( Optimum >= TerminationRule_ExpectedFitness ){ // this->numericUpDown7->Value
																			  TerminationRule = true;
																		}// if 
																		break;
																	}
																case 3: // [[4] Stop if Fit(BestInd) <= Limit OR Generation >= MaxGeneration
																	{
 																	if ( ( Optimum <= TerminationRule_ExpectedFitness ) ||
																		     ( g_Generation >= TerminationRule_MaxGeneration ) ){
																			  TerminationRule = true;
																		}// if 
																		break;
																	}
																case 4: // [5] Stop if Fit(BestInd) >= Limit OR Generation >= MaxGeneration
																	{
 																	if ( ( Optimum >= TerminationRule_ExpectedFitness ) ||
																		     ( g_Generation >= TerminationRule_MaxGeneration ) ){
																			  TerminationRule = true;
																		}// if 
																		break;
																	}
																default:
																	{
																		break;
																	}
							       }// switch 

														// draw every generation
											   if ( this->checkBox35->Checked == true ){
											      DrawPopulation();
											   }// if 

														if ( g_DebugMode == true){
													    Application::DoEvents();
										    }// if

														// STOP was 
														if ( g_TerminateThread == true ){
                 TerminationRule = true;
														}//
              
														g_Generation = g_Generation + 1;

							    } while ( TerminationRule == false); 
											//**************************** WHILE **************************** 
											//**************************** WHILE **************************** 
  							  g_Generation = g_Generation - 1 ;


           // Find BEST IND and FIT due tue Searching Alg.
									  if ( g_SearchingAlgorithm == 0){ // SMALLEST DSMAE 

   						 	   Optimum = safe_cast<c104PopItem^>(g_Population[0])->Fitness;
              for ( Int32 i=0;i<Convert::ToInt32(g_Population->Count);i++){

                  if ( safe_cast<c104PopItem^>(g_Population[i])->Fitness <= Optimum ){ 

																			  posX = safe_cast<c104PopItem^>(g_Population[i])->Xdec; 
																			  posY = safe_cast<c104PopItem^>(g_Population[i])->Ydec; 
																					Angle_RAD = safe_cast<c104PopItem^>(g_Population[i])->Angle; 
																					Optimum = safe_cast<c104PopItem^>(g_Population[i])->Fitness;

		                }// if 

              }// for

									  } else
									  {
   						 	   Optimum = safe_cast<c104PopItem^>(g_Population[0])->Fitness;
              for ( Int32 i=0;i<Convert::ToInt32(g_Population->Count);i++){

                  if ( safe_cast<c104PopItem^>(g_Population[i])->Fitness >= Optimum ){ 

																			  posX = safe_cast<c104PopItem^>(g_Population[i])->Xdec; 
																			  posY = safe_cast<c104PopItem^>(g_Population[i])->Ydec; 
																					Angle_RAD = safe_cast<c104PopItem^>(g_Population[i])->Angle; 
																					Optimum = safe_cast<c104PopItem^>(g_Population[i])->Fitness;

		                }// if 

              }// for

									  }// if else

							    GA_1stDeletePopulation(); 

 								  gs_RPose.posX = posX - (0.5*g_GA_AreaWidth)  + gs_RPose.posX;
									  gs_RPose.posY = posY - (0.5*g_GA_AreaHeight) + gs_RPose.posY;
	 									gs_RPose.Angle_RAD = Angle_RAD; 


						
									if ( gs_RPose.Angle_RAD > doublePI ){
										  while ( gs_RPose.Angle_RAD > doublePI ){
													     gs_RPose.Angle_RAD = gs_RPose.Angle_RAD - doublePI; 
										  }// while 
									}// if 
									if ( gs_RPose.Angle_RAD < (0) ){
										  while ( gs_RPose.Angle_RAD < (0) ){
													     gs_RPose.Angle_RAD = gs_RPose.Angle_RAD + doublePI; 
												}// while 
									}// if 


				

   WriteMessageToRichTextBox( g_ActualLSScan, "D1 | Scanner,DE", gs_RPose.posX, gs_RPose.posY, gs_RPose.Angle_RAD, g_EpsTdummy, g_SearchingAlgorithm, Optimum );
			g_ContinualOptimum = Optimum;

									RI1 = 0;
									for ( Int32 i=0;i<g_RBeams->Length;i++){
										   if ( g_RBeams[i] == true ){
														  RI1 = RI1 + 1;
													}// if 
									}// for

									this->label85->Text = "Optimum: " + Convert::ToString( Math::Round(Optimum,2) ) + "  beam[ "+Convert::ToString(RI1) + " ]";
			      this->label85->Refresh(); 


											return 0;

}// private: System::Byte A_02_02( Int32 Item ){


private: System::Int32 WriteMessageToRichTextBox( Int32 scan, String^ text, double X, double Y, double angle, double epsT, Int32 sa, double optimum ){

String^ line_0 = "";
String^ line_1 = "";
String^ line_2 = "";
String^ line_3 = "";
String^ line_4 = "";
String^ line_5 = "";
String^ line_6 = "";
String^ line_7 = "";
String^ line_8 = "";
String^ line_9 = "";

Int32 el = 0;

Int32 RI1 = 0;

//******************************

   //
   if ( Convert::ToString( scan )->Length <= 6 ){
				  el = 6;
			} else
			{
				  el = Convert::ToString( scan )->Length + 1;
			}// if else
			line_1 = gcnew String( Convert::ToChar(32), el-Convert::ToString( scan )->Length ) + Convert::ToString( scan );

   // 
   if ( Convert::ToString( text )->Length <= 20 ){
				  el = 20;
			} else
			{
				  el = Convert::ToString( text )->Length + 1;
			}// if else
   line_2 = gcnew String( Convert::ToChar(32), el-Convert::ToString( text )->Length ) + Convert::ToString( text );

   //
   if ( Convert::ToString( Math::Round(X,2) )->Length <= 8 ){
				  el = 8;
			} else
			{
				  el = Convert::ToString( Math::Round(X,2) )->Length + 1;
			}// if else
   line_3 = gcnew String( Convert::ToChar(32), el-Convert::ToString( Math::Round(X,2) )->Length ) + Convert::ToString( Math::Round(X,2) );

   //
   if ( Convert::ToString( Math::Round(Y,2) )->Length <= 8 ){
				  el = 8;
			} else
			{
				  el = Convert::ToString( Math::Round(Y,2) )->Length + 1;
			}// if else
   line_4 = gcnew String( Convert::ToChar(32), el-Convert::ToString( Math::Round(Y,2) )->Length ) + Convert::ToString( Math::Round(Y,2) );

   //
   if ( Convert::ToString( Math::Round(rad2deg(angle),2) )->Length <= 6 ){
				  el = 6;
			} else
			{
				  el = Convert::ToString( Math::Round(rad2deg(angle),2) )->Length + 1;
			}// if else
   line_5 = gcnew String( Convert::ToChar(32), el-Convert::ToString( Math::Round(rad2deg(angle),2) )->Length ) + Convert::ToString( Math::Round(rad2deg(angle),2) );

   //
   if ( Convert::ToString( Math::Round( epsT,8 ) )->Length <= 18 ){
				  el = 18;
			} else
			{
				  el = Convert::ToString( Math::Round( epsT,8 ) )->Length + 1;
			}// if else
   line_6 = gcnew String( Convert::ToChar(32), el-Convert::ToString( Math::Round( epsT,8) )->Length ) + Convert::ToString( Math::Round( epsT,8 ) );  

   //
   if ( Convert::ToString( sa )->Length <= 3 ){
				  el = 3;
			} else
			{
				  el = Convert::ToString( sa )->Length + 1;
			}// if else
   line_7 = gcnew String( Convert::ToChar(32), el-Convert::ToString( sa )->Length ) + Convert::ToString( sa );

   //
   if ( Convert::ToString( Math::Round(optimum,2) )->Length <= 20 ){
				  el = 20;
			} else
			{
				  el = Convert::ToString( Math::Round(optimum,2) )->Length + 1;
			}// if else
   line_8 = gcnew String( Convert::ToChar(32), el-Convert::ToString( Math::Round(optimum,2) )->Length ) + Convert::ToString( Math::Round(optimum,2) );

   //
			RI1 = 0;
 		for ( Int32 i=0;i<g_RBeams->Length;i++){
						   if ( g_RBeams[i] == true ){
											 RI1 = RI1 + 1;
									}// if 
			}// for
   if ( Convert::ToString( RI1 )->Length <= 8 ){
				  el = 8;
			} else
			{
				  el = Convert::ToString( RI1 )->Length + 1;
			}// if else
   line_9 = gcnew String( Convert::ToChar(32), el-Convert::ToString( RI1 )->Length ) + Convert::ToString( RI1 );

   
			line_0 = line_1+": "+line_2+" | "+line_3+" | "+line_4+" | "+line_5+" | "+line_6+" | "+line_7+" | "+line_8+" | "+line_9+Environment::NewLine; 

			if ( this->richTextBox1->TextLength + line_0->Length < this->richTextBox1->MaxLength ){
				  this->richTextBox1->AppendText( line_0 );
			} else
			{
				  this->richTextBox1->Text = "";
				  this->richTextBox1->AppendText( line_0 );
			}// if 

			this->richTextBox1->Select(this->richTextBox1->Text->Length,0);
			this->richTextBox1->ScrollToCaret(); 

			line_0 = "";
			line_1 = "";
			line_2 = "";
 		for ( Int32 i=0;i<g_RBeams->Length;i++){
						   if ( g_RBeams[i] == true ){
											 line_1 = line_1 + "*";
									} else
									{
	           line_1 = line_1 + ".";
									}// if 
			}// for

   //
   if ( Convert::ToString( g_ActualLSScan )->Length <= 6 ){
				  el = 6;
			} else
			{
				  el = Convert::ToString( g_ActualLSScan )->Length + 1;
			}// if else
			line_2 = gcnew String( Convert::ToChar(32), el-Convert::ToString( g_ActualLSScan )->Length ) + Convert::ToString( g_ActualLSScan );

			line_0 = line_2 + ": " + line_1 + Environment::NewLine; 

			if ( this->richTextBox2->TextLength + line_0->Length < this->richTextBox2->MaxLength ){
				  this->richTextBox2->AppendText( line_0 );
			}// if 

			this->richTextBox2->Select(this->richTextBox2->Text->Length,0);
			this->richTextBox2->ScrollToCaret(); 

			return 0;

}// private: System::In32 WriteMessageToRichTextBox( Int32 scan, double X, double Y, double angle, double epsT, Int32 sa, double optimum, String^ bs ){

private: System::Void SaveMSGFile(System::Object^  sender, System::EventArgs^  e) {
// Svae Messages

const double doublePI = Math::PI * 2;

double R1 = 0;

String^ line = "";
String^ sep = "";
Boolean ErrStatus = false;
StreamWriter^ sw; 

double coefLS = 0;
UInt32 coef2PIBeams = 0;
UInt32	coefDmCount = 0;

//****************************************************


 					if ( gs_AutoSave.Opened == false ){
 							 MessageBox::Show( this, "Output TXT file name is not defined.", "TXT file saving.", MessageBoxButtons::OK ); 
									return;
						}// if 

						if ( this->richTextBox1->TextLength == 0 ){
 							 MessageBox::Show( this, "Number of found messages is equal to zero.", "MSG/TXT file saving.", MessageBoxButtons::OK ); 
									return;
						}// if 



 	    try
      {

        array<String^>^ tempArray = gcnew array<String^>( this->richTextBox1->Lines->Length );
        tempArray = this->richTextBox1->Lines;

							 line = Path::GetDirectoryName( gs_AutoSave.DirectoryOrFileName ) + "\\" + "msg.txt";

  						File::Delete( line ); 
 	  			 sw = gcnew StreamWriter( line );

								for ( Int32 i=0;i<Convert::ToInt32(tempArray->Length);i++){

												sw->WriteLine( tempArray[i] );

								}// for 

								delete( tempArray );
						}
 					catch( Exception^ e )
						{
						  ErrStatus = true;
								MessageBox::Show( "Error at writing TXT/MSG file: "+e->Message,"TXT/MSG file saving.", MessageBoxButtons::OK );
						}
      finally
      {
        if ( sw )
           delete (IDisposable^)sw;

								//if ( ErrStatus == false && this->checkBox41->Checked == false ){
									  //MessageBox::Show( "TXT/MSG data file saved OK.","TXT/MSG file saving.", MessageBoxButtons::OK );
								//}// if
								
      }// try catch finally

}// private: System::Void SaveMSGFile(System::Object^  sender, System::EventArgs^  e) {


private: System::Void SaveInfoFile(System::Object^  sender, System::EventArgs^  e) {
// AUTO PROPERTIES SAVE

String^ line = "";
Boolean ErrStatus = false;

StreamWriter^ sw = nullptr;

//***************************************

 					if ( gs_AutoSave.Opened == false ){
 							 MessageBox::Show( this, "Output TXT file name is not defined.", "TXT file saving.", MessageBoxButtons::OK ); 
									return;
						}// if 

		
   try
   {

						 line = Path::GetDirectoryName( gs_AutoSave.DirectoryOrFileName ) + "\\" + "info.txt";

  					File::Delete( line ); 

 	  		 sw = gcnew StreamWriter( line );

							line = "DS/MAE-3 + EA algorithm. Info file.";
       sw->WriteLine( line );
							line = "***********************************";
       sw->WriteLine( line );

							line = "TimeOfCreating: " + DateTime::Now.ToString();
       sw->WriteLine( line );

							line = "Algorithm Start/Stop time: " + g_StartStopTime;
       sw->WriteLine( line );

							line = "      ";
       sw->WriteLine( line );

							// RUN
							line = "Start pose: " + Convert::ToString( this->comboBox13->SelectedIndex ); 
       sw->WriteLine( line );
							if ( this->comboBox13->SelectedIndex == -1 ){
									 line = "Start pose description: User defined";
							} else
							{
							   line = "Start pose description: " + Convert::ToString( this->comboBox13->Items[ this->comboBox13->SelectedIndex ] ); 
							}// if else
       sw->WriteLine( line );
							line = "StartPose X: " + Convert::ToString( this->numericUpDown1->Value ); 
       sw->WriteLine( line );
							line = "StartPose Y: " + Convert::ToString( this->numericUpDown2->Value ); 
       sw->WriteLine( line );
							line = "StartPose Angle DEG: " + Convert::ToString( this->numericUpDown69->Value ); 
       sw->WriteLine( line );
							line = "Step Scan: " + Convert::ToString( this->numericUpDown35->Value ); 
       sw->WriteLine( line );

							// draw
							line = "Draw static objects: " + Convert::ToString( this->checkBox30->Checked ); 
       sw->WriteLine( line );
							line = "Show robot's pose and heading: " + Convert::ToString( this->checkBox31->Checked ); 
       sw->WriteLine( line );
							line = "Obelize robot's pose: " + Convert::ToString( this->checkBox32->Checked ); 
       sw->WriteLine( line );
							line = "Draw moving objects: " + Convert::ToString( this->checkBox34->Checked ); 
       sw->WriteLine( line );
							line = "Show every population: " + Convert::ToString( this->checkBox35->Checked ); 
       sw->WriteLine( line );
							line = "Write PTH file: " + Convert::ToString( this->checkBox36->Checked ); 
       sw->WriteLine( line );
							line = "Robot view magnifier: " + Convert::ToString( this->numericUpDown59->Value ); 
       sw->WriteLine( line );
							line = "Debufg mode: " + Convert::ToString( this->checkBox29->Checked ); 
       sw->WriteLine( line );

							line = "Auto application exit: " + Convert::ToString( this->checkBox48->Checked ); 
       sw->WriteLine( line );

							line = "Master priority: " + Convert::ToString( this->trackBar5->Value ); 
       sw->WriteLine( line );

							line = "Play signal at the end: " + Convert::ToString( this->checkBox40->Checked ); 
       sw->WriteLine( line );
							line = "Write INFO file: " + Convert::ToString( this->checkBox52->Checked ); 
       sw->WriteLine( line );

							line = "      ";
       sw->WriteLine( line );

    

							// Scanner
						 line = "Use dynamic computing Ds: " + Convert::ToString( this->radioButton4->Checked ); 
       sw->WriteLine( line );
						 line = "Use dynamic computing Ds+De: " + Convert::ToString( this->radioButton5->Checked ); 
       sw->WriteLine( line );
							line = "Fix EpsT value: " + Convert::ToString( this->maskedTextBox8->Text ); 
       sw->WriteLine( line );
							line = "StepDs : " + Convert::ToString( this->numericUpDown21->Value ); 
       sw->WriteLine( line );
							line = "StepDe : " + Convert::ToString( this->numericUpDown20->Value ); 
       sw->WriteLine( line );
							line = "Detection angle: " + Convert::ToString( this->numericUpDown19->Value ); 
       sw->WriteLine( line );
							line = "Searching algorithm: " + Convert::ToString( this->comboBox8->SelectedIndex ); 
       sw->WriteLine( line );
							line = "Searching area minX: " + Convert::ToString( this->numericUpDown29->Value ); 
       sw->WriteLine( line );
						 line = "Searching area minY: " + Convert::ToString( this->numericUpDown31->Value ); 
       sw->WriteLine( line );
						 line = "Searching area maxX: " + Convert::ToString( this->numericUpDown33->Value ); 
       sw->WriteLine( line );
						 line = "Searching area maxY: " + Convert::ToString( this->numericUpDown34->Value ); 
       sw->WriteLine( line );
						 line = "Searching area stepX: " + Convert::ToString( this->numericUpDown30->Value ); 
       sw->WriteLine( line );
							line = "Searching area stepY: " + Convert::ToString( this->numericUpDown32->Value ); 
       sw->WriteLine( line );
							line = "Type of DE method: rand/1/exp";
       sw->WriteLine( line );
							line = "Number of INDs: " + Convert::ToString( this->numericUpDown28->Value ); 
       sw->WriteLine( line );
						 line = "Way of POP creation: " + Convert::ToString( this->comboBox6->SelectedIndex ); 
       sw->WriteLine( line );
							line = "DE searching area minX: " + Convert::ToString( this->numericUpDown24->Value ); 
       sw->WriteLine( line );
						 line = "DE searching area minY: " + Convert::ToString( this->numericUpDown25->Value ); 
       sw->WriteLine( line );
						 line = "DE searching area maxX: " + Convert::ToString( this->numericUpDown26->Value ); 
       sw->WriteLine( line );
						 line = "DE searching area maxY: " + Convert::ToString( this->numericUpDown27->Value ); 
       sw->WriteLine( line );
							line = "F value: " + Convert::ToString( this->maskedTextBox10->Text ); 
       sw->WriteLine( line );
							line = "Pcrx value: " + Convert::ToString( this->maskedTextBox9->Text ); 
       sw->WriteLine( line );
							line = "Number of generations: " + Convert::ToString( this->numericUpDown23->Value ); 
       sw->WriteLine( line );
							line = "F(x) value: " + Convert::ToString( this->numericUpDown22->Value ); 
       sw->WriteLine( line );

							line = "      ";
       sw->WriteLine( line );


   }
  	catch( Exception^ err )
			{
		   ErrStatus = true;
					MessageBox::Show( "Error at writing INFO file: "+err->Message,"INFO file saving.", MessageBoxButtons::OK );
			}
   finally
   {
     if ( sw )
        delete (IDisposable^)sw;
								
   }// try catch finally

}// private: System::Void SaveInfoFile(System::Object^  sender, System::EventArgs^  e) {


private: System::Void SavePTHFile(System::Object^  sender, System::EventArgs^  e) {
// Save PTH File 

BinaryWriter^ binWriter;

//*************************************************


       if ( g_FoundedPositions->Count == 0 ){ 
								  return;
							}// if 

       try
							{

			        binWriter = gcnew BinaryWriter( File::Open( gs_PTHFile.FileName , FileMode::Append  ) );
        
								   binWriter->Write(	gs_PLBFile.FileName );

           binWriter->Write(	g_globalPLBMinX_XY );
	          binWriter->Write(	g_globalPLBMaxX_XY );
	          binWriter->Write(	g_globalPLBMinY_XY );
	          binWriter->Write(	g_globalPLBMaxY_XY );

							   	cLSTechInfo^ LSTechInfo = gcnew cLSTechInfo(); 
							   	binWriter->Write(	LSTechInfo->NumberOfBeams ); // UInt16
							   	binWriter->Write(	LSTechInfo->DetectionAngleDEG ); //double
							   	binWriter->Write(	LSTechInfo->DetectionAngleRAD );
							   	binWriter->Write(	LSTechInfo->LSRange );
							   	delete( LSTechInfo );

						   		binWriter->Write(	g_DsMinX_XY );
	          binWriter->Write(	g_DsMaxX_XY );
	          binWriter->Write(	g_DsMinY_XY );
	          binWriter->Write(	g_DsMaxY_XY );

		         binWriter->Write(	g_DsMinX_Polar );
	          binWriter->Write( g_DsMaxX_Polar );
	          binWriter->Write(	g_DsMinY_Polar );
	          binWriter->Write(	g_DsMaxY_Polar );

							   	binWriter->Write(	g_vRobotMagnifier );

 						   	binWriter->Write( Convert::ToDouble( this->numericUpDown33->Value ));
	          binWriter->Write( Convert::ToDouble( this->numericUpDown34->Value ) );
	          binWriter->Write( Convert::ToDouble( this->numericUpDown31->Value ));
	          binWriter->Write( Convert::ToDouble( this->numericUpDown29->Value ));
		         binWriter->Write( Convert::ToDouble( this->numericUpDown30->Value ) );
		         binWriter->Write( Convert::ToDouble( this->numericUpDown32->Value ) );

							   	binWriter->Write( g_Ds_NumberOfScans );
           binWriter->Write( g_Ds_NumberOfBeams );
		         binWriter->Write( g_Ds_DetectionAngle );

           binWriter->Write( g_PLBMagnifierX );
		         binWriter->Write( g_PLBMagnifierY );
		         binWriter->Write( g_PLBMagnifierZoom );

           binWriter->Write( g_DsMagnifier );

							   	binWriter->Write( Convert::ToUInt32( 1 ) ); // uint32
       	   binWriter->Write( Convert::ToUInt32( 1 ) ); // uint32

							    binWriter->Write( Convert::ToInt32( 23 ) ); 
           binWriter->Write( 0 ); //
											binWriter->Write( "Map Building - DS/MAE-3+Vector+EA+Submap" ); // ME

											for ( Int32 j=0;j<g_FoundedPositions->Count;j++){ 

						       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->PosX);
						       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->PosY );
						       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->Angle );
						       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->Optimum );
						       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->Sample );
						       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->NoiseLevel );
						       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->XYAttrib );

						       binWriter->Write(	safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->DsMinX_Polar );
	    	       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->DsMaxX_Polar );
             binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->DsMinY_Polar );
						       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->DsMaxY_Polar );

             binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->DsMinX_XY );
			   			    binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->DsMaxX_XY );
   						    binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->DsMinY_XY );
						       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->DsMaxY_XY );

						       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->DsRHeadX );
						       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->DsRHeadY );

	            for (UInt32 i=0;i<Convert::ToUInt32( g_Ds_NumberOfBeams );i=i+1){

							          binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->LSItemDsPolar[i]->PolarLength ); 
                 binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->LSItemDsXY[i]->X );
			   							    binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->LSItemDsXY[i]->Y );

     	 			   }// for 

					        for (UInt32 i=0;i<Convert::ToUInt32( g_Ds_NumberOfBeams );i++){

									        binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->LSItemDfXY[i]->X );
										       binWriter->Write( safe_cast<c104FoundPosition^>(g_FoundedPositions[j])->LSItemDfXY[i]->Y );

   						    }// for 

											}// for j

								}
								catch( Exception^ err )
								{
									  MessageBox::Show( "Error at writing PTH file: "+err->Message,"PTH file saving.", MessageBoxButtons::OK );
								}
								finally
								{

							   	binWriter->Close();
   				   	delete( binWriter ); 
								}

							
}// private: System::Void SavePTHFile(System::Object^  sender, System::EventArgs^  e) {

private: System::Void button24_Click(System::Object^  sender, System::EventArgs^  e) {
// SAVE found positions to TXT file

const double doublePI = Math::PI * 2;

double R1 = 0;

String^ line = "";
String^ sep = "";
Boolean ErrStatus = false;
StreamWriter^ sw; 

double coefLS = 0;
UInt32 coef2PIBeams = 0;
UInt32	coefDmCount = 0;

System::Globalization::CultureInfo^ culture;

//****************************************************


 					if ( gs_TXTFile.Opened == false ){
 							 MessageBox::Show( this, "Output TXT file name is not defined.", "TXT file saving.", MessageBoxButtons::OK ); 
									return;
						}// if 

						if ( g_FoundedPositions->Count == 0 ){
 							 MessageBox::Show( this, "Number of found positions is equal to zero.", "TXT file saving.", MessageBoxButtons::OK ); 
									return;
						}// if 

						if ( Math::Abs( g_Ds_DetectionAngle - doublePI ) < 0.00001 ){

    				 coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
       	 coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
	        coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081

						} else
						{
    				 coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
       	 coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
	        coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081
						}// if else

       // textovy separator
       if ( this->radioButton37->Checked == true ){ // ;
          sep = ";";
       } else if ( this->radioButton36->Checked == true ){ // TAB
          sep = Convert::ToString( Convert::ToChar(9) );
       } else if ( this->radioButton35->Checked == true ){ // ,
          sep = ",";
       } else if ( this->radioButton34->Checked == true ){ // libovolne
          sep = Convert::ToString( Convert::ToChar( this->numericUpDown72->Value ) );
       } else
       {
          sep = ";";
       }// if else 


						if ( this->checkBox45->Checked == false ){
							  culture = gcnew System::Globalization::CultureInfo("en-US"); // comma separator
						   culture->NumberFormat->NumberDecimalSeparator = ",";
						} else
						{
							  culture = gcnew System::Globalization::CultureInfo("en-US"); // dot separator
						   culture->NumberFormat->NumberDecimalSeparator = ".";
						}// if else


 	    try
      {

  						File::Delete( gs_TXTFile.FileName ); 
 	  			 sw = gcnew StreamWriter( gs_TXTFile.FileName );

        // No column header
        if ( this->checkBox46->Checked == false ){ 

           line = "Item"+sep+"Xpos"+sep+"Ypos"+sep+"AngleDEG"+sep+"Optimum"+sep+"NoiseLevel"+sep+"XYAttrib";

        }// if 

						  sw->WriteLine( line );

								for ( UInt32 i=0;i<Convert::ToUInt32(g_FoundedPositions->Count);i++){

												R1 = rad2deg( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->Angle );

						      line = "";
						      line = Convert::ToString( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->Sample, culture ) + sep +
										         Convert::ToString( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->PosX, culture ) + sep +
						             Convert::ToString( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->PosY, culture ) + sep +
																   Convert::ToString( R1, culture ) + sep +
                   Convert::ToString( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->Optimum, culture ) + sep +
                   Convert::ToString( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->NoiseLevel, culture ) + sep +
									          Convert::ToString( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->XYAttrib, culture );

												sw->WriteLine( line );

								}// for 
						}
 					catch( Exception^ e )
						{
						  ErrStatus = true;
								MessageBox::Show( "Error at writing TXT file: "+e->Message,"TXT file saving.", MessageBoxButtons::OK );
						}
      finally
      {
        if ( sw )
           delete (IDisposable^)sw;

								if ( ErrStatus == false ){
									  MessageBox::Show( "TXT data file saved OK.","TXT file saving.", MessageBoxButtons::OK );
								}// if
								
      }// try catch finally

   
}// private: System::Void button24_Click

private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
// CUT limit values from Laser - LSB file if bigger than limit 


double R1 = 0;
double R2 = 0;

Int32 RI1 = 0;

	double MinX_Polar = 0;
	double MaxX_Polar = 0;
	double MinY_Polar = 0;
	double MaxY_Polar = 0;

	double MinX_XY = 0;
	double MaxX_XY = 0;
	double MinY_XY = 0;
	double MaxY_XY = 0;

	double coefLS = 0;

//**************************

	        this->button11->Text = "Wait ... ";
									this->button11->Enabled = false;
									this->button11->BackColor = Color::Red; 
									this->button11->ForeColor = Color::Yellow; 
									this->button11->Refresh();
									Application::DoEvents(); 


						   for ( Int32 i=0; i < g_DsLSArray->Count; i++ ){

										   // compute average
										   R2 = 0;
										   for ( Int16 j=0; j < Convert::ToInt16( safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar->Length ); j++ ){

															  if ( safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]->PolarLength < Convert::ToDouble( this->numericUpDown88->Value ) ){

													       R1 = R1 + safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]->PolarLength;
																				R2 = R2 + 1;

																	}// if 

													}// for 
													R1 = R1 / R2;
 	               
	   									for ( Int16 j=0; j < Convert::ToInt16( safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar->Length ); j++ ){

				   										if ( safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]->PolarLength >= Convert::ToDouble( this->numericUpDown88->Value ) ){

                    safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]->PolarLength = R1;
                    safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]->Correct = false;

							   							}// if 

													}// for

									}// for 

		      	if ( g_Ds_DetectionAngle == (2*Math::PI) ){
   			      coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
      			} else
			      {
   			      coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
       		}// if else

									MinX_Polar = +9999999;
    	    MaxX_Polar = -9999999;
	        MinY_Polar = +9999999;
	        MaxY_Polar = -9999999;

    	    MinX_XY = +9999999;
	        MaxX_XY = -9999999;
	        MinY_XY = +9999999;
									MaxY_XY = -9999999;

									this->listBox1->Items->Clear(); 

						   for ( Int32 i=0; i < g_DsLSArray->Count; i++ ){


										   for ( Int16 j=0; j < Convert::ToInt16( safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar->Length ); j++ ){

												     if ( MinX_Polar >	j ){
				                MinX_Polar =	j;
					     	      }// if			
											      if ( MaxX_Polar <	j ){
				                MaxX_Polar =	j;
					     	      }// if	
    							      if ( MinY_Polar >	safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]->PolarLength ){
   				             MinY_Polar =	safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]->PolarLength;
			   		     	   }// if			
						   					   if ( MaxY_Polar <	safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]->PolarLength ){
				                MaxY_Polar =	safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]->PolarLength;
					     	      }// if	

											      safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemXY[j]->X = Math::Cos(coefLS*Convert::ToDouble(j)) * 
																		                                                          safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]->PolarLength;
											      safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemXY[j]->Y = Math::Sin(coefLS*Convert::ToDouble(j)) * 
																		                                                          safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar[j]->PolarLength;

		
										       if ( MinX_XY >	safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemXY[j]->X ){
   				             MinX_XY = safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemXY[j]->X;
			   		     	   }// if			 
						   					   if ( MaxX_XY <	safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemXY[j]->X ){
				                MaxX_XY = safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemXY[j]->X;
					     	      }// if		
											      if ( MinY_XY >	safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemXY[j]->Y ){
				                MinY_XY = safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemXY[j]->Y;
					     	      }// if			 
											      if ( MaxY_XY <	safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemXY[j]->Y ){
				                MaxY_XY = safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemXY[j]->Y;
					     	      }// if		
                     
													}// for ( Int16 j=0; j < Convert::ToInt16( safe_cast<c104LSScan^>( g_DsLSArray[i] )->LSItemPolar->Length ); j++ ){

  										 safe_cast<c104LSScan^>( g_DsLSArray[i] )->RHeadX = Math::Abs( MinX_XY );
             safe_cast<c104LSScan^>( g_DsLSArray[i] )->RHeadY = Math::Abs( MinY_XY );

             safe_cast<c104LSScan^>( g_DsLSArray[i] )->MinX_XY = MinX_XY;
							      safe_cast<c104LSScan^>( g_DsLSArray[i] )->MaxX_XY = MaxX_XY;
							      safe_cast<c104LSScan^>( g_DsLSArray[i] )->MinY_XY = MinY_XY;
							      safe_cast<c104LSScan^>( g_DsLSArray[i] )->MaxY_XY = MaxY_XY;
							
	            safe_cast<c104LSScan^>( g_DsLSArray[i] )->MinX_Polar = MinX_Polar;
	            safe_cast<c104LSScan^>( g_DsLSArray[i] )->MaxX_Polar = MaxX_Polar;
							      safe_cast<c104LSScan^>( g_DsLSArray[i] )->MinY_Polar = MinY_Polar;
	            safe_cast<c104LSScan^>( g_DsLSArray[i] )->MaxY_Polar = MaxY_Polar;

			       this->listBox1->SelectedIndexChanged -= gcnew System::EventHandler(this, &MapBuilding_LM104::listBox1_SelectedIndexChanged);

   							this->listBox1->Items->Add("LS: " + Convert::ToString(i)+
		    					                          "  C minXY[" + Convert::ToInt32(MinX_XY).ToString() + 
			 		  			                          "," + Convert::ToInt32(MinY_XY).ToString() +
				 			   																										"],maxXY[" + Convert::ToInt32(MaxX_XY).ToString() +
					 					   																							"," + Convert::ToInt32(MaxY_XY).ToString() + "] " +
						 							   																				"P minXY[" + Convert::ToInt32(MinX_Polar).ToString() +
							 									   																	"," + Convert::ToInt32(MinY_Polar).ToString() +
								 											   														"],maxXY[" + Convert::ToUInt32(MaxX_Polar).ToString() +
									 													   											"," + Convert::ToInt32(MaxY_Polar).ToString() + "] " );
	
			       this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MapBuilding_LM104::listBox1_SelectedIndexChanged);


									}// for 


				     this->label188->Text = "[ Number of samples: " + Convert::ToString(g_Ds_NumberOfScans) + " ] ";

			 		   this->textBox22->Text = Convert::ToString( Math::Round( g_DsMinX_Polar ));
						   this->textBox21->Text = Convert::ToString( Math::Round( g_DsMinY_Polar ));
						   this->textBox20->Text = Convert::ToString( Math::Round( g_DsMaxX_Polar ));
						   this->textBox19->Text = Convert::ToString( Math::Round( g_DsMaxY_Polar ));

     	   this->textBox16->Text = Convert::ToString( Math::Round( g_DsMinX_XY ));
						   this->textBox18->Text = Convert::ToString( Math::Round( g_DsMinY_XY ));
						   this->textBox17->Text = Convert::ToString( Math::Round( g_DsMaxX_XY ));
						   this->textBox15->Text = Convert::ToString( Math::Round( g_DsMaxY_XY ));

		    			this->listBox1->SelectedIndex = (0); 
  
					    this->label81->Text = "Start sample: 0";

    					DrawDsSample( this->listBox1->SelectedIndex );

									this->button11->Text = "Apply";
									this->button11->Enabled = true;
									this->button11->BackColor = Color::Transparent; 
									this->button11->ForeColor = Color::Black;
									this->button11->Refresh();
									Application::DoEvents();

}// private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e)  





private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
// ********************************************
//              START SEARCHING
// ********************************************

const double doublePI = Math::PI * 2;

double coefLS = 0;
UInt32 coef2PIBeams = 0;
UInt32	coefDmCount = 0;

double R1=0;
double R2=0;
double R3=0;
double R4=0;
double R5=0;
double R6=0;
double R7=0;
double R8=0;
double R9=0;
double R10=0;
double R11=0;
double R12=0;
double R13=0;

Int32 RI1 = 0;
Int32 RI2 = 0;
Int32 RI3 = 0;

Int32 StartItem = 0;

Boolean DebugMode = false;

String^ DummyStr = "";

 String^ lineItem_1="";
 String^ lineItem_2="";
	String^ line = "";


g_ScanAngleNumber = 60; //(doublePI/12);



 System::Drawing::Icon^ MasterIcon = nullptr;
 System::Drawing::Icon^ SlaveIcon = nullptr;
 System::Drawing::Icon^ RSIcon = nullptr; // old icon

	String^ StartStopTime = "";

 DialogResult result;

 Process^ currentProcess = Process::GetCurrentProcess();


	List<Object^>^ BeamArray; 
	List<Object^>^ ApproxLinesArray; 

//******************************************************************


	
	      if ( this->numericUpDown24->Value != this->numericUpDown27->Value ){
								  MessageBox::Show( this, "Scanner: min/max area of EA must be identical.","Parameters checker.", MessageBoxButtons::OK );
										return;
							}// if 
	      if ( this->numericUpDown25->Value != this->numericUpDown26->Value ){
								  MessageBox::Show( this, "Scanner:  min/max area of EA must be identical.","Parameters checker.", MessageBoxButtons::OK );
										return;
							}// if 


		     if ( this->checkBox36->Checked == true && gs_PTHFile.FileName == "" ){
           MessageBox::Show( this, "Robot path - PTH file name is not defined. I can not create PTH file.","Parameters checker.", MessageBoxButtons::OK );
											return;
			 				} else
								{
									if ( File::Exists( gs_PTHFile.FileName ) == true ){
										  result = MessageBox::Show( this, "Do you want to overwrite existing PTH file?","Searching process...", MessageBoxButtons::YesNo );
												if ( result == ::DialogResult::Yes ){
													  try
															{
									        File::Delete( gs_PTHFile.FileName ); 
															}
															catch(...)
															{
																 MessageBox::Show( this, "Error at deleting PTH file.","PTH file is not accessible.", MessageBoxButtons::OK );
															}
															finally
															{
															}
												} else
												{
													 return;
												}
									}// if 

								}// if else
	

							  g_RequestedProcessPriority = g_Process->PriorityClass;
							  if ( this->checkBox29->Checked == true ){
								    g_DebugMode = true;
										  SetPriority(ProcessPriorityClass::Normal);
							  } else
							  {
									   g_DebugMode = true;
										  SetPriority(g_RequestedProcessPriority);
							  }// if 


	
	    //set debug mode
	    if ( this->checkBox29->Checked == true ){
						  g_DebugMode = true;
	    }// if

						// list of found pos
      this->tabPage6->Enabled = false; 


						if ( Math::Round( g_Ds_DetectionAngle,5 ) == Math::Round( doublePI,5 ) ){

   			     coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams )  );
			        coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
			        coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081

			     } else
			     {
   			     coefLS = ( g_Ds_DetectionAngle / Convert::ToDouble( g_Ds_NumberOfBeams - 1 )  );
			        coef2PIBeams = Convert::ToUInt32( doublePI / coefLS );   //720                    // number of LS beams from angle 0 to angle ((2*PI)-coefLS)
			        coefDmCount = Convert::ToUInt32( coef2PIBeams + Convert::ToUInt32( g_Ds_NumberOfBeams ) ); //1081
			     }// if else

			 	this->richTextBox1->Text = "";
			 	this->richTextBox2->Text = "";

     Application::DoEvents(); 
     Application::DoEvents(); 

					this->button9->Text = "SEARCHING IN PROGRESS"; 
					this->button9->BackColor = Color::FromArgb(255,192,192); 
					this->button9->Enabled = false;

					this->button8->Enabled = false;   // reset OFF
					this->button7->Enabled = true;   //  pause ON

					this->button3->Enabled = false;  // RESET files off 

					StartStopTime = "Start / StopTime: "+DateTime::Now.ToString()+" / ";
					this->label88->Text = StartStopTime;

					gs_RPose.posX = Convert::ToDouble( this->numericUpDown1->Value );  
					gs_RPose.posY = Convert::ToDouble( this->numericUpDown2->Value );  
     gs_RPose.Angle_RAD = deg2rad_double( Convert::ToDouble( this->numericUpDown69->Value ) );  

					//Console::WriteLine("detA {0}",g_Ds_DetectionAngle );

     StartItem = Convert::ToInt32( this->listBox1->SelectedIndex );   // nastaveni hledaneho scanu v list boxu

	 	  BeamArray = gcnew List<Object^>;
		   ApproxLinesArray = gcnew List<Object^>(); 


 		 	for ( Int32 i=0;i<Convert::ToInt32( safe_cast<c104LSScan^>( g_DsLSArray[ StartItem ] )->LSItemXY->Length );i++){

		   		  ROBOMAP::c100LSRayBunchItem^ Beam = gcnew c100LSRayBunchItem();

				  			Beam->PolarLength = safe_cast<c104LSScan^>( g_DsLSArray[ StartItem ] )->LSItemPolar[i]->PolarLength ;
						  	Beam->X = safe_cast<c104LSScan^>( g_DsLSArray[ StartItem ] )->LSItemXY[i]->X;
							  Beam->Y = safe_cast<c104LSScan^>( g_DsLSArray[ StartItem ] )->LSItemXY[i]->Y;
 						  Beam->Status = 0; 
							  Beam->PosIndex = i; 

							  BeamArray->Add(Beam); 

			  }// for

     c100MultiLineApproximationA^ R = gcnew c100MultiLineApproximationA(BeamArray, ApproxLinesArray, nullptr ); // nullptr = use all 361 beams 
     R->g_distanceLimit_pointTopoint = Convert::ToDouble( this->numericUpDown77->Value ); 
     R->g_distanceLimit_pointToLine  = Convert::ToDouble( this->numericUpDown78->Value ); 
					R->Run();
			 	delete( R );

		   for ( Int32 i=0;i < Convert::ToInt32( BeamArray->Count );i++){
         delete( safe_cast<c100LSRayBunchItem^>(BeamArray[i]) );
			  }// for
			  BeamArray->Clear();


				 R7 = gs_RPose.Angle_RAD - (g_Ds_DetectionAngle/2);
		   for (Int32 i=0;i<Convert::ToInt32( ApproxLinesArray->Count );i++){

			      R1 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->X1; // 
		 			   R2 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->Y1;

							  R3 = ((R1 * Math::Cos( R7 )) - (R2 * Math::Sin( R7 ))) + gs_RPose.posX;
							  R4 = ((R1 * Math::Sin( R7 )) + (R2 * Math::Cos( R7 ))) + gs_RPose.posY;

						   R1 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->X2; //  
		 			   R2 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->Y2;

							  R5 = ((R1 * Math::Cos( R7 )) - (R2 * Math::Sin( R7 ))) + gs_RPose.posX;
						  	R6 = ((R1 * Math::Sin( R7 )) + (R2 * Math::Cos( R7 ))) + gs_RPose.posY;

				     ROBOMAP::c100LineItem^ LineItem = gcnew c100LineItem();

							  LineItem->X1 = R3;
							  LineItem->Y1 = R4;
							  LineItem->X2 = R5;
							  LineItem->Y2 = R6; 

							  LineItem->diffX  = ( LineItem->X2 - LineItem->X1 );
							  LineItem->diffY  = ( LineItem->Y1 - LineItem->Y2 );
							  LineItem->LengthSQR = Math::Pow( (LineItem->X2 - LineItem->X1),2 ) +  Math::Pow( (LineItem->Y2 - LineItem->Y1),2 );
							  LineItem->Length = Math::Sqrt( LineItem->LengthSQR ); 

							  LineItem->u1 = ( LineItem->X2 - LineItem->X1 );
							  LineItem->u2 = ( LineItem->Y2 - LineItem->Y1 );

         if (	LineItem->X1 > LineItem->X2 ){
								    LineItem->Wx1 = LineItem->X2; 
            LineItem->Wx2 = LineItem->X1; 
										  LineItem->Wx1 = LineItem->Wx1 - g_WindowTolerance; 
            LineItem->Wx2 = LineItem->Wx2 + g_WindowTolerance; 
							  } else
						   {
			 				    LineItem->Wx1 = LineItem->X1; 
            LineItem->Wx2 = LineItem->X2; 
  										LineItem->Wx1 = LineItem->Wx1 - g_WindowTolerance; 
            LineItem->Wx2 = LineItem->Wx2 + g_WindowTolerance; 
         }// if else
							  if (	LineItem->Y1 > LineItem->Y2 ){
										  LineItem->Wy1 = LineItem->Y2; 
            LineItem->Wy2 = LineItem->Y1;
										  LineItem->Wy1 = LineItem->Wy1 - g_WindowTolerance; 
            LineItem->Wy2 = LineItem->Wy2 + g_WindowTolerance;
					    } else
							  {
									  	LineItem->Wy1 = LineItem->Y1; 
            LineItem->Wy2 = LineItem->Y2;
 									  LineItem->Wy1 = LineItem->Wy1 - g_WindowTolerance; 
            LineItem->Wy2 = LineItem->Wy2 + g_WindowTolerance;
							  }// if else

							  LineItem->a2 = LineItem->Y1 - LineItem->Y2; 
							  LineItem->b2 = LineItem->X2 - LineItem->X1;
							  LineItem->c2 = (LineItem->X1*LineItem->Y2)-(LineItem->X2*LineItem->Y1); 

							  LineItem->a1 = LineItem->a2;  // dummy 3 lines
							  LineItem->b1 = LineItem->b2;  //
							  LineItem->c1 = LineItem->c2;  //

							  g_GlobalMap->Add( LineItem ); //

   		}// for

			  for (Int32 i=0;i<Convert::ToInt32( ApproxLinesArray->Count );i++){
				     delete( safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i]) );
			  }// for 
			  ApproxLinesArray->Clear();


												if ( this->checkBox23->Checked == true ){ 
												   DrawGlobalMap();
												}// if 

										  // create TemporaryMap directly
							  			switch( this->comboBox23->SelectedIndex ){
									  		case 0:
											  	{
               createTemporaryMap_fromGlobalMap( StartItem );
													  break;
												  }
										   case 1:
											   {
										     createTemporaryMap_fromLastScan( StartItem );
												   break;
											   }
										  }// switch


			  for ( Int32 i=0;i<g_RBeams->Length;i++){
								   g_RBeams[i] = true; 
     }// for i 


     // FOR ALL LS SCANS 
					for ( Int32 f = Convert::ToInt32(StartItem);f<Convert::ToInt32(g_DsLSArray->Count);f = f + Convert::ToInt32( this->numericUpDown35->Value ) ){

						   g_ActualLSScan = f;

									this->label83->Text = "Actual sample: "+Convert::ToString(f)+"  /  [ "+Convert::ToString(g_DsLSArray->Count)+" ]";   
									this->label83->Refresh(); 

									this->label84->Text = "Position:  X: " + Convert::ToString( Math::Round( gs_RPose.posX,2 ) ) + 
			                            " Y: " + Convert::ToString( Math::Round( gs_RPose.posY,2 ) ) + 
												      	       			 	"  ["+ Convert::ToString( Math::Round( rad2deg(gs_RPose.Angle_RAD),2 ) ) + "°]";  
         this->label84->Refresh(); 

         // create TemporaryMap directly
									switch( this->comboBox23->SelectedIndex ){
							  		case 0:
									  	{
             createTemporaryMap_fromGlobalMap( g_ActualLSScan );
											  break;
										  }
								   case 1:
									   {
								     createTemporaryMap_fromLastScan( g_ActualLSScan );
										   break;
									   }
								  }// switch

									if ( this->checkBox22->Checked == true ){ 
	           DrawTemporaryMap( );
									}// if 

		 				   		// SCANNER ?
	  							  switch ( this->comboBox8->SelectedIndex ){
			 									case 0: // DSMAE 1 Brute Force
				 									{
					 									A_02_01(f);
						 								break;
							  					}
			 									case 1: // DSMAE 2 Brute Force
				 									{
					 									A_02_01(f);
						 								break;
							  					}
			 									case 2: // DSMAE 1 EA
														{
															//Console::WriteLine("DSMAE 1 EA"); 
					 									A_02_02(f);
						 								break;
							  					}
			 									case 3: // DSMAE 2 EA
														{
					 									A_02_02(f);
						 								break;
							  					}
									 			default:
										 			{
											 			break;
												 	}
											 }// switch


									if ( gs_RPose.Angle_RAD > doublePI ){
										  while ( gs_RPose.Angle_RAD > doublePI ){
													     gs_RPose.Angle_RAD = gs_RPose.Angle_RAD - doublePI; 
										  }// while 
									}// if 
									if ( gs_RPose.Angle_RAD < (0) ){
										  while ( gs_RPose.Angle_RAD < (0) ){
													     gs_RPose.Angle_RAD = gs_RPose.Angle_RAD + doublePI; 
												}// while 
									}// if



            for ( Int32 i=0;i<Convert::ToInt32( safe_cast<c104LSScan^>( g_DsLSArray[ g_ActualLSScan ] )->LSItemXY->Length );i++){

		   		         ROBOMAP::c100LSRayBunchItem^ Beam = gcnew c100LSRayBunchItem();

				  			       Beam->PolarLength = safe_cast<c104LSScan^>( g_DsLSArray[ g_ActualLSScan ] )->LSItemPolar[i]->PolarLength ;
						  	       Beam->X = safe_cast<c104LSScan^>( g_DsLSArray[ g_ActualLSScan ] )->LSItemXY[i]->X;
							         Beam->Y = safe_cast<c104LSScan^>( g_DsLSArray[ g_ActualLSScan ] )->LSItemXY[i]->Y;
 						         Beam->Status = 0; 
							         Beam->PosIndex = i; 

							         BeamArray->Add(Beam); 

			         }// for


			         for ( Int32 i=0;i<g_RBeams->Length;i++){
													   if ( safe_cast<c104LSScan^>( g_DsLSArray[ g_ActualLSScan ] )->LSItemPolar[i]->Correct == true ){
				               g_RBeams[i] = true;
																} else
																{
				               g_RBeams[i] = false;
																}// if 
			         }// for i 


												this->label86->Text = "Algorithm: Recursive Line Splitting & LinearRegression";
							     this->label86->Refresh(); 

												Application::DoEvents(); 

												// Build a map according to RBEAMS, 
        				//c100MultiLineApproximationA^ R = gcnew c100MultiLineApproximationA(BeamArray, ApproxLinesArray, g_RBeams ); // do NOT use it, it is for Cascaded EA SLAM, unstable
												c100MultiLineApproximationA^ R = gcnew c100MultiLineApproximationA(BeamArray, ApproxLinesArray, nullptr );
					       R->g_distanceLimit_pointTopoint = Convert::ToDouble( this->numericUpDown77->Value ); 
					       R->g_distanceLimit_pointToLine  = Convert::ToDouble( this->numericUpDown78->Value ); 
					       R->Run();
			 	       delete( R );

		          for ( Int32 i=0;i<Convert::ToInt32( BeamArray->Count );i++){
               delete( safe_cast<c100LSRayBunchItem^>(BeamArray[i]) );
			         }// for
			         BeamArray->Clear();

        				R7 = gs_RPose.Angle_RAD - (g_Ds_DetectionAngle/2);
		          for (Int32 i=0;i<Convert::ToInt32( ApproxLinesArray->Count );i++){

			             R1 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->X1; // 
		 			          R2 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->Y1;

							         R3 = ((R1 * Math::Cos( R7 )) - (R2 * Math::Sin( R7 ))) + gs_RPose.posX;
							         R4 = ((R1 * Math::Sin( R7 )) + (R2 * Math::Cos( R7 ))) + gs_RPose.posY;

						          R1 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->X2; //  
		 			          R2 = safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i])->Y2;

							         R5 = ((R1 * Math::Cos( R7 )) - (R2 * Math::Sin( R7 ))) + gs_RPose.posX;
						  	       R6 = ((R1 * Math::Sin( R7 )) + (R2 * Math::Cos( R7 ))) + gs_RPose.posY;

				            ROBOMAP::c100LineItem^ LineItem = gcnew c100LineItem();

							         LineItem->X1 = R3;
							         LineItem->Y1 = R4;
							         LineItem->X2 = R5;
							         LineItem->Y2 = R6; 

							         LineItem->diffX  = ( LineItem->X2 - LineItem->X1 );
							         LineItem->diffY  = ( LineItem->Y1 - LineItem->Y2 );
							         LineItem->LengthSQR = Math::Pow( (LineItem->X2 - LineItem->X1),2 ) +  Math::Pow( (LineItem->Y2 - LineItem->Y1),2 );
							         LineItem->Length = Math::Sqrt( LineItem->LengthSQR ); 

							         LineItem->u1 = ( LineItem->X2 - LineItem->X1 );
							         LineItem->u2 = ( LineItem->Y2 - LineItem->Y1 );

                if (	LineItem->X1 > LineItem->X2 ){
								           LineItem->Wx1 = LineItem->X2; 
                   LineItem->Wx2 = LineItem->X1; 
										         LineItem->Wx1 = LineItem->Wx1 - g_WindowTolerance; 
                   LineItem->Wx2 = LineItem->Wx2 + g_WindowTolerance; 
							         } else
						          {
			 				           LineItem->Wx1 = LineItem->X1; 
                   LineItem->Wx2 = LineItem->X2; 
  										       LineItem->Wx1 = LineItem->Wx1 - g_WindowTolerance; 
                   LineItem->Wx2 = LineItem->Wx2 + g_WindowTolerance; 
                }// if else
							         if (	LineItem->Y1 > LineItem->Y2 ){
										         LineItem->Wy1 = LineItem->Y2; 
                   LineItem->Wy2 = LineItem->Y1;
										         LineItem->Wy1 = LineItem->Wy1 - g_WindowTolerance; 
                   LineItem->Wy2 = LineItem->Wy2 + g_WindowTolerance;
					           } else
							         {
									  	       LineItem->Wy1 = LineItem->Y1; 
                   LineItem->Wy2 = LineItem->Y2;
 									         LineItem->Wy1 = LineItem->Wy1 - g_WindowTolerance; 
                   LineItem->Wy2 = LineItem->Wy2 + g_WindowTolerance;
							         }// if else

							         LineItem->a2 = LineItem->Y1 - LineItem->Y2; 
							         LineItem->b2 = LineItem->X2 - LineItem->X1;
							         LineItem->c2 = (LineItem->X1*LineItem->Y2)-(LineItem->X2*LineItem->Y1); 

							         LineItem->a1 = LineItem->a2;  // doplneno pro COXe tri radky
							         LineItem->b1 = LineItem->b2;  //
							         LineItem->c1 = LineItem->c2;  //

							         g_LocalMap->Add( LineItem ); //
																// g_GlobalMap->Add( LineItem ); //

   		       }// for

			         for (Int32 i=0;i<Convert::ToInt32( ApproxLinesArray->Count );i++){
				           delete( safe_cast<c100ApproxLineItem^>(ApproxLinesArray[i]) );
			         }// for 
			         ApproxLinesArray->Clear();

												this->label86->Text = "Algorithm: Inserting Actual Scan to Global Map";
							     this->label86->Refresh(); 

												c100InsertLocalMapToGlobalMap^ p = gcnew c100InsertLocalMapToGlobalMap( g_GlobalMap, g_LocalMap );
												p->g_param_split_i_dist                = Convert::ToDouble( this->numericUpDown79->Value ); 
												p->g_param_split_i_angle_LMtoGM        = Convert::ToDouble( this->maskedTextBox44->Text ); 
            p->g_param_split_i_cut_plusLength      = Convert::ToDouble( this->maskedTextBox46->Text ); 
            p->g_param_split_i_cut_overHangLength  = Convert::ToDouble( this->numericUpDown80->Value );
												p->g_param_merge_i_dist                = Convert::ToDouble( this->maskedTextBox45->Text ); 
												p->g_param_merge_i_adjacentPoint       = Convert::ToDouble( this->numericUpDown75->Value ); 
												p->g_param_merge_i_angle_GMmerging     = Convert::ToDouble( this->numericUpDown73->Value );
            p->g_param_merge_i_cut_overHangLength  = Convert::ToDouble( this->numericUpDown74->Value );
            p->g_param_merge_i_smallLineLength     = Convert::ToDouble( this->numericUpDown76->Value );
            p->g_param_remove_i_smallLineLength    = Convert::ToDouble( this->numericUpDown81->Value );
												if ( this->checkBox20->Checked == true ){
													  p->g_param_useSmallLineRemoving = true;
												} else
												{
													  p->g_param_useSmallLineRemoving = false;
												}// if 
												if ( this->checkBox19->Checked == true ){
													  p->g_param_useMerging = true;
												} else
												{
													  p->g_param_useMerging = false;
												}// if 
												p->Run_LMtoGM();
			         delete( p );

												//write correct lines to global map from local map
											 for (Int32 i=0;i<Convert::ToInt32( g_LocalMap->Count );i++){
													   g_GlobalMap->Add( safe_cast<c100LineItem^>(g_LocalMap[i]) );
			         }// for 

												if ( this->checkBox23->Checked == true ){ 
												   DrawGlobalMap();
												}// if 

												if ( this->checkBox24->Checked == true ){ 
												   DrawLocalMap();
												}// if 

												if ( this->checkBox25->Checked == true ){ 
												   DrawState_AllPoses();
												}// if 

								    if ( this->checkBox27->Checked == true ){ 
               DrawState( f );
								   	}// if 

												// Clear localMap after draw !!!
			         g_LocalMap->Clear();

									
									 // LIST of found positions *****************************************************
			       this->listBox2->SelectedIndexChanged -= gcnew System::EventHandler(this, &MapBuilding_LM104::listBox2_SelectedIndexChanged);
			  	    this->listBox2->Items->Add("Scan : "+Convert::ToString(f)+
					                                "   [ X: "+Convert::ToString(gs_RPose.posX) +    
						 		 				    																			" ]  [ Y: "+Convert::ToString(gs_RPose.posY) +
																																					" ]  ang: [ "+Convert::ToString( Math::Round( rad2deg( gs_RPose.Angle_RAD ),2 )  ) + " °] "+
											 		 							    											"   Opt: [ "+Convert::ToString(g_ContinualOptimum)+" ]");
			       this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MapBuilding_LM104::listBox2_SelectedIndexChanged);

										R1 = 0;
          for (UInt32 i=0;i<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );i++){
										   	R1 = R1 + ( safe_cast<c104LSScan^>( g_DsLSArray[f] )->LSItemPolar[i]->PolarLength * Convert::ToDouble( this->maskedTextBox8->Text ) );
          }// for 

				    		ROBOMAP::c104FoundPosition^ Position = gcnew c104FoundPosition( Convert::ToUInt16( coef2PIBeams ), Convert::ToUInt16( g_Ds_NumberOfBeams ) );

						    Position->PosX = gs_RPose.posX;
					     Position->PosY = gs_RPose.posY;
						    Position->Angle = gs_RPose.Angle_RAD; 
          Position->Optimum = 0; //g
						    Position->Sample = f;
						    Position->NoiseLevel = R1; 
						    Position->XYAttrib = ( ( gs_RPose.posY * g_globalPLBMaxX_XY ) + gs_RPose.posX );

				    		Position->DsRHeadX = safe_cast<c104LSScan^>( g_DsLSArray[f] )->RHeadX; 
					    	Position->DsRHeadY = safe_cast<c104LSScan^>( g_DsLSArray[f] )->RHeadY; 

	         for (UInt32 i=0;i<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );i=i+1){

									    	Position->LSItemDsPolar[i] = gcnew c104LSItemPolar();
										    Position->LSItemDsXY[i] = gcnew c104LSItemXY();

              Position->LSItemDsPolar[i]->PolarLength = safe_cast<c104LSScan^>( g_DsLSArray[f] )->LSItemPolar[i]->PolarLength;
              Position->LSItemDsXY[i]->X = safe_cast<c104LSScan^>( g_DsLSArray[f] )->LSItemXY[i]->X;
									     Position->LSItemDsXY[i]->Y = safe_cast<c104LSScan^>( g_DsLSArray[f] )->LSItemXY[i]->Y;

										}// for 

					    	Position->DsMinX_Polar = safe_cast<c104LSScan^>( g_DsLSArray[f])->MinX_Polar; 
	    	    Position->DsMaxX_Polar = safe_cast<c104LSScan^>( g_DsLSArray[f])->MaxX_Polar; 
          Position->DsMinY_Polar = safe_cast<c104LSScan^>( g_DsLSArray[f])->MinY_Polar; 
						    Position->DsMaxY_Polar = safe_cast<c104LSScan^>( g_DsLSArray[f])->MaxY_Polar; 

          Position->DsMinX_XY = safe_cast<c104LSScan^>( g_DsLSArray[f])->MinX_XY;
						    Position->DsMaxX_XY = safe_cast<c104LSScan^>( g_DsLSArray[f])->MaxX_XY; 
						    Position->DsMinY_XY = safe_cast<c104LSScan^>( g_DsLSArray[f])->MinY_XY;  
						    Position->DsMaxY_XY = safe_cast<c104LSScan^>( g_DsLSArray[f])->MaxY_XY; 

			    			R7 = gs_RPose.Angle_RAD - (g_Ds_DetectionAngle/2); 

    			   for (UInt32 i=0;i<=Convert::ToUInt32( g_Ds_NumberOfBeams-1 );i++){

											   Position->Obstacle[i] = gcnew c104ObstacleItem();

											   if ( g_RBeams[i] == false ){
															  Position->Obstacle[i]->Obstacle = true;
														} else
														{
															  Position->Obstacle[i]->Obstacle = false;
														}// if else

				    						Position->LSItemDfXY[i] = gcnew c104LSItemXY();
 
	    				     R1 = safe_cast<c104LSScan^>( g_DsLSArray[f] )->LSItemXY[i]->X; // - safe_cast<c24LSScan^>( g_DsLSArray[Item] )->RHeadX; 
		 		    	    R2 = safe_cast<c104LSScan^>( g_DsLSArray[f] )->LSItemXY[i]->Y;

							       R3 = ((R1 * Math::Cos( R7 )) - (R2 * Math::Sin( R7 )))+ gs_RPose.posX;
							       R4 = ((R1 * Math::Sin( R7 )) + (R2 * Math::Cos( R7 )))+ gs_RPose.posY;

              Position->LSItemDfXY[i]->X = R3;
										    Position->LSItemDfXY[i]->Y = R4;

						    }// for 

						    g_FoundedPositions->Add( Position ); 

          //***********************************************************

									if ( g_TerminateThread == true ){
										  break;
									}// if

									this->label84->Text = "Position:  X: " + Convert::ToString( Math::Round( gs_RPose.posX,2 ) ) + 
			                            " Y: " + Convert::ToString( Math::Round( gs_RPose.posY,2 ) ) + 
												      	       			 	"  ["+ Convert::ToString( Math::Round( rad2deg(gs_RPose.Angle_RAD),2 ) ) + "°]";  
         this->label84->Refresh(); 
 
					}// for ALL SCANS *******************************************************************************


					// final map refinement + show map
					if ( this->checkBox21->Checked == true ){

								this->label86->Text = "Algorithm: Final Map Refinement.";
							 this->label86->Refresh(); 

								c100InsertLocalMapToGlobalMap^ p = gcnew c100InsertLocalMapToGlobalMap( g_GlobalMap, g_LocalMap );
								p->GM_mergeLines( Convert::ToDouble( this->maskedTextBox47->Text ),
									                 Convert::ToDouble( this->numericUpDown83->Value ),
																										Convert::ToDouble( this->numericUpDown85->Value ),
																										Convert::ToDouble( this->numericUpDown84->Value ),
																										Convert::ToDouble( this->numericUpDown82->Value ) ); // angle dist adjacent overhangCUT minimumLineLength
			     delete( p );
											
												if ( this->checkBox23->Checked == true ){ 
												   DrawGlobalMap();
												}// if 

					}// if 


     this->button9->Text = "SEARCHING FINISHED"; 
					this->button7->Enabled = false;  // pause OFF
					this->button8->Enabled = true;   // reset ON

					this->button7->Enabled = true;             // Pause button ON
     this->button7->Text = "Pause/Stop";        // Pause button
					this->button7->ForeColor = Color::Black;   // Pause button
					this->button7->Refresh();
					this->button7->Enabled = false;            // Pause button OFF


     StartStopTime = StartStopTime + DateTime::Now.ToString();
					this->label88->Text = StartStopTime;
					g_StartStopTime = StartStopTime;


			
       if ( this->checkBox40->Checked == true ){
          Console::Beep(); 
       }// if 

					if ( this->listBox2->Items->Count != 0 ){
			     this->listBox2->SelectedIndexChanged -= gcnew System::EventHandler(this, &MapBuilding_LM104::listBox2_SelectedIndexChanged);
						  this->listBox2->SelectedIndex = 0;
			     this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MapBuilding_LM104::listBox2_SelectedIndexChanged);
					}// if 

					// save PTH file 
					if ( this->checkBox36->Checked == true ){ 
					   SavePTHFile( sender, e);
					}// if 

					// SAVE subsidiary description files
					if ( gs_AutoSave.Opened == true ){

					   SaveMSGFile( sender, e );
   					SaveInfoFile( sender, e );

					}// if 

						// priority track bar + popis Enable
						SetPriority(ProcessPriorityClass::Normal);

						// list of found pos
      this->tabPage6->Enabled = true; 


						this->button7->Enabled = false; // OFF Pause/Stop button
						this->button8->Enabled = true;  // ON Reset button

						delete( BeamArray );
						delete( ApproxLinesArray );

      if ( this->checkBox48->Checked == true ){
         Application::Exit(); 
      }// if 

}// private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {

private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
// PAUSE STOP

System::Windows::Forms::DialogResult result;

//***********************************************

        Application::DoEvents();

								this->button7->BackColor = Color::Red;
 							this->button7->ForeColor = Color::White;  // Pause button 
								result = MessageBox::Show( this, "Do you want to stop searching process ?", "Searching process...", MessageBoxButtons::YesNo );

					 		if ( result == ::DialogResult::Yes ){
									  g_TerminateThread = true;
           this->button7->Text = "Wait...";        // Pause button
    							this->button7->Refresh(); 

								} else
								{
           this->button7->Text = "Pause/Stop";        // Pause button
									  g_TerminateThread = false;
											this->button7->ForeColor = Color::Black;
											this->button7->BackColor = Color::Transparent;
    							this->button7->Refresh(); 
											this->button9->Text = "SEARCHING IN PROGRESS";	
										 return;
								}// if

							this->button9->Text = "SEARCHING STOPPED";							
				
							SetPriority(ProcessPriorityClass::Normal);


}// private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {

private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
// RESET DATA

	 	      this->label84->Text = "Position: ";
         this->label84->Refresh(); 

					    this->label87->Text = "Generation:";
							  this->label87->Refresh(); 

	        this->label86->Text = "Algorithm:";
							  this->label86->Refresh(); 

	        this->label85->Text = "Optimum:";
							  this->label85->Refresh(); 

 				    this->button9->Text = "START SEARCHING"; 
					    this->button9->BackColor = Color::Transparent;
					    this->button9->Enabled = true;

   					 this->label88->Text = "Start / StopTime: ";

									this->label83->Text = "Actual sample: ";
							  this->label83->Refresh(); 

         this->button7->Text = "Pause/Stop";        // Pause button
									this->button7->ForeColor = Color::Black;
									this->button7->BackColor = Color::Transparent;
  							this->button7->Refresh(); 
								

			 	this->richTextBox1->Text = "";
			 	this->richTextBox2->Text = "";

					this->button3->Enabled = true;   // reset file ON

					g_TerminateThread = false;

			         //****** ENABLE ALL 2DLS BEAMS ******
			         for ( Int32 i=0;i<g_RBeams->Length;i++){
				            g_RBeams[i] = true;
			         }// for i 
			         //***********************************

					if ( g_TemporaryMap->Count != 0 ){

						 	// vycisti Temporary map 
							 for (Int32 i=0;i<Convert::ToInt32( g_TemporaryMap->Count );i++){
									   delete( safe_cast<c100LineItem^>(g_TemporaryMap[i]) );
			     }// for 
			     g_TemporaryMap->Clear();

					}// if 


					if ( g_FoundedPositions->Count != 0 ){ 

										   for (UInt32 i=0;i<=Convert::ToUInt32( g_FoundedPositions->Count - 1 );i++){

													   	for (UInt32 j=0;j<=Convert::ToUInt32( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDsPolar->Length-1 );j++){
															      delete( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDsPolar[j] );
														   }//for 
										       for (UInt32 j=0;j<=Convert::ToUInt32( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDsXY->Length-1 );j++){
															      delete( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDsXY[j] );
														   }// for

										       for (UInt32 j=0;j<=Convert::ToUInt32( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDfXY->Length-1 );j++){
															      delete( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->LSItemDfXY[j] );
														   }// for

										       for (UInt32 j=0;j<Convert::ToUInt32( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->Obstacle->Length );j++){
															      delete( safe_cast<c104FoundPosition^>(g_FoundedPositions[i])->Obstacle[j] );
														   }// for

														   delete( safe_cast<c104FoundPosition^>(g_FoundedPositions[i]) );

										   }// for

										   g_FoundedPositions->Clear(); 

						}// if 

												//
											 for (Int32 i=0;i<Convert::ToInt32( g_GlobalMap->Count );i++){
													   delete( safe_cast<c100LineItem^>(g_GlobalMap[i]) );
			         }// for 
			         g_GlobalMap->Clear();


      this->listBox2->Items->Clear(); // clear list of found positions 

      this->pictureBox1->Image = nullptr;

   			Application::DoEvents(); 

			   if ( g_PLBBitmap != nullptr ){
 			     delete( g_PLBBitmap );
		 			   g_PLBBitmap = nullptr;
		    }// if
   	  if ( g_PLBBitmapDummy != nullptr ){
		       delete( g_PLBBitmapDummy );
				     g_PLBBitmapDummy = nullptr;
		    }// if
			   if ( g_G_PLB != nullptr ){
		       delete( g_G_PLB );
				     g_G_PLB = nullptr;
		    }// if

						DrawLines();


}// private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {



};// public ref class MapBuilding_LM104 : public System::Windows::Forms::UserControl

}// namespace ROBOMAP {
