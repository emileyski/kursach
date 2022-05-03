using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class melee_unit : base_unit
{
    private bool x = false;// служебная переменная для того, чтобы узнать на перезарядке(кулдауне) ли наша атака
    protected override void moveing()
    {
        base.moveing();
        if (atackRange > Vector3.Distance(transform.position, player.transform.position) && !animator.GetBool("IsAttacking") && x == false)
            StartCoroutine("Atack", true);
    }
    protected override IEnumerator Atack(bool toAtack)
    {
        animator.SetBool("IsAttacking", true);
        x = true;
        Weapon.GetComponent<BoxCollider2D>().enabled = true;
        yield return new WaitForSeconds(0.5f);//проигрываем анимацию(бъем)
        animator.SetBool("IsAttacking", false);
        Weapon.GetComponent<BoxCollider2D>().enabled = false;
        yield return new WaitForSeconds(cooldown);//откатываемся
        x = false;
    }
}
