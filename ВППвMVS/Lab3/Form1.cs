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

namespace Lab3
{
    public partial class Form : System.Windows.Forms.Form
    {
        public Form()
        {
            InitializeComponent();
        }

        private void Form_Load(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {
            int x=0, y=0, z=0;
            double a;
            if ((textBox1.Text == "") || (textBox2.Text == "") || (textBox3.Text == ""))
            {
                label5.ForeColor = Color.Red;
                label5.Text = "ВВЕДИТЕ ЗНАЧЕНИЯ";
            }
            else
            {
                try
                {
                    x = int.Parse(textBox1.Text);
                    y = int.Parse(textBox2.Text);
                    z = int.Parse(textBox3.Text);
                    a = (Log(Pow(y, (-Sqrt(Abs(x)))))) * (x - y / 2) + Pow(Sin(Atan(z)), 2);
                    label5.ForeColor = Color.Black;
                    label5.Text = Convert.ToString(a);
                }
                catch
                {
                    label5.ForeColor = Color.Red;
                    label5.Text = "ЗНАЧЕНИЯ НЕВЕРНОГО ТИПА";
                }
            }
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            label5.Text = "";
        }
    }
}
