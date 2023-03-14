using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab6
{
    public partial class Form1 : Form
    {
        ToolStripLabel dateLabel;
        ToolStripLabel timeLabel;
        ToolStripLabel infoLabel;
        Timer timer;
        Form2 newForm = new Form2();

        public Form1()
        {
            InitializeComponent();
            //
            //Menu
            //
            ToolStripMenuItem info = new ToolStripMenuItem("О программе");
            info.Click += info_Click;
            menuStrip1.Items.Add(info);
            //
            //Status
            //
            infoLabel = new ToolStripLabel();
            infoLabel.Text = "Текущие дата и время:";
            dateLabel = new ToolStripLabel();
            timeLabel = new ToolStripLabel();
            statusStrip1.Items.Add(infoLabel);
            statusStrip1.Items.Add(dateLabel);
            statusStrip1.Items.Add(timeLabel);
            timer = new Timer() { Interval = 1000 };
            timer.Tick += timer_Tick;
            timer.Start();
            var f = new Form2(this);
            f.Show();
        }

        void timer_Tick(object sender, EventArgs e)
        {
            dateLabel.Text = DateTime.Now.ToLongDateString();
            timeLabel.Text = DateTime.Now.ToLongTimeString();
        }

        private void info_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Калькулятор c обычними операциями (сложения, вычитания, деления и умножения),\n" +
                "и дополнительными функциями (возведения в степень, корень квадратный, sin, cos, tg, ctg).");
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void Button1_Click(object sender, EventArgs e)
        {
            if (checkData())
                label3.Text = Convert.ToString(double.Parse(textBox1.Text) + double.Parse(textBox2.Text));
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            if (checkData())
                label3.Text = Convert.ToString(double.Parse(textBox1.Text) - double.Parse(textBox2.Text));
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            if (checkData())
                label3.Text = Convert.ToString(double.Parse(textBox1.Text) / double.Parse(textBox2.Text));
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            if(checkData())
                label3.Text = Convert.ToString(double.Parse(textBox1.Text) * double.Parse(textBox2.Text));
        }
        private bool checkData()
        {
            double x = 0, y = 0;
            if ((textBox1.Text == "") || (textBox2.Text == ""))
            {
                label3.Text = "Введите значения!";
                return false;
            }
            else 
            {
                try
            
                {
                    x = double.Parse(textBox1.Text);
                    y = double.Parse(textBox2.Text);
                    return true;
                }
                catch
                {
                    label3.Text = "Значения неверного типа";
                    return false;
                }
            }
        }
    }
}
