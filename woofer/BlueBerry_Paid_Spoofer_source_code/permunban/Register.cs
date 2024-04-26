using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.StartPanel;
using KeyAuth;
using Code7777;
using permunban;

namespace Code7777.Forms
{
    public partial class Register : Form
    {
        public static api KeyAuthApp = new api(
    name: "Loader",
    ownerid: "lQDfKzMKbn",
    secret: "27628f5fcbb27653282e433d3828b61c15c465c0f26f1e572ec77b547e2052a2",
    version: "1.0"
);

        public Register()
        {
            InitializeComponent();
        }
       

        private void save()
        {
            File.WriteAllText(string.Concat(Path.GetPathRoot(Environment.SystemDirectory), "\\code7777.txt"), string.Concat(this.username.Text, "\n", this.password.Text));
        }
        private void Register_Load(object sender, EventArgs e)
        {
            KeyAuthApp.init(); 
            base.TopMost = true;
            siticoneShadowForm1.SetShadowForm(this);
            siticoneDragControl1.SetDrag(this);
        }

        private void guna2Button1_Click(object sender, EventArgs e)
        {
            Login rar = new Login();
            rar.Show();
            this.Hide();
        }

        private void guna2Button2_Click(object sender, EventArgs e)
        {
            KeyAuthApp.register(username.Text, password.Text, key.Text);
            if(KeyAuthApp.response.success)
            {
                guna2Button2.Text = "Creating Account...";
                MessageBox.Show("Succesfully Registerd in!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                main aa = new main();
                save();
                Task.Delay(6900);
                KeyAuthApp.Checkinit();
                KeyAuthApp.check();
                Task.Delay(6900);
                aa.Show();
                this.Hide();
            }
            else
            {
                string clear = "";
                username.Text = clear;
                password.Text = clear;
                MessageBox.Show("Invaild Username/Password/License", "Invaild", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void gunaCirclePictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void password_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
