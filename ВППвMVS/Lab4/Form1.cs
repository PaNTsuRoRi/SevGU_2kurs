using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Math;

namespace Lab4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {
            int x, i;
            if ((textBox1.Text == "") || (textBox2.Text == ""))
            {
                label4.Text = "Введите значения!";
            }
            else
            {
                try
                {
                    x = int.Parse(textBox1.Text);
                    i = int.Parse(textBox2.Text);
                    label4.Text = "";
                    Decision(x, i);
                }
                catch
                {
                    label4.Text = "Значения неверного типа";
                }
            }
        }

        private void Decision(int x, int i)
        {
            double a = 0;
            double f = 0;
            if (radioButton1.Checked)
            {
                f = Sinh(x);
            }
            else if (radioButton2.Checked)
            {
                f = Pow(x, 2);
            }
            else if (radioButton3.Checked)
            {
                f = Exp(x);
            }
            else label4.Text = "Выберите функцию";
            if ((x > 0) && (i%2 == 1))
            {
                a = i * Sqrt(f);
            }
            else if (x<0 && (i%2 == 0))
            {
                a = i / 2 * Sqrt(Abs(f));
            }
            else
            {
                a = Sqrt(Abs(i * f));
            }
            listBox1.Items.Add(a);
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }
    }
}
