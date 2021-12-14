using System.Windows.Forms;

namespace LoginScreen.Models
{
    public class User
    {
        public User(string _userName, string _password)
        {
            UserName = _userName;
            Password = _password;
        }
        string _password;
        public string UserName { get; set; }
        public string Password
        {
            get
            {
                return _password;
            }
            set
            {
                if (value.Length < 4)
                {
                    System.Windows.Forms.MessageBox.Show("Password must be at least 4 characters.");
                    Application.Restart();
                }
                _password = value;
            }
        }
    }
}
