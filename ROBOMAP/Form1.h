#pragma once


namespace ROBOMAP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		Int32 g_CFG_FormResolution;
		Int32 g_CFG_MinMaxFormAtStart;

	 String^ g_CFG_RobomapDirectory; 

	private:

		System::Object^ g_ActiveMenuPTR;
		System::UInt16  g_ActiveMenuINT;
		System::Windows::Forms::Form^ g_MyHandle;

	private:
		static const System::UInt16	mnuMapBuilding_LM104                   = 0x00000509;


	public:
		Form1(void)
		{
			InitializeComponent();

   g_ActiveMenuPTR = nullptr;
			g_ActiveMenuINT = 0;

			g_CFG_FormResolution = 13; 
			g_CFG_MinMaxFormAtStart = 2;
			g_CFG_RobomapDirectory = "C:\\ROBOMAP";
	
   switch ( g_CFG_MinMaxFormAtStart ){ // Windows View first !!!
					case 0:
						{
							 this->WindowState = FormWindowState::Normal; 
								break;
						}
					case 1:
						{
							 this->WindowState = FormWindowState::Minimized; 
								break;
						}
					case 2:
						{
							 this->WindowState = FormWindowState::Maximized; 
								break;
						}
					default:
						{
							 this->WindowState = FormWindowState::Normal; 
							 break;
						}
			}// switch 

			switch ( g_CFG_FormResolution ){
					case 0:
						{
							this->Size = System::Drawing::Size( 640,480 );
							break;
						}
					case 1:
						{
							this->Size = System::Drawing::Size( 800,600 );
							break;
						}
					case 2:
						{
							this->Size = System::Drawing::Size( 1024,768 );
							break;
						}
					case 3:
						{
							this->Size = System::Drawing::Size( 1152,864 );
							break;
						}
					case 4:
						{
							this->Size = System::Drawing::Size( 1280,720 );
							break;
						}
					case 5:
						{
							this->Size = System::Drawing::Size( 1280,768 );
							break;
						}
					case 6:
						{
							this->Size = System::Drawing::Size( 1280,960 );
							break;
						}
					case 7:
						{
							this->Size = System::Drawing::Size( 1280,1024 );
							break;
						}
					case 8:
						{
							this->Size = System::Drawing::Size(  1360,768 );
							break;
						}
					case 9:
						{
							this->Size = System::Drawing::Size( 1366,768 );
							break;
						}
					case 10:
						{
							this->Size = System::Drawing::Size( 1400,1050 );
							break;
						}
					case 11:
						{
							this->Size = System::Drawing::Size( 1440,900 );
							break;
						}
					case 12:
						{
							this->Size = System::Drawing::Size( 1600,1200 );
							break;
						}
					case 13:
						{
							this->Size = System::Drawing::Size( 1680,1050 );
							break;
						}
					case 14:
						{
							this->Size = System::Drawing::Size( 1920,1080 );
							break;
						}
					case 15:
						{
							this->Size = System::Drawing::Size( 1920,1200 );
							break;
						}
					default:
						{
							break;
						}
			}// switch
			

   // Robomap Icon
   if ( File::Exists( g_CFG_RobomapDirectory + "\\res\\ROBOMAPStudio.ico" ) == true ){
      this->Icon = gcnew System::Drawing::Icon( g_CFG_RobomapDirectory + "\\res\\ROBOMAPStudio.ico" );  
   } else
   {
      MessageBox::Show( this, "I can not find ROBOMAP Studio Icon - [ " + g_CFG_RobomapDirectory + "\\res\\ROBOMAPStudio.ico" + " ]","Error at RobomapStudio initializing ...", MessageBoxButtons::OK ); 
   }// if else


			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
 private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
 private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
 private: System::Windows::Forms::ToolStripMenuItem^  geometricSLAMToolStripMenuItem;
 private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;





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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->geometricSLAMToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->exitToolStripMenuItem, 
				this->geometricSLAMToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1672, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// geometricSLAMToolStripMenuItem
			// 
			this->geometricSLAMToolStripMenuItem->Name = L"geometricSLAMToolStripMenuItem";
			this->geometricSLAMToolStripMenuItem->Size = System::Drawing::Size(96, 20);
			this->geometricSLAMToolStripMenuItem->Text = L"Geometric SLAM";
			this->geometricSLAMToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::geometricSLAMToolStripMenuItem_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripButton1, 
				this->toolStripButton2, this->toolStripButton3});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1672, 25);
			this->toolStrip1->TabIndex = 1;
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
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"toolStripButton2";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(23, 22);
			this->toolStripButton3->Text = L"toolStripButton3";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Form1::toolStripButton3_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->AutoSize = true;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 49);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1672, 967);
			this->panel1->TabIndex = 2;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1672, 1016);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Robomap Studio - Geometric SLAM";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
           MenuSelector(sender, e, mnuMapBuilding_LM104  );
}// private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {


