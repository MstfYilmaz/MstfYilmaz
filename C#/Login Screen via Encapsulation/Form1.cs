using LoginScreen.Models;
using System;
using System.Windows.Forms;


namespace LoginScreen
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            User user = new User(txtUserName.Text, txtPassword.Text);
            Form2 frm = new Form2(user);
            this.Hide();
            frm.Show();
        }
    }
}
