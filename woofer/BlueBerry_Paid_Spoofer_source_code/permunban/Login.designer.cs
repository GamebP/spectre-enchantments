namespace Code7777
{
    partial class Login
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.siticoneDragControl1 = new Siticone.UI.WinForms.SiticoneDragControl(this.components);
            this.siticoneElipse1 = new Siticone.UI.WinForms.SiticoneElipse(this.components);
            this.siticoneShadowForm1 = new Siticone.UI.WinForms.SiticoneShadowForm(this.components);
            this.username = new Guna.UI2.WinForms.Guna2TextBox();
            this.password = new Guna.UI2.WinForms.Guna2TextBox();
            this.loginbttn = new Guna.UI2.WinForms.Guna2Button();
            this.gunaCirclePictureBox1 = new Guna.UI.WinForms.GunaCirclePictureBox();
            this.guna2Button1 = new Guna.UI2.WinForms.Guna2Button();
            ((System.ComponentModel.ISupportInitialize)(this.gunaCirclePictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // siticoneDragControl1
            // 
            this.siticoneDragControl1.TargetControl = null;
            // 
            // siticoneElipse1
            // 
            this.siticoneElipse1.TargetControl = this;
            // 
            // username
            // 
            this.username.Animated = true;
            this.username.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(13)))), ((int)(((byte)(13)))));
            this.username.BorderRadius = 3;
            this.username.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.username.DefaultText = "";
            this.username.DisabledState.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(208)))), ((int)(((byte)(208)))), ((int)(((byte)(208)))));
            this.username.DisabledState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(226)))));
            this.username.DisabledState.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(138)))), ((int)(((byte)(138)))), ((int)(((byte)(138)))));
            this.username.DisabledState.PlaceholderForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(138)))), ((int)(((byte)(138)))), ((int)(((byte)(138)))));
            this.username.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(13)))), ((int)(((byte)(13)))));
            this.username.FocusedState.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.username.FocusedState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.username.Font = new System.Drawing.Font("Segoe UI", 9F);
            this.username.ForeColor = System.Drawing.Color.White;
            this.username.HoverState.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.username.HoverState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.username.Location = new System.Drawing.Point(12, 161);
            this.username.Name = "username";
            this.username.PasswordChar = '\0';
            this.username.PlaceholderText = "Username";
            this.username.SelectedText = "";
            this.username.Size = new System.Drawing.Size(252, 28);
            this.username.TabIndex = 2;
            // 
            // password
            // 
            this.password.Animated = true;
            this.password.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(13)))), ((int)(((byte)(13)))));
            this.password.BorderRadius = 3;
            this.password.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.password.DefaultText = "";
            this.password.DisabledState.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(208)))), ((int)(((byte)(208)))), ((int)(((byte)(208)))));
            this.password.DisabledState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(226)))));
            this.password.DisabledState.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(138)))), ((int)(((byte)(138)))), ((int)(((byte)(138)))));
            this.password.DisabledState.PlaceholderForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(138)))), ((int)(((byte)(138)))), ((int)(((byte)(138)))));
            this.password.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(13)))), ((int)(((byte)(13)))));
            this.password.FocusedState.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.password.FocusedState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.password.Font = new System.Drawing.Font("Segoe UI", 9F);
            this.password.ForeColor = System.Drawing.Color.White;
            this.password.HoverState.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.password.HoverState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.password.Location = new System.Drawing.Point(12, 195);
            this.password.Name = "password";
            this.password.PasswordChar = '•';
            this.password.PlaceholderText = "Password";
            this.password.SelectedText = "";
            this.password.Size = new System.Drawing.Size(252, 28);
            this.password.TabIndex = 3;
            this.password.TextChanged += new System.EventHandler(this.password_TextChanged);
            // 
            // loginbttn
            // 
            this.loginbttn.Animated = true;
            this.loginbttn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(10)))), ((int)(((byte)(10)))), ((int)(((byte)(10)))));
            this.loginbttn.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(13)))), ((int)(((byte)(13)))));
            this.loginbttn.BorderRadius = 3;
            this.loginbttn.BorderThickness = 1;
            this.loginbttn.CheckedState.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.loginbttn.CheckedState.CustomBorderColor = System.Drawing.Color.RoyalBlue;
            this.loginbttn.CheckedState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.loginbttn.CheckedState.ForeColor = System.Drawing.Color.White;
            this.loginbttn.CustomBorderThickness = new System.Windows.Forms.Padding(0, 0, 0, 1);
            this.loginbttn.DisabledState.BorderColor = System.Drawing.Color.DarkGray;
            this.loginbttn.DisabledState.CustomBorderColor = System.Drawing.Color.DarkGray;
            this.loginbttn.DisabledState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(169)))), ((int)(((byte)(169)))), ((int)(((byte)(169)))));
            this.loginbttn.DisabledState.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(141)))), ((int)(((byte)(141)))), ((int)(((byte)(141)))));
            this.loginbttn.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(13)))), ((int)(((byte)(13)))));
            this.loginbttn.Font = new System.Drawing.Font("Segoe UI Semilight", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.loginbttn.ForeColor = System.Drawing.Color.Gray;
            this.loginbttn.HoverState.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(15)))), ((int)(((byte)(15)))), ((int)(((byte)(15)))));
            this.loginbttn.HoverState.CustomBorderColor = System.Drawing.Color.RoyalBlue;
            this.loginbttn.HoverState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(15)))), ((int)(((byte)(15)))), ((int)(((byte)(15)))));
            this.loginbttn.HoverState.ForeColor = System.Drawing.Color.White;
            this.loginbttn.Location = new System.Drawing.Point(12, 231);
            this.loginbttn.Name = "loginbttn";
            this.loginbttn.PressedDepth = 15;
            this.loginbttn.Size = new System.Drawing.Size(252, 28);
            this.loginbttn.TabIndex = 4;
            this.loginbttn.Text = "LOGIN";
            this.loginbttn.TextOffset = new System.Drawing.Point(0, -1);
            this.loginbttn.Click += new System.EventHandler(this.guna2Button2_Click);
            // 
            // gunaCirclePictureBox1
            // 
            this.gunaCirclePictureBox1.BaseColor = System.Drawing.Color.White;
            this.gunaCirclePictureBox1.Image = global::permunban.Properties.Resources.image;
            this.gunaCirclePictureBox1.Location = new System.Drawing.Point(69, 12);
            this.gunaCirclePictureBox1.Name = "gunaCirclePictureBox1";
            this.gunaCirclePictureBox1.Size = new System.Drawing.Size(134, 132);
            this.gunaCirclePictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.gunaCirclePictureBox1.TabIndex = 1;
            this.gunaCirclePictureBox1.TabStop = false;
            this.gunaCirclePictureBox1.UseTransfarantBackground = false;
            this.gunaCirclePictureBox1.Click += new System.EventHandler(this.gunaCirclePictureBox1_Click);
            // 
            // guna2Button1
            // 
            this.guna2Button1.Animated = true;
            this.guna2Button1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(10)))), ((int)(((byte)(10)))), ((int)(((byte)(10)))));
            this.guna2Button1.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(13)))), ((int)(((byte)(13)))));
            this.guna2Button1.BorderRadius = 3;
            this.guna2Button1.BorderThickness = 1;
            this.guna2Button1.CheckedState.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.guna2Button1.CheckedState.CustomBorderColor = System.Drawing.Color.RoyalBlue;
            this.guna2Button1.CheckedState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(16)))), ((int)(((byte)(16)))));
            this.guna2Button1.CheckedState.ForeColor = System.Drawing.Color.White;
            this.guna2Button1.CustomBorderThickness = new System.Windows.Forms.Padding(0, 0, 0, 1);
            this.guna2Button1.DisabledState.BorderColor = System.Drawing.Color.DarkGray;
            this.guna2Button1.DisabledState.CustomBorderColor = System.Drawing.Color.DarkGray;
            this.guna2Button1.DisabledState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(169)))), ((int)(((byte)(169)))), ((int)(((byte)(169)))));
            this.guna2Button1.DisabledState.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(141)))), ((int)(((byte)(141)))), ((int)(((byte)(141)))));
            this.guna2Button1.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(13)))), ((int)(((byte)(13)))));
            this.guna2Button1.Font = new System.Drawing.Font("Segoe UI Semilight", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.guna2Button1.ForeColor = System.Drawing.Color.Gray;
            this.guna2Button1.HoverState.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(15)))), ((int)(((byte)(15)))), ((int)(((byte)(15)))));
            this.guna2Button1.HoverState.CustomBorderColor = System.Drawing.Color.RoyalBlue;
            this.guna2Button1.HoverState.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(15)))), ((int)(((byte)(15)))), ((int)(((byte)(15)))));
            this.guna2Button1.HoverState.ForeColor = System.Drawing.Color.White;
            this.guna2Button1.Location = new System.Drawing.Point(12, 265);
            this.guna2Button1.Name = "guna2Button1";
            this.guna2Button1.PressedDepth = 15;
            this.guna2Button1.Size = new System.Drawing.Size(252, 28);
            this.guna2Button1.TabIndex = 5;
            this.guna2Button1.Text = "REGISTER";
            this.guna2Button1.TextOffset = new System.Drawing.Point(0, -1);
            this.guna2Button1.Click += new System.EventHandler(this.guna2Button1_Click);
            // 
            // Login
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(10)))), ((int)(((byte)(10)))), ((int)(((byte)(10)))));
            this.ClientSize = new System.Drawing.Size(276, 373);
            this.Controls.Add(this.guna2Button1);
            this.Controls.Add(this.loginbttn);
            this.Controls.Add(this.password);
            this.Controls.Add(this.username);
            this.Controls.Add(this.gunaCirclePictureBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Login";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Login";
            this.TopMost = true;
            this.Load += new System.EventHandler(this.Login_Load);
            ((System.ComponentModel.ISupportInitialize)(this.gunaCirclePictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private Guna.UI.WinForms.GunaCirclePictureBox gunaCirclePictureBox1;
        private Siticone.UI.WinForms.SiticoneDragControl siticoneDragControl1;
        private Siticone.UI.WinForms.SiticoneElipse siticoneElipse1;
        private Siticone.UI.WinForms.SiticoneShadowForm siticoneShadowForm1;
        private Guna.UI2.WinForms.Guna2TextBox username;
        private Guna.UI2.WinForms.Guna2TextBox password;
        private Guna.UI2.WinForms.Guna2Button loginbttn;
        private Guna.UI2.WinForms.Guna2Button guna2Button1;
    }
}