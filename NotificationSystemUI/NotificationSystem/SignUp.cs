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
    public partial class SignUpFrm : Form
    {
        bool isUserNameEntered = false;
        bool isEmailEntered = false;
        bool isMobileEntered = false;
        bool isPasswordEntered = false;
        bool isRePasswordEntered = false;

        public SignUpFrm()
        {
            InitializeComponent();
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

        private void txtUsername_TextChanged(object sender, EventArgs e)
        {
            isUserNameEntered = true;
            if (txtUsername.Text == "User Name" || txtUsername.Text == "")
                isUserNameEntered = false;
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

        private void txtRePassword_TextChanged(object sender, EventArgs e)
        {
            isRePasswordEntered = true;
            if (txtRePassword.Text == "Retype - Password" || txtRePassword.Text == "")
                isRePasswordEntered = false;
        }

        private void txtRePassword_Enter(object sender, EventArgs e)
        {
            if (!isRePasswordEntered)
                txtRePassword.Text = "";
            txtRePassword.PasswordChar = '*';
        }

        private void txtRePassword_Leave(object sender, EventArgs e)
        {
            if (!isRePasswordEntered)
            {
                txtRePassword.Text = "Retype - Password";
                txtRePassword.PasswordChar = '\0';
            }
        }

        private void txtEmail_TextChanged(object sender, EventArgs e)
        {
            isEmailEntered = true;
            if (txtEmail.Text == "e-mail Id" || txtEmail.Text == "")
                isEmailEntered = false;
        }

        private void txtEmail_Enter(object sender, EventArgs e)
        {
            if (!isEmailEntered)
                txtEmail.Text = "";
        }

        private void txtEmail_Leave(object sender, EventArgs e)
        {
            if (!isEmailEntered)
                txtEmail.Text = "e-mail Id";
        }

        private void txtMobile_TextChanged(object sender, EventArgs e)
        {
            isMobileEntered = true;
            if (txtMobile.Text == "Mobile Number" || txtMobile.Text == "")
                isMobileEntered = false;
        }

        private void txtMobile_Enter(object sender, EventArgs e)
        {
            if (!isMobileEntered)
                txtMobile.Text = "";
        }

        private void txtMobile_Leave(object sender, EventArgs e)
        {
            if (!isMobileEntered)
                txtMobile.Text = "Mobile Number";
        }


    }
}
