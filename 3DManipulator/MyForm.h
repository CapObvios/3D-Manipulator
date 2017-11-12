#pragma once

#include "Types.h"
#include <math.h>

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

			removeInvisible = removeInvisibleLinesCheckBox->Checked;

			ManipulationType = permutationType::Move;

			GeomType = Types::objectType::Tet;

			p = gcnew Pen(Color::Black);

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
	private: System::Windows::Forms::CheckBox^  removeInvisibleLinesCheckBox;

	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;

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
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->xScroll = (gcnew System::Windows::Forms::HScrollBar());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->removeInvisibleLinesCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->zScroll = (gcnew System::Windows::Forms::HScrollBar());
			this->yScroll = (gcnew System::Windows::Forms::HScrollBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DrawingArea))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// DrawingArea
			// 
			this->DrawingArea->Location = System::Drawing::Point(5, 64);
			this->DrawingArea->Margin = System::Windows::Forms::Padding(5);
			this->DrawingArea->Name = L"DrawingArea";
			this->DrawingArea->Size = System::Drawing::Size(1756, 1410);
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
			this->menuStrip1->Size = System::Drawing::Size(2213, 51);
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
			this->transformToolStripMenuItem->Size = System::Drawing::Size(161, 45);
			this->transformToolStripMenuItem->Text = L"Transform";
			// 
			// moveToolStripMenuItem
			// 
			this->moveToolStripMenuItem->Name = L"moveToolStripMenuItem";
			this->moveToolStripMenuItem->Size = System::Drawing::Size(310, 46);
			this->moveToolStripMenuItem->Text = L"Move";
			this->moveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::moveToolStripMenuItem_Click);
			// 
			// rotateToolStripMenuItem
			// 
			this->rotateToolStripMenuItem->Name = L"rotateToolStripMenuItem";
			this->rotateToolStripMenuItem->Size = System::Drawing::Size(310, 46);
			this->rotateToolStripMenuItem->Text = L"Rotate local";
			this->rotateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rotateToolStripMenuItem_Click);
			// 
			// rotateGlobalToolStripMenuItem
			// 
			this->rotateGlobalToolStripMenuItem->Name = L"rotateGlobalToolStripMenuItem";
			this->rotateGlobalToolStripMenuItem->Size = System::Drawing::Size(310, 46);
			this->rotateGlobalToolStripMenuItem->Text = L"Rotate global";
			this->rotateGlobalToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rotateGlobalToolStripMenuItem_Click);
			// 
			// resizeToolStripMenuItem
			// 
			this->resizeToolStripMenuItem->Name = L"resizeToolStripMenuItem";
			this->resizeToolStripMenuItem->Size = System::Drawing::Size(310, 46);
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
			this->viewToolStripMenuItem->Size = System::Drawing::Size(94, 45);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// perspectiveToolStripMenuItem
			// 
			this->perspectiveToolStripMenuItem->Name = L"perspectiveToolStripMenuItem";
			this->perspectiveToolStripMenuItem->Size = System::Drawing::Size(286, 46);
			this->perspectiveToolStripMenuItem->Text = L"Perspective";
			this->perspectiveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::perspectiveToolStripMenuItem_Click);
			// 
			// orthogonalToolStripMenuItem
			// 
			this->orthogonalToolStripMenuItem->Name = L"orthogonalToolStripMenuItem";
			this->orthogonalToolStripMenuItem->Size = System::Drawing::Size(286, 46);
			this->orthogonalToolStripMenuItem->Text = L"Orthogonal";
			this->orthogonalToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::orthogonalToolStripMenuItem_Click);
			// 
			// figureToolStripMenuItem
			// 
			this->figureToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->tetrahedronToolStripMenuItem,
					this->cubeToolStripMenuItem, this->octahedronToolStripMenuItem, this->icosahedronToolStripMenuItem, this->dodecahedronToolStripMenuItem,
					this->sphereToolStripMenuItem
			});
			this->figureToolStripMenuItem->Name = L"figureToolStripMenuItem";
			this->figureToolStripMenuItem->Size = System::Drawing::Size(113, 45);
			this->figureToolStripMenuItem->Text = L"Figure";
			// 
			// tetrahedronToolStripMenuItem
			// 
			this->tetrahedronToolStripMenuItem->Name = L"tetrahedronToolStripMenuItem";
			this->tetrahedronToolStripMenuItem->Size = System::Drawing::Size(331, 46);
			this->tetrahedronToolStripMenuItem->Text = L"Tetrahedron";
			this->tetrahedronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tetrahedronToolStripMenuItem_Click);
			// 
			// cubeToolStripMenuItem
			// 
			this->cubeToolStripMenuItem->Name = L"cubeToolStripMenuItem";
			this->cubeToolStripMenuItem->Size = System::Drawing::Size(331, 46);
			this->cubeToolStripMenuItem->Text = L"Cube";
			this->cubeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cubeToolStripMenuItem_Click);
			// 
			// octahedronToolStripMenuItem
			// 
			this->octahedronToolStripMenuItem->Name = L"octahedronToolStripMenuItem";
			this->octahedronToolStripMenuItem->Size = System::Drawing::Size(331, 46);
			this->octahedronToolStripMenuItem->Text = L"Octahedron";
			this->octahedronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::octahedronToolStripMenuItem_Click);
			// 
			// icosahedronToolStripMenuItem
			// 
			this->icosahedronToolStripMenuItem->Name = L"icosahedronToolStripMenuItem";
			this->icosahedronToolStripMenuItem->Size = System::Drawing::Size(331, 46);
			this->icosahedronToolStripMenuItem->Text = L"Icosahedron";
			this->icosahedronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::icosahedronToolStripMenuItem_Click);
			// 
			// dodecahedronToolStripMenuItem
			// 
			this->dodecahedronToolStripMenuItem->Name = L"dodecahedronToolStripMenuItem";
			this->dodecahedronToolStripMenuItem->Size = System::Drawing::Size(331, 46);
			this->dodecahedronToolStripMenuItem->Text = L"Dodecahedron";
			this->dodecahedronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::dodecahedronToolStripMenuItem_Click);
			// 
			// sphereToolStripMenuItem
			// 
			this->sphereToolStripMenuItem->Name = L"sphereToolStripMenuItem";
			this->sphereToolStripMenuItem->Size = System::Drawing::Size(331, 46);
			this->sphereToolStripMenuItem->Text = L"Sphere";
			this->sphereToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sphereToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(112, 45);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// xScroll
			// 
			this->xScroll->LargeChange = 1;
			this->xScroll->Location = System::Drawing::Point(274, 121);
			this->xScroll->Maximum = 360;
			this->xScroll->Minimum = -360;
			this->xScroll->Name = L"xScroll";
			this->xScroll->Size = System::Drawing::Size(85, 26);
			this->xScroll->TabIndex = 2;
			this->xScroll->ValueChanged += gcnew System::EventHandler(this, &MyForm::xScroll_ValueChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->removeInvisibleLinesCheckBox);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->zScroll);
			this->panel1->Controls->Add(this->yScroll);
			this->panel1->Controls->Add(this->xScroll);
			this->panel1->Location = System::Drawing::Point(1772, 56);
			this->panel1->Margin = System::Windows::Forms::Padding(5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(420, 480);
			this->panel1->TabIndex = 3;
			// 
			// removeInvisibleLinesCheckBox
			// 
			this->removeInvisibleLinesCheckBox->AutoSize = true;
			this->removeInvisibleLinesCheckBox->Location = System::Drawing::Point(39, 407);
			this->removeInvisibleLinesCheckBox->Name = L"removeInvisibleLinesCheckBox";
			this->removeInvisibleLinesCheckBox->Size = System::Drawing::Size(336, 36);
			this->removeInvisibleLinesCheckBox->TabIndex = 5;
			this->removeInvisibleLinesCheckBox->Text = L"Remove invisible lines";
			this->removeInvisibleLinesCheckBox->UseVisualStyleBackColor = true;
			this->removeInvisibleLinesCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Blue;
			this->label4->Location = System::Drawing::Point(171, 260);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 32);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Z";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Green;
			this->label3->Location = System::Drawing::Point(171, 194);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 32);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Y";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(171, 130);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 32);
			this->label2->TabIndex = 4;
			this->label2->Text = L"X";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(171, 310);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 32);
			this->label5->TabIndex = 3;
			this->label5->Text = L"axis";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(92, 45);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(162, 32);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Move along";
			// 
			// zScroll
			// 
			this->zScroll->LargeChange = 1;
			this->zScroll->Location = System::Drawing::Point(274, 251);
			this->zScroll->Maximum = 360;
			this->zScroll->Minimum = -360;
			this->zScroll->Name = L"zScroll";
			this->zScroll->Size = System::Drawing::Size(85, 26);
			this->zScroll->TabIndex = 2;
			this->zScroll->ValueChanged += gcnew System::EventHandler(this, &MyForm::zScroll_ValueChanged);
			// 
			// yScroll
			// 
			this->yScroll->LargeChange = 1;
			this->yScroll->Location = System::Drawing::Point(274, 184);
			this->yScroll->Maximum = 360;
			this->yScroll->Minimum = -360;
			this->yScroll->Name = L"yScroll";
			this->yScroll->Size = System::Drawing::Size(85, 26);
			this->yScroll->TabIndex = 2;
			this->yScroll->ValueChanged += gcnew System::EventHandler(this, &MyForm::yScroll_ValueChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2213, 1555);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->DrawingArea);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(5);
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
			g->Clear(Color::White);
			DrawingArea->Refresh();
		}

		System::Void DrawEverything()
		{
			g->DrawLine(gcnew Pen(Color::Red), 0, CoordCenY, DrawingArea->Width, CoordCenY);
			g->DrawLine(gcnew Pen(Color::Green), CoordCenX, 0, CoordCenX, DrawingArea->Height);

			auto mx = ApplyMatrices(geom->getMatrices(GeomType));

			for each (auto poli in mx)
			{
				auto p1 = poli[0];
				auto p2 = poli[1];
				auto p3 = poli[2];

				g->DrawLine(p, CoordCenX + p1[0], CoordCenY + p1[1], CoordCenX + p2[0], CoordCenY + p2[1]);
				g->DrawLine(p, CoordCenX + p1[0], CoordCenY + p1[1], CoordCenX + p3[0], CoordCenY + p3[1]);
				g->DrawLine(p, CoordCenX + p3[0], CoordCenY + p3[1], CoordCenX + p2[0], CoordCenY + p2[1]);
			}

			DrawingArea->Refresh();
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
		if (ManipulationType == permutationType::Move)
		{
			for (size_t i = 0; i < 3; i++)
			{
				MxMove[i][(int)coord] += scroll->Value * 5;
			}
		}
		else if (ManipulationType == permutationType::Resize)
		{
			MxExtend[(int)coord][(int)coord] *= (1 + (scroll->Value / 50.0));
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
						curMultiplier = Math::Cos(scroll->Value / 90.0);
						wasFirstValue = true;
					}
					else if (!wasFirstRow && wasFirstValue)
					{
						curMultiplier = Math::Sin(scroll->Value / 90.0);
						wasFirstRow = true;
						wasFirstValue = false;
					}
					else if (wasFirstRow && !wasFirstValue)
					{
						curMultiplier = -Math::Sin(scroll->Value / 90.0);
						wasFirstValue = true;
					}
					else
					{
						curMultiplier = Math::Cos(scroll->Value / 90.0);
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
		DrawEverything();
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
			DrawEverything();
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
			DrawEverything();

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
		System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			removeInvisible = removeInvisibleLinesCheckBox->Checked;
			ClearDrawingArea();
			DrawEverything();
		}
		System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			MessageBox::Show("Author: Sergey Pavlov\ntask: Seminar 5\nYou can pick figure to show in the Figure menu.\n"+
				"Permutation method can be chosen in the Transform menu. To control it, you can use arrows on the right menu.\n"+
				"Camera mode can be switched in the View menu.");
		}
	};
}
