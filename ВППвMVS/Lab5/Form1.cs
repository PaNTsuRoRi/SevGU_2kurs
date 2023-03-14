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

namespace Lab5
{
    public partial class Form1 : Form
    {
        Button myButton = new Button();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            myButton.BackColor = Color.LightGray;
            myButton.ForeColor = Color.Black;
            myButton.Location = new Point(240, 376);
            myButton.Size = new Size(224, 31);
            myButton.Text = "Очистить результаты";
            myButton.Font = new System.Drawing.Font("Times New Roman", 14.25F);
            myButton.Click += new System.EventHandler(MyButton_Click);
            myButton.Visible = false;
            this.Controls.Add(myButton);
        }

        private void MyButton_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            myButton.Visible = false;
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
            if (listBox1.Items.Count != 0) myButton.Visible = true;
        }

        private void ListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
