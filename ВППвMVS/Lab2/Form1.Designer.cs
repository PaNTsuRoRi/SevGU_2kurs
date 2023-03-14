using System;

namespace Lab2
{
    partial class Form
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.but1 = new System.Windows.Forms.Button();
            this.but2 = new System.Windows.Forms.Button();
            this.but3 = new System.Windows.Forms.Button();
            this.but4 = new System.Windows.Forms.Button();
            this.but5 = new System.Windows.Forms.Button();
            this.butStart = new System.Windows.Forms.Button();
            this.lab1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // but1
            // 
            this.but1.Location = new System.Drawing.Point(50, 320);
            this.but1.Name = "but1";
            this.but1.Size = new System.Drawing.Size(100, 30);
            this.but1.TabIndex = 0;
            this.but1.Text = "1";
            this.but1.UseVisualStyleBackColor = true;
            this.but1.Click += new System.EventHandler(this.but1_Click);
            // 
            // but2
            // 
            this.but2.Location = new System.Drawing.Point(200, 320);
            this.but2.Name = "but2";
            this.but2.Size = new System.Drawing.Size(100, 30);
            this.but2.TabIndex = 1;
            this.but2.Text = "2";
            this.but2.UseVisualStyleBackColor = true;
            this.but2.Click += new System.EventHandler(this.but2_Click);
            // 
            // but3
            // 
            this.but3.Location = new System.Drawing.Point(350, 320);
            this.but3.Name = "but3";
            this.but3.Size = new System.Drawing.Size(100, 30);
            this.but3.TabIndex = 2;
            this.but3.Text = "3";
            this.but3.UseVisualStyleBackColor = true;
            this.but3.Click += new System.EventHandler(this.but3_Click);
            // 
            // but4
            // 
            this.but4.Location = new System.Drawing.Point(500, 320);
            this.but4.Name = "but4";
            this.but4.Size = new System.Drawing.Size(100, 30);
            this.but4.TabIndex = 3;
            this.but4.Text = "4";
            this.but4.UseVisualStyleBackColor = true;
            this.but4.Click += new System.EventHandler(this.but4_Click);
            // 
            // but5
            // 
            this.but5.Location = new System.Drawing.Point(650, 320);
            this.but5.Name = "but5";
            this.but5.Size = new System.Drawing.Size(100, 30);
            this.but5.TabIndex = 4;
            this.but5.Text = "5";
            this.but5.UseVisualStyleBackColor = true;
            this.but5.Click += new System.EventHandler(this.but5_Click);
            // 
            // butStart
            // 
            this.butStart.Location = new System.Drawing.Point(350, 360);
            this.butStart.Name = "butStart";
            this.butStart.Size = new System.Drawing.Size(100, 30);
            this.butStart.TabIndex = 5;
            this.butStart.Text = "Start";
            this.butStart.UseVisualStyleBackColor = true;
            this.butStart.Click += new System.EventHandler(this.butStart_Click);
            // 
            // lab1
            // 
            this.lab1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.lab1.Font = new System.Drawing.Font("Times New Roman", 69.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.lab1.ForeColor = System.Drawing.Color.Black;
            this.lab1.Location = new System.Drawing.Point(325, 100);
            this.lab1.Margin = new System.Windows.Forms.Padding(0);
            this.lab1.Name = "lab1";
            this.lab1.Size = new System.Drawing.Size(150, 150);
            this.lab1.TabIndex = 6;
            this.lab1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 415);
            this.Controls.Add(this.lab1);
            this.Controls.Add(this.butStart);
            this.Controls.Add(this.but5);
            this.Controls.Add(this.but4);
            this.Controls.Add(this.but3);
            this.Controls.Add(this.but2);
            this.Controls.Add(this.but1);
            this.Name = "Form";
            this.Text = "Form";
            this.Load += new System.EventHandler(this.Form_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button but1;
        private System.Windows.Forms.Button but2;
        private System.Windows.Forms.Button but3;
        private System.Windows.Forms.Button but4;
        private System.Windows.Forms.Button but5;
        private System.Windows.Forms.Button butStart;
        private System.Windows.Forms.Label lab1;
    }
}