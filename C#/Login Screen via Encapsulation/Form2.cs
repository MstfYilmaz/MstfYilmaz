using LoginScreen.Models;
using System;
using System.Windows.Forms;

namespace LoginScreen
{
    public partial class Form2 : Form
    {
        public Form2(User user)
        {
            InitializeComponent();
            UserInformation = user;
        }
        User UserInformation;
        private void button1_Click(object sender, EventArgs e)
        {
            if (txtUserName.Text == UserInformation.UserName && txtPassword.Text == UserInformation.Password)
            {
                Form3 frm = new Form3();
                this.Hide();
                frm.Show();

            }
            else
            {
                MessageBox.Show("Username or password is incorrect.");
            }

        }
    }
}
