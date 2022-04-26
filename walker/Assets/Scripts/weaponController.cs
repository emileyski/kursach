using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class weaponController : MonoBehaviour
{
    public int damageCount;
    public string weapon_type;
    private Joystick joystick;
    private SpriteRenderer weapon_sprite;
    private float angle;
    private Animator animator;
    private void Start()
    {
        animator = GetComponent<Animator>();
        joystick = GameObject.Find("Fixed Joystick").GetComponent<Joystick>();
        weapon_sprite = GetComponentInChildren<SpriteRenderer>();
    }
    private void Update()
    {
        if (weapon_type != "bow")
            RotateWeapon();
    }
    void RotateWeapon()
    {
        if (joystick.Horizontal == 0 && joystick.Vertical == 0) return;
        angle = Mathf.Atan2(joystick.Vertical, joystick.Horizontal) * Mathf.Rad2Deg;
        var lookRotation = Quaternion.Euler(angle * Vector3.forward);
        transform.rotation = lookRotation;
        weapon_sprite.flipX = (joystick.Horizontal > 0) ? false : true;
    }
    public void attack(bool isAttack)
    {
        if (isAttack)
        {
            GetComponentInChildren<BoxCollider2D>().enabled = true;
            animator.SetBool("Attack", true);
        }
        else
        {
            GetComponentInChildren<BoxCollider2D>().enabled = false;
            animator.SetBool("Attack", false);
        }
    }
}
