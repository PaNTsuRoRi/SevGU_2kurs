using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace lab6
{
    public partial class Form2 : Form
    {
        Form1 form1;

        public Form2()
        {
            InitializeComponent();
        }

        public Form2(Form1 f)
        {
            InitializeComponent();
            form1 = f;
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {
            if (checkData())
                form1.label3.Text = Convert.ToString(Math.Pow(double.Parse(form1.textBox1.Text), double.Parse(form1.textBox2.Text)));
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            if (checkData())
                form1.label3.Text = Convert.ToString(Math.Sqrt(double.Parse(form1.textBox1.Text)));
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            if (checkData())
                form1.label3.Text = Convert.ToString(Math.Sin(double.Parse(form1.textBox1.Text)));
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            if (checkData())
                form1.label3.Text = Convert.ToString(Math.Cos(double.Parse(form1.textBox1.Text)));
        }

        private void Button5_Click(object sender, EventArgs e)
        {
            if (checkData())
                form1.label3.Text = Convert.ToString(Math.Tan(double.Parse(form1.textBox1.Text)));
        }

        private void Button6_Click(object sender, EventArgs e)
        {
            if(checkData())
                form1.label3.Text = Convert.ToString(1/Math.Tan(double.Parse(form1.textBox1.Text)));
        }

        private bool checkData()
        {
            double x = 0, y = 0;
            if (form1.textBox1.Text == "")
            {
                form1.label3.Text = "Введите значение!";
                return false;
            }
            else
            {
                try
                {
                    x = double.Parse(form1.textBox1.Text);
                    return true;
                }
                catch
                {
                    form1.label3.Text = "Значение неверного типа";
                    return false;
                }
            }
        }
    }
}
