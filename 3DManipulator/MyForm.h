#pragma once

#include <math.h>

#include "Types.h"
#include "Drawer.h"

namespace My3DManipulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace Types;
	

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();

			bm = gcnew Bitmap(DrawingArea->Width, DrawingArea->Height);
			DrawingArea->Image = bm;
			g = Graphics::FromImage(bm);
			ClearDrawingArea();

			CoordCenX = DrawingArea->Width / 2;
			CoordCenY = DrawingArea->Height / 2;

			zProjectionCoord = 0;
			permutationSpeed = 1;

			Il = linghtIntensivenessScroller->Value / 10.0, 
				Ia = 10, 
				ka = ambientScroll->Value / 100.0, 
				kd = coeffDiffuseScroller->Value / 100.0, 
				K = 1, 
				d = 0, 
				ks = coeffReflectScroll->Value / 100.0, 
				m = reflectionPowerScroller->Value;
			lightSource = gcnew Point3D(0, 0, 100);

			drawer = gcnew Drawer::SimpleDrawer();
			zBuffer = gcnew Dictionary<Point, float>();

			removeInvisible = removeInvisibleLinesCheckBox->Checked;
			useZBuffer = zBufferChecker->Checked;

			ManipulationType = permutationType::Move;
			GeomType = Types::objectType::Tet;
			p = gcnew Pen(Color::White);
			geom = gcnew GeometryObj();

			ReInitPermutationMatrices();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: PictureBox^  DrawingArea;
			 MenuStrip^  menuStrip1;
			 ToolStripMenuItem^  transformToolStripMenuItem;
			 ToolStripMenuItem^  moveToolStripMenuItem;
			 ToolStripMenuItem^  rotateToolStripMenuItem;
			 ToolStripMenuItem^  rotateGlobalToolStripMenuItem;

			 Bitmap^ bm;
			 Graphics^ g;
			 GeometryObj^ geom;
			 int CoordCenX, CoordCenY;
			 Pen^ p;

			 array<array<float>^>^ MxTurn;
			 array<array<float>^>^ MxTurnGlobal;

			 //List<array<array<float>^>^>^ MxTurn;
			 //List<array<array<float>^>^>^ MxTurnGlobal;
			 array<array<float>^>^ MxMove;
			 array<array<float>^>^ MxExtend;
			 array<array<float>^>^ MxMirror;
			 Panel^  panel1;
			 HScrollBar^  xScroll;
			 HScrollBar^  zScroll;
			 HScrollBar^  yScroll;

			 float zProjectionCoord;
			 Types::objectType GeomType;
			 bool removeInvisible;
			 bool useZBuffer;
			 int permutationSpeed;
			 float Il, Ia, ka, kd, K, d, ks, m;
			 Point3D lightSource;

			 Drawer::SimpleDrawer^ drawer;
			 Dictionary<Point, float>^ zBuffer;

			 permutationType ManipulationType;
			 System::Windows::Forms::ToolStripMenuItem^  resizeToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  perspectiveToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  orthogonalToolStripMenuItem;
			 System::Windows::Forms::Label^  label4;
			 System::Windows::Forms::Label^  label3;
			 System::Windows::Forms::Label^  label2;
			 System::Windows::Forms::Label^  label5;
			 System::Windows::Forms::Label^  label1;
			 System::Windows::Forms::ToolStripMenuItem^  figureToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  tetrahedronToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  cubeToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  octahedronToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  icosahedronToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  dodecahedronToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  sphereToolStripMenuItem;
			 System::Windows::Forms::CheckBox^  removeInvisibleLinesCheckBox;

			 System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
			 System::Windows::Forms::Label^  label6;
			 System::Windows::Forms::HScrollBar^  speedScroll;
			 System::Windows::Forms::ToolStripMenuItem^  torusToolStripMenuItem;
			 System::Windows::Forms::CheckBox^  zBufferChecker;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::HScrollBar^  coeffReflectScroll;
	private: System::Windows::Forms::HScrollBar^  coeffDiffuseScroller;
	private: System::Windows::Forms::HScrollBar^  linghtIntensivenessScroller;
	private: System::Windows::Forms::HScrollBar^  ambientScroll;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::HScrollBar^  reflectionPowerScroller;
