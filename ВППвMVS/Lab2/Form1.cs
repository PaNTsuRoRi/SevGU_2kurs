using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2
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

        private void but1_Click(object sender, EventArgs e)
        {
            lab1.Text = but1.Text;
        }

        private void but2_Click(object sender, EventArgs e)
        {
            lab1.Text = but2.Text;
        }

        private void but3_Click(object sender, EventArgs e)
        {
            lab1.Text = but3.Text;
        }

        private void but4_Click(object sender, EventArgs e)
        {
            lab1.Text = but4.Text;
        }

        private void but5_Click(object sender, EventArgs e)
        {
            lab1.Text = but5.Text;
        }

        private void butStart_Click(object sender, EventArgs e)
        {
            lab1.Text = "";
        }
    }
}