private: System::Void MenuSelector(System::Object^  sender, System::EventArgs^  e, int mnuType ) {
									
						 		//	Console::WriteLine("ActiveMnuType mnuType {0} {1}",ActiveMnuType.ToString(), mnuType.ToString() );
									if ( g_ActiveMenuINT == mnuType ){
										  return;
									};
									if ( g_ActiveMenuINT == 0 ){
										  g_ActiveMenuINT = mnuType;
									};
         if ( g_ActiveMenuPTR != nullptr ) {
										  this->SuspendLayout();
										  delete( g_ActiveMenuPTR );
												this->ResumeLayout(false);
												this->PerformLayout(); 
									};

         switch ( mnuType ){
											case mnuMapBuilding_LM104 :
												{
													ROBOMAP::MapBuilding_LM104^ ptr = gcnew MapBuilding_LM104( this );  
													this->SuspendLayout();
													panel1->Controls->Add(ptr); 
										 		ptr->Parent = this->panel1; 
													this->ResumeLayout(false);
												 this->PerformLayout(); 
             g_ActiveMenuPTR = ptr;
													g_ActiveMenuINT = mnuType;
													break;
												}	
											
 									default:
										  {
											  break;
										  }
									}// switch
																									
}// private: System::Void MenuSelector


private: System::Void geometricSLAMToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
         MenuSelector(sender, e, mnuMapBuilding_LM104 ); 
}// private: System::Void geometricSLAMToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
// EXIT 

										if ( g_ActiveMenuPTR != nullptr ){
											  delete( g_ActiveMenuPTR );
										}// if 

										GC::Collect();

										Application::DoEvents(); 

										Form1::Close();

										Application::Exit(); 

}// private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

//***************************************************************************************************
//
//***************************************************************************************************

private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
// TOOLSTRIP BACK

								if ( g_ActiveMenuINT == 0 ){
									  return;
								};

        if ( g_ActiveMenuPTR != nullptr ) {
									  this->SuspendLayout();
									  delete( g_ActiveMenuPTR );
											this->ResumeLayout(false);
											this->PerformLayout(); 
									  g_ActiveMenuINT = 0;
           g_ActiveMenuPTR = nullptr;
								};// if 

}// private: System::Void toolStripButton1_Click

private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
// TOOLSTRIP RELOAD 

System::UInt16  RUI16 = 0;

//****************************

								if ( g_ActiveMenuINT == 0 ){
									  return;
								};

        RUI16 = g_ActiveMenuINT;
								g_ActiveMenuINT = 0;

        if ( g_ActiveMenuPTR != nullptr ) {
									  this->SuspendLayout();
									  delete( g_ActiveMenuPTR );
											this->ResumeLayout(false);
											this->PerformLayout(); 
           g_ActiveMenuPTR = nullptr;
								};// if 

								Application::DoEvents(); 

        MenuSelector(sender, e, RUI16 );
									
}// private: System::Void toolStripButton2_Click

private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e) {
// TOOLSTRIP DELETE

								if ( g_ActiveMenuINT == 0 ){
									  return;
								};

        if ( g_ActiveMenuPTR != nullptr ) {
									  this->SuspendLayout();
									  delete( g_ActiveMenuPTR );
											this->ResumeLayout(false);
											this->PerformLayout(); 
									  g_ActiveMenuINT = 0;
           g_ActiveMenuPTR = nullptr;
								};// if 

}// private: System::Void toolStripButton3_Click

};//	public ref class Form1 : public System::Windows::Forms::Form

}// namespace ROBOMAP {