private: System::Windows::Forms::Label^  label11;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->DrawingArea = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->transformToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->moveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rotateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rotateGlobalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->perspectiveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->orthogonalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->figureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tetrahedronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cubeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->octahedronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->icosahedronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dodecahedronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sphereToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->torusToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->xScroll = (gcnew System::Windows::Forms::HScrollBar());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->zBufferChecker = (gcnew System::Windows::Forms::CheckBox());
			this->removeInvisibleLinesCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->reflectionPowerScroller = (gcnew System::Windows::Forms::HScrollBar());
			this->coeffReflectScroll = (gcnew System::Windows::Forms::HScrollBar());
			this->coeffDiffuseScroller = (gcnew System::Windows::Forms::HScrollBar());
			this->linghtIntensivenessScroller = (gcnew System::Windows::Forms::HScrollBar());
			this->ambientScroll = (gcnew System::Windows::Forms::HScrollBar());
			this->speedScroll = (gcnew System::Windows::Forms::HScrollBar());
			this->zScroll = (gcnew System::Windows::Forms::HScrollBar());
			this->yScroll = (gcnew System::Windows::Forms::HScrollBar());
			this->label11 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DrawingArea))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// DrawingArea
			// 
			this->DrawingArea->Location = System::Drawing::Point(3, 41);
			this->DrawingArea->Name = L"DrawingArea";
			this->DrawingArea->Size = System::Drawing::Size(988, 910);
			this->DrawingArea->TabIndex = 0;
			this->DrawingArea->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->transformToolStripMenuItem,
					this->viewToolStripMenuItem, this->figureToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(11, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(1245, 35);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// transformToolStripMenuItem
			// 
			this->transformToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->moveToolStripMenuItem,
					this->rotateToolStripMenuItem, this->rotateGlobalToolStripMenuItem, this->resizeToolStripMenuItem
			});
			this->transformToolStripMenuItem->Name = L"transformToolStripMenuItem";
			this->transformToolStripMenuItem->Size = System::Drawing::Size(103, 29);
			this->transformToolStripMenuItem->Text = L"Transform";
			// 
			// moveToolStripMenuItem
			// 
			this->moveToolStripMenuItem->Name = L"moveToolStripMenuItem";
			this->moveToolStripMenuItem->Size = System::Drawing::Size(202, 30);
			this->moveToolStripMenuItem->Text = L"Move";
			this->moveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::moveToolStripMenuItem_Click);
			// 
			// rotateToolStripMenuItem
			// 
			this->rotateToolStripMenuItem->Name = L"rotateToolStripMenuItem";
			this->rotateToolStripMenuItem->Size = System::Drawing::Size(202, 30);
			this->rotateToolStripMenuItem->Text = L"Rotate local";
			this->rotateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rotateToolStripMenuItem_Click);
			// 
			// rotateGlobalToolStripMenuItem
			// 
			this->rotateGlobalToolStripMenuItem->Name = L"rotateGlobalToolStripMenuItem";
			this->rotateGlobalToolStripMenuItem->Size = System::Drawing::Size(202, 30);
			this->rotateGlobalToolStripMenuItem->Text = L"Rotate global";
			this->rotateGlobalToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rotateGlobalToolStripMenuItem_Click);
			// 
			// resizeToolStripMenuItem
			// 
			this->resizeToolStripMenuItem->Name = L"resizeToolStripMenuItem";
			this->resizeToolStripMenuItem->Size = System::Drawing::Size(202, 30);
			this->resizeToolStripMenuItem->Text = L"Resize";
			this->resizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::resizeToolStripMenuItem_Click);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->perspectiveToolStripMenuItem,
					this->orthogonalToolStripMenuItem
			});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(61, 29);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// perspectiveToolStripMenuItem
			// 
			this->perspectiveToolStripMenuItem->Name = L"perspectiveToolStripMenuItem";
			this->perspectiveToolStripMenuItem->Size = System::Drawing::Size(188, 30);
			this->perspectiveToolStripMenuItem->Text = L"Perspective";
			this->perspectiveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::perspectiveToolStripMenuItem_Click);
			// 
			// orthogonalToolStripMenuItem
			// 
			this->orthogonalToolStripMenuItem->Name = L"orthogonalToolStripMenuItem";
			this->orthogonalToolStripMenuItem->Size = System::Drawing::Size(188, 30);
			this->orthogonalToolStripMenuItem->Text = L"Orthogonal";
			this->orthogonalToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::orthogonalToolStripMenuItem_Click);
			// 
			// figureToolStripMenuItem
			// 
			this->figureToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->tetrahedronToolStripMenuItem,
					this->cubeToolStripMenuItem, this->octahedronToolStripMenuItem, this->icosahedronToolStripMenuItem, this->dodecahedronToolStripMenuItem,
					this->sphereToolStripMenuItem, this->torusToolStripMenuItem
			});
			this->figureToolStripMenuItem->Name = L"figureToolStripMenuItem";
			this->figureToolStripMenuItem->Size = System::Drawing::Size(73, 29);
			this->figureToolStripMenuItem->Text = L"Figure";
			// 
			// tetrahedronToolStripMenuItem
			// 
			this->tetrahedronToolStripMenuItem->Name = L"tetrahedronToolStripMenuItem";
			this->tetrahedronToolStripMenuItem->Size = System::Drawing::Size(214, 30);
			this->tetrahedronToolStripMenuItem->Text = L"Tetrahedron";
			this->tetrahedronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tetrahedronToolStripMenuItem_Click);
			// 
			// cubeToolStripMenuItem
			// 
			this->cubeToolStripMenuItem->Name = L"cubeToolStripMenuItem";
			this->cubeToolStripMenuItem->Size = System::Drawing::Size(214, 30);
			this->cubeToolStripMenuItem->Text = L"Cube";
			this->cubeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cubeToolStripMenuItem_Click);
			// 
			// octahedronToolStripMenuItem
			// 
			this->octahedronToolStripMenuItem->Name = L"octahedronToolStripMenuItem";
			this->octahedronToolStripMenuItem->Size = System::Drawing::Size(214, 30);
			this->octahedronToolStripMenuItem->Text = L"Octahedron";
			this->octahedronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::octahedronToolStripMenuItem_Click);
			// 
			// icosahedronToolStripMenuItem
			// 
			this->icosahedronToolStripMenuItem->Name = L"icosahedronToolStripMenuItem";
			this->icosahedronToolStripMenuItem->Size = System::Drawing::Size(214, 30);
			this->icosahedronToolStripMenuItem->Text = L"Icosahedron";
			this->icosahedronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::icosahedronToolStripMenuItem_Click);
			// 
			// dodecahedronToolStripMenuItem
			// 
			this->dodecahedronToolStripMenuItem->Name = L"dodecahedronToolStripMenuItem";
			this->dodecahedronToolStripMenuItem->Size = System::Drawing::Size(214, 30);
			this->dodecahedronToolStripMenuItem->Text = L"Dodecahedron";
			this->dodecahedronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::dodecahedronToolStripMenuItem_Click);
			// 
			// sphereToolStripMenuItem
			// 
			this->sphereToolStripMenuItem->Name = L"sphereToolStripMenuItem";
			this->sphereToolStripMenuItem->Size = System::Drawing::Size(214, 30);
			this->sphereToolStripMenuItem->Text = L"Sphere";
			this->sphereToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sphereToolStripMenuItem_Click);
			// 
			// torusToolStripMenuItem
			// 
			this->torusToolStripMenuItem->Name = L"torusToolStripMenuItem";
			this->torusToolStripMenuItem->Size = System::Drawing::Size(214, 30);
			this->torusToolStripMenuItem->Text = L"Torus";
			this->torusToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::torusToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(74, 29);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// xScroll
			// 
			this->xScroll->LargeChange = 1;
			this->xScroll->Location = System::Drawing::Point(154, 78);
			this->xScroll->Maximum = 360;
			this->xScroll->Minimum = -360;
			this->xScroll->Name = L"xScroll";
			this->xScroll->Size = System::Drawing::Size(48, 26);
			this->xScroll->TabIndex = 2;
			this->xScroll->ValueChanged += gcnew System::EventHandler(this, &MyForm::xScroll_ValueChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->zBufferChecker);
			this->panel1->Controls->Add(this->removeInvisibleLinesCheckBox);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->reflectionPowerScroller);
			this->panel1->Controls->Add(this->coeffReflectScroll);
			this->panel1->Controls->Add(this->coeffDiffuseScroller);
			this->panel1->Controls->Add(this->linghtIntensivenessScroller);
			this->panel1->Controls->Add(this->ambientScroll);
			this->panel1->Controls->Add(this->speedScroll);
			this->panel1->Controls->Add(this->zScroll);
			this->panel1->Controls->Add(this->yScroll);
			this->panel1->Controls->Add(this->xScroll);
			this->panel1->Location = System::Drawing::Point(997, 36);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(236, 915);
			this->panel1->TabIndex = 3;
			// 
			// zBufferChecker
			// 
			this->zBufferChecker->AutoSize = true;
			this->zBufferChecker->Location = System::Drawing::Point(21, 378);
			this->zBufferChecker->Margin = System::Windows::Forms::Padding(2);
			this->zBufferChecker->Name = L"zBufferChecker";
			this->zBufferChecker->Size = System::Drawing::Size(91, 24);
			this->zBufferChecker->TabIndex = 5;
			this->zBufferChecker->Text = L"Z buffer";
			this->zBufferChecker->UseVisualStyleBackColor = true;
			this->zBufferChecker->CheckedChanged += gcnew System::EventHandler(this, &MyForm::zBufferChecker_CheckedChanged);
			// 
			// removeInvisibleLinesCheckBox
			// 
			this->removeInvisibleLinesCheckBox->AutoSize = true;
			this->removeInvisibleLinesCheckBox->Location = System::Drawing::Point(22, 340);
			this->removeInvisibleLinesCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->removeInvisibleLinesCheckBox->Name = L"removeInvisibleLinesCheckBox";
			this->removeInvisibleLinesCheckBox->Size = System::Drawing::Size(195, 24);
			this->removeInvisibleLinesCheckBox->TabIndex = 5;
			this->removeInvisibleLinesCheckBox->Text = L"Remove invisible faces";
			this->removeInvisibleLinesCheckBox->UseVisualStyleBackColor = true;
			this->removeInvisibleLinesCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Blue;
			this->label4->Location = System::Drawing::Point(96, 168);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(19, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Z";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Green;
			this->label3->Location = System::Drawing::Point(96, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(20, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Y";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(96, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"X";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(18, 229);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 20);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Speed";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(96, 200);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 20);
			this->label5->TabIndex = 3;
			this->label5->Text = L"axis";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 736);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(121, 20);
			this->label10->TabIndex = 3;
			this->label10->Text = L"reflection power";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(3, 657);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(158, 20);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Reflection coefficient";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 579);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(140, 20);
			this->label8->TabIndex = 3;
			this->label8->Text = L"Diffusal coefficient";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 506);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(193, 20);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Source light intensiveness";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Move along";
			// 
			// reflectionPowerScroller
			// 
			this->reflectionPowerScroller->LargeChange = 2;
			this->reflectionPowerScroller->Location = System::Drawing::Point(22, 770);
			this->reflectionPowerScroller->Maximum = 26;
			this->reflectionPowerScroller->Minimum = 2;
			this->reflectionPowerScroller->Name = L"reflectionPowerScroller";
			this->reflectionPowerScroller->Size = System::Drawing::Size(180, 26);
			this->reflectionPowerScroller->SmallChange = 2;
			this->reflectionPowerScroller->TabIndex = 2;
			this->reflectionPowerScroller->Value = 2;
			this->reflectionPowerScroller->ValueChanged += gcnew System::EventHandler(this, &MyForm::reflectionPowerScroller_ValueChanged);
			// 
			// coeffReflectScroll
			// 
			this->coeffReflectScroll->LargeChange = 1;
			this->coeffReflectScroll->Location = System::Drawing::Point(22, 691);
			this->coeffReflectScroll->Name = L"coeffReflectScroll";
			this->coeffReflectScroll->Size = System::Drawing::Size(180, 26);
			this->coeffReflectScroll->TabIndex = 2;
			this->coeffReflectScroll->Value = 1;
			this->coeffReflectScroll->ValueChanged += gcnew System::EventHandler(this, &MyForm::coeffReflectScroll_ValueChanged);
			// 
			// coeffDiffuseScroller
			// 
			this->coeffDiffuseScroller->LargeChange = 1;
			this->coeffDiffuseScroller->Location = System::Drawing::Point(21, 608);
			this->coeffDiffuseScroller->Name = L"coeffDiffuseScroller";
			this->coeffDiffuseScroller->Size = System::Drawing::Size(180, 26);
			this->coeffDiffuseScroller->TabIndex = 2;
			this->coeffDiffuseScroller->Value = 1;
			this->coeffDiffuseScroller->ValueChanged += gcnew System::EventHandler(this, &MyForm::coeffDiffuseScroller_ValueChanged);
			// 
			// linghtIntensivenessScroller
			// 
			this->linghtIntensivenessScroller->LargeChange = 1;
			this->linghtIntensivenessScroller->Location = System::Drawing::Point(21, 539);
			this->linghtIntensivenessScroller->Name = L"linghtIntensivenessScroller";
			this->linghtIntensivenessScroller->Size = System::Drawing::Size(180, 26);
			this->linghtIntensivenessScroller->TabIndex = 2;
			this->linghtIntensivenessScroller->Value = 1;
			this->linghtIntensivenessScroller->ValueChanged += gcnew System::EventHandler(this, &MyForm::linghtIntensivenessScroller_ValueChanged);
			// 
			// ambientScroll
			// 
			this->ambientScroll->LargeChange = 1;
			this->ambientScroll->Location = System::Drawing::Point(21, 456);
			this->ambientScroll->Name = L"ambientScroll";
			this->ambientScroll->Size = System::Drawing::Size(180, 26);
			this->ambientScroll->TabIndex = 2;
			this->ambientScroll->Value = 15;
			this->ambientScroll->ValueChanged += gcnew System::EventHandler(this, &MyForm::ambientScroll_ValueChanged);
			// 
			// speedScroll
			// 
			this->speedScroll->LargeChange = 1;
			this->speedScroll->Location = System::Drawing::Point(22, 258);
			this->speedScroll->Maximum = 20;
			this->speedScroll->Minimum = 1;
			this->speedScroll->Name = L"speedScroll";
			this->speedScroll->Size = System::Drawing::Size(180, 26);
			this->speedScroll->TabIndex = 2;
			this->speedScroll->Value = 1;
			this->speedScroll->ValueChanged += gcnew System::EventHandler(this, &MyForm::speedScroll_ValueChanged);
			// 
			// zScroll
			// 
			this->zScroll->LargeChange = 1;
			this->zScroll->Location = System::Drawing::Point(154, 162);
			this->zScroll->Maximum = 360;
			this->zScroll->Minimum = -360;
			this->zScroll->Name = L"zScroll";
			this->zScroll->Size = System::Drawing::Size(48, 26);
			this->zScroll->TabIndex = 2;
			this->zScroll->ValueChanged += gcnew System::EventHandler(this, &MyForm::zScroll_ValueChanged);
			// 
			// yScroll
			// 
			this->yScroll->LargeChange = 1;
			this->yScroll->Location = System::Drawing::Point(154, 119);
			this->yScroll->Maximum = 360;
			this->yScroll->Minimum = -360;
			this->yScroll->Name = L"yScroll";
			this->yScroll->Size = System::Drawing::Size(48, 26);
			this->yScroll->TabIndex = 2;
			this->yScroll->ValueChanged += gcnew System::EventHandler(this, &MyForm::yScroll_ValueChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(3, 422);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(68, 20);
			this->label11->TabIndex = 3;
			this->label11->Text = L"Ambient";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1245, 1003);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->DrawingArea);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DrawingArea))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void ClearDrawingArea()
		{
			g->Clear(Color::Black);
			//DrawingArea->Refresh();
		}

		System::Void RenderCurrent()
		{
			g->DrawLine(gcnew Pen(Color::Red), 0, CoordCenY, DrawingArea->Width, CoordCenY);
			g->DrawLine(gcnew Pen(Color::Green), CoordCenX, 0, CoordCenX, DrawingArea->Height);

			zBuffer = gcnew Dictionary<Point, float>();

			auto mx = ApplyMatrices(geom->getMatrices(GeomType));

			for each (auto poli in mx)
			{

				auto p1 = poli[0];
				auto p2 = poli[1];
				auto p3 = poli[2];

				if (!useZBuffer)
				{
					g->DrawLine(p, CoordCenX + p1[0], CoordCenY + p1[1], CoordCenX + p2[0], CoordCenY + p2[1]);
					g->DrawLine(p, CoordCenX + p1[0], CoordCenY + p1[1], CoordCenX + p3[0], CoordCenY + p3[1]);
					g->DrawLine(p, CoordCenX + p3[0], CoordCenY + p3[1], CoordCenX + p2[0], CoordCenY + p2[1]);
				}
				else
				{
					auto pixelsToDraw = GetPoliPixels(p1, p2, p3);
					
					Point3D pCen = (gcnew Point3D(p1) + gcnew Point3D(p2) + gcnew Point3D(p3))/3;
					auto planeEq = gcnew PlaneEquation(gcnew Point3D(p1), gcnew Point3D(p2), gcnew Point3D(p3));
					// normal
					// Il, Ia, ka, kd, K, d, ks, m
					auto L = gcnew Point3D( -(pCen.X - lightSource.X), -(pCen.Y - lightSource.Y),  (pCen.Z - lightSource.Z));
					auto S = gcnew Point3D(L->X,L->Y, L->Z);
					auto Normal = NormalizeVector(gcnew Point3D(planeEq->X, planeEq->Y, planeEq->Z));
					float dotLN = DotProductNonNormalized(Normal, L);
					auto R = gcnew Point3D((-S->X - 2 * dotLN*Normal->X), (-S->Y - 2 * dotLN*Normal->Y), S->Z - 2 * dotLN*Normal->Z);
					

					auto dotNL = DotProduct(Normal, L);
					if (dotNL < 0) dotNL = 0;
					auto dotRS = DotProduct(R, S);
					if (dotRS > 0) dotRS = 0;
					
					//Phong equation simplified
					float light = Ia*ka + Il / (d + K)*(kd*dotNL + ks*Math::Abs(Math::Pow(dotRS, m)));
					if (light < 0) light = 0;

					Color^ col = Color::FromArgb(255, 0, 255 * ((light / 10) > 1 ? 1 : light / 10), 0);

					DrawPixels(*col, pixelsToDraw, planeEq);
				}
			}

			DrawingArea->Refresh();
		}

		void DrawPixels(Color col, Dictionary<Point, System::Object^>^ pixelsToDraw, PlaneEquation^ peq)
		{
			for each (auto pixel in pixelsToDraw->Keys)
			{
				if (pixel.X >= 0 && pixel.X < bm->Width
					&& pixel.Y >= 0 && pixel.Y < bm->Height)
				{
					auto z = peq->GetZCoord(Point(pixel.X - CoordCenX, pixel.Y - CoordCenY));

					if (!zBuffer->ContainsKey(pixel))
					{
						zBuffer->Add(pixel, z);
						bm->SetPixel(pixel.X, pixel.Y, col);
					}
					else if (zBuffer[pixel] > z)
					{
						zBuffer[pixel] = z;
						bm->SetPixel(pixel.X, pixel.Y, col);
					}
				}
			}
		}

		float VectorLength(Point3D^ vec)
		{
			return Math::Sqrt(vec->X*vec->X + vec->Y*vec->Y + vec->Z*vec->Z);
		}

		Point3D^ NormalizeVector(Point3D^ vec)
		{
			float length = VectorLength(vec);
			return gcnew Point3D(vec->X / length, vec->Y / length, vec->Z / length);
		}

		float DotProductNonNormalized(Point3D^ vec1, Point3D^ vec2)
		{
			return vec1->X*vec2->X + vec1->Y*vec2->Y + vec1->Z*vec2->Z;;
		}

		float DotProduct(Point3D^ vec1, Point3D^ vec2)
		{
			return DotProductNonNormalized(NormalizeVector(vec1), NormalizeVector(vec2));
		}

		Dictionary<Point, System::Object^>^ GetPoliPixels(array<float>^ p1, array<float>^ p2, array<float>^ p3)
		{
			auto pixelsToDraw = gcnew Dictionary<Point, System::Object^>();

			//Add line pixels
			{
				auto linePixels = drawer->GetLinePixels(CoordCenX + p1[0], CoordCenY + p1[1], CoordCenX + p2[0], CoordCenY + p2[1]);
				linePixels->AddRange(drawer->GetLinePixels(CoordCenX + p1[0], CoordCenY + p1[1], CoordCenX + p3[0], CoordCenY + p3[1]));
				linePixels->AddRange(drawer->GetLinePixels(CoordCenX + p3[0], CoordCenY + p3[1], CoordCenX + p2[0], CoordCenY + p2[1]));

				for each (auto pixel in linePixels)
				{
					if (!pixelsToDraw->ContainsKey(pixel))
						pixelsToDraw->Add(pixel, nullptr);
				}
			}

			//Add filling pixels
			{
				List<GeometryTypes::IGeometry^>^ lines = gcnew List<GeometryTypes::IGeometry^>();
				lines->Add(GeometryTypes::Line(CoordCenX + p1[0], CoordCenY + p1[1], CoordCenX + p2[0], CoordCenY + p2[1], Color::Black));
				lines->Add(GeometryTypes::Line(CoordCenX + p2[0], CoordCenY + p2[1], CoordCenX + p3[0], CoordCenY + p3[1], Color::Black));
				lines->Add(GeometryTypes::Line(CoordCenX + p3[0], CoordCenY + p3[1], CoordCenX + p1[0], CoordCenY + p1[1], Color::Black));

				for each (auto pixel in drawer->GetFillGeometryObjectPixels(lines))
				{
					if (!pixelsToDraw->ContainsKey(pixel))
						pixelsToDraw->Add(pixel, nullptr);
				}
			}

			return pixelsToDraw;
		}

		List<array<array<float>^>^>^ ApplyMatrices(List<array<array<float>^>^>^ mx)
		{
			List<array<array<float>^>^>^ res = gcnew List<array<array<float>^>^>();

			for each (auto poli in mx)
			{
				auto polim = MultiplyMatrices(poli, MxExtend);

				//Perform local coordinates rotation
				polim = MultiplyMatrices(polim, MxTurn);

				//Move object
				polim = AddMatrices(polim, MxMove);

				polim = MultiplyMatrices(polim, MxTurnGlobal);

				//Apply projection
				polim = ApplyProjection(polim);

				if (removeInvisible && !IsVisible(polim)) continue;

				res->Add(polim);
			}

			return res;
		}

		bool IsVisible(array<array<float>^>^ poli)
		{
			int z = (poli[1][0] - poli[0][0]) * (poli[2][1] - poli[0][1]) - (poli[2][0] - poli[0][0]) * (poli[1][1] - poli[0][1]);
			if (z < 0) return true;
			return false;
		}

		array<array<float>^>^ MultiplyMatrices(array<array<float>^>^ A, array<array<float>^>^ P)
		{
			array<array<float>^>^ res = gcnew array<array<float>^>(A->Length) { gcnew array<float>(3), gcnew array<float>(3), gcnew array<float>(3) };

			for (size_t i = 0; i < A->Length; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					for (size_t k = 0; k < 3; k++)
					{
						res[i][j] += A[i][k] * P[k][j];
					}
				}
			}

			return res;
		}

		array<array<float>^>^ AddMatrices(array<array<float>^>^ A, array<array<float>^>^ P)
		{
			array<array<float>^>^ res = gcnew array<array<float>^>(A->Length) { gcnew array<float>(3), gcnew array<float>(3), gcnew array<float>(3) };

			for (size_t i = 0; i < A->Length; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					res[i][j] = A[i][j] + P[0][j];
				}
			}

			return res;
		}

		array<array<float>^>^ MakeDiagonal(array<array<float>^>^ matrix)
		{
			for (size_t i = 0; i < matrix->Length; i++)
			{
				matrix[i][i] = 1;
			}

			return matrix;
		}

		array<array<float>^>^ ApplyProjection(array<array<float>^>^ matrix)
		{
			for (size_t i = 0; i < matrix->Length; i++)
			{
				matrix[i][0] = matrix[i][0] / (matrix[i][2] * zProjectionCoord + 1);
				matrix[i][1] = matrix[i][1] / (matrix[i][2] * zProjectionCoord + 1);
			}

			return matrix;
		}

	private: System::Void xScroll_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		MoveFigure(coordType::X, xScroll);
	}

	private: System::Void yScroll_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		MoveFigure(coordType::Y, yScroll);
	}

	private: System::Void zScroll_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		MoveFigure(coordType::Z, zScroll);
	}

	private: System::Void MoveFigure(coordType coord, HScrollBar^ scroll)
	{
		if (scroll->Value == 0) return;

		if (ManipulationType == permutationType::Move)
		{
			for (size_t i = 0; i < 3; i++)
			{
				MxMove[i][(int)coord] += scroll->Value * permutationSpeed;
			}
		}
		else if (ManipulationType == permutationType::Resize)
		{
			MxExtend[(int)coord][(int)coord] *= (1 + (scroll->Value / 50.0) *permutationSpeed);
		}
		else if (ManipulationType == permutationType::Rotate || ManipulationType == permutationType::RotateGlobal)
		{
			bool wasFirstRow = false;
			bool wasFirstValue = false;
			auto mx = MakeDiagonal(gcnew array<array<float>^>(3) { gcnew array<float>(3), gcnew array<float>(3), gcnew array<float>(3) });

			for (size_t i = 0; i < 3; i++)
			{
				if (i == (int)coord) continue;

				for (size_t j = 0; j < 3; j++)
				{
					if (j == (int)coord) continue;

					float curMultiplier;
					if (!wasFirstRow && !wasFirstValue)
					{
						curMultiplier = Math::Cos(permutationSpeed*scroll->Value / 90.0);
						wasFirstValue = true;
					}
					else if (!wasFirstRow && wasFirstValue)
					{
						curMultiplier = Math::Sin(permutationSpeed*scroll->Value / 90.0);
						wasFirstRow = true;
						wasFirstValue = false;
					}
					else if (wasFirstRow && !wasFirstValue)
					{
						curMultiplier = -Math::Sin(permutationSpeed*scroll->Value / 90.0);
						wasFirstValue = true;
					}
					else
					{
						curMultiplier = Math::Cos(permutationSpeed*scroll->Value / 90.0);
					}

					if (mx[i][j] != 0) mx[i][j] *= curMultiplier;
					else			   mx[i][j] = curMultiplier;
				}
			}

			if (ManipulationType == permutationType::Rotate)
				//MxTurn->Add(mx);
				MxTurn = MultiplyMatrices(MxTurn, mx);
			else if (ManipulationType == permutationType::RotateGlobal)
				//MxTurnGlobal->Add(mx);
				MxTurnGlobal = MultiplyMatrices(MxTurnGlobal, mx);
		}
		scroll->Value = 0;

		ClearDrawingArea();
		RenderCurrent();
	}

	private:
		System::Void moveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			label1->Text = "Move along";
			ManipulationType = permutationType::Move;
		}
		System::Void rotateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			label1->Text = "Rotate around local";
			ManipulationType = permutationType::Rotate;
		}
		System::Void rotateGlobalToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			label1->Text = "Rotate around";
			ManipulationType = permutationType::RotateGlobal;
		}
		System::Void resizeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			label1->Text = "Stretch along";
			ManipulationType = permutationType::Resize;
		}
		System::Void perspectiveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ChangeProjection(0.001);
		}
		System::Void orthogonalToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ChangeProjection(0);
		}

		System::Void ChangeProjection(float newProjectionValue)
		{
			zProjectionCoord = newProjectionValue;
			ClearDrawingArea();
			RenderCurrent();
		}

		System::Void ReInitPermutationMatrices()
		{
			MxExtend = MakeDiagonal(gcnew array<array<float>^>(3) { gcnew array<float>(3), gcnew array<float>(3), gcnew array<float>(3) });
			/*MxTurn = gcnew List<array<array<float>^>^>();
			MxTurnGlobal = gcnew List<array<array<float>^>^>();*/
			MxTurn = MakeDiagonal(gcnew array<array<float>^>(3) {
				gcnew array<float>(3), gcnew array<float>(3)
					, gcnew array<float>(3)
			});
			MxTurnGlobal = MakeDiagonal(gcnew array<array<float>^>(3) {
				gcnew array<float>(3), gcnew array<float>(3)
					, gcnew array<float>(3)
			});
			MxMirror = MakeDiagonal(gcnew array<array<float>^>(3) { gcnew array<float>(3), gcnew array<float>(3), gcnew array<float>(3) });
			MxMove = gcnew array<array<float>^>(3) { gcnew array<float>(3), gcnew array<float>(3), gcnew array<float>(3) };

			ClearDrawingArea();
			RenderCurrent();

			DrawingArea->Refresh();
		}

		System::Void tetrahedronToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			GeomType = Types::objectType::Tet;
			ReInitPermutationMatrices();
		}
		System::Void cubeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			GeomType = Types::objectType::Cub;
			ReInitPermutationMatrices();
		}
		System::Void octahedronToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			GeomType = Types::objectType::Oct;
			ReInitPermutationMatrices();
		}
		System::Void icosahedronToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			GeomType = Types::objectType::Ico;
			ReInitPermutationMatrices();
		}
		System::Void dodecahedronToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			GeomType = Types::objectType::Dod;
			ReInitPermutationMatrices();
		}
		System::Void sphereToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			GeomType = Types::objectType::Sph;
			ReInitPermutationMatrices();
		}
		System::Void torusToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			GeomType = Types::objectType::Tor;
			ReInitPermutationMatrices();
		}
		System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			removeInvisible = removeInvisibleLinesCheckBox->Checked;
			ClearDrawingArea();
			RenderCurrent();
		}
		System::Void zBufferChecker_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			useZBuffer = zBufferChecker->Checked;
			ClearDrawingArea();
			RenderCurrent();
		}

		System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			MessageBox::Show("Author: Sergey Pavlov\ntask: Seminar 5\nYou can pick figure to show in the Figure menu.\n" +
				"Permutation method can be chosen in the Transform menu. To control it, you can use arrows on the right menu.\n" +
				"Camera mode can be switched in the View menu.\n"+
				"seminar 6: you can turn on Z-buffer with rendering. Underneath the switcher most of the coefficients might be changed.");
		}
		System::Void speedScroll_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			permutationSpeed = speedScroll->Value;
		}
		System::Void ambientScroll_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			ka = ambientScroll->Value / 100.0;
			ClearDrawingArea();
			RenderCurrent();
		}
		System::Void linghtIntensivenessScroller_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			Il = linghtIntensivenessScroller->Value / 10.0;
			ClearDrawingArea();
			RenderCurrent();
		}
		System::Void coeffDiffuseScroller_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			kd = coeffDiffuseScroller->Value / 100.0;
			ClearDrawingArea();
			RenderCurrent();
		}
		System::Void coeffReflectScroll_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			ks = coeffReflectScroll->Value / 100.0;
			ClearDrawingArea();
			RenderCurrent();
		}
		System::Void reflectionPowerScroller_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			m = reflectionPowerScroller->Value;//reflectionPowerScroller->Value %2 > 0 ? reflectionPowerScroller->Value + 1 : reflectionPowerScroller->Value;
			ClearDrawingArea();
			RenderCurrent();
		}
};
}
