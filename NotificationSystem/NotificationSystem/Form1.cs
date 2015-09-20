using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace NotificationSystem
{
    public partial class SignInFrm : Form
    {
        bool isUserNameEntered = false;
        bool isPasswordEntered = false;

        public SignInFrm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SignUpFrm signUpFrm = new SignUpFrm();
            signUpFrm.Show();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void ForgotPwd_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {

        }

        private void txtUsername_TextChanged(object sender, EventArgs e)
        {
            isUserNameEntered = true;
            if (txtUsername.Text == "User Name" || txtUsername.Text == "")
                isUserNameEntered = false;
        }

        private void txtUsername_Enter(object sender, EventArgs e)
        {
            if (!isUserNameEntered)
                txtUsername.Text = "";
        }

        private void txtUsername_Leave(object sender, EventArgs e)
        {
            if (!isUserNameEntered)
                txtUsername.Text = "User Name";
        }

        private void txtPassword_TextChanged(object sender, EventArgs e)
        {
            isPasswordEntered = true;
            if (txtPassword.Text == "Password" || txtPassword.Text == "")
                isPasswordEntered = false;
        }

        private void txtPassword_Enter(object sender, EventArgs e)
        {
            if (!isPasswordEntered)
                txtPassword.Text = "";
            txtPassword.PasswordChar = '*';
        }

        private void txtPassword_Leave(object sender, EventArgs e)
        {
            if (!isPasswordEntered)
            {
                txtPassword.Text = "Password";
                txtPassword.PasswordChar = '\0';
            }
        }

        private void btnSignIn_Click(object sender, EventArgs e)
        {
            if (!Validate())
            {
                MessageBox.Show("Validation error");
                    return;
            }

            if (!Connection.Instance.isAuthendicate(txtUsername.Text, txtPassword.Text))
                return;
            Global.username = txtUsername.Text;
            this.WindowState = FormWindowState.Minimized;
            Global.mainfrm.Show();            
        }

        private bool Validate()
        {
            if (txtUsername.Text == "User Name" || txtUsername.Text == "")
                return false;

            if (txtPassword.Text == "Password" || txtPassword.Text == "")
                return false;

            return true;
        }
    }
}
